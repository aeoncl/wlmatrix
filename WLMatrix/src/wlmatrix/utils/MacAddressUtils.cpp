#pragma once
#include "MacAddressUtils.h"
#include <stdio.h>
#include <Windows.h>
#include <Iphlpapi.h>
#include <Assert.h>
#include <iomanip>

#pragma comment(lib, "iphlpapi.lib")

/** Source: https://stackoverflow.com/a/13688254 **/
std::optional<std::string> MacAddressUtils::getMacAddress()
{
    std::string macAddr;
    PIP_ADAPTER_INFO AdapterInfo;
    DWORD dwBufLen = sizeof(IP_ADAPTER_INFO);

    AdapterInfo = (IP_ADAPTER_INFO *)malloc(sizeof(IP_ADAPTER_INFO));
    if (AdapterInfo == NULL)
    {
        return std::nullopt;
    }

    // Make an initial call to GetAdaptersInfo to get the necessary size into the dwBufLen variable
    if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == ERROR_BUFFER_OVERFLOW)
    {
        free(AdapterInfo);
        AdapterInfo = (IP_ADAPTER_INFO *)malloc(dwBufLen);
        if (AdapterInfo == NULL)
        {
            return std::nullopt;
        }
    }

    if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == NO_ERROR)
    {
        // Contains pointer to first adapter info
        PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;
        for (int i = 0; i < pAdapterInfo->AddressLength; i++)
        {
            macAddr += std::to_string((int)pAdapterInfo->Address[i]);
        }
    }
    free(AdapterInfo);
    return std::make_optional(macAddr);
}