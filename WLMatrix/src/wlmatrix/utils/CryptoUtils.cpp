#include "CryptoUtils.h"
#include "boost/algorithm/hex.hpp"

#include "boost/uuid/detail/md5.hpp"

#include <boost/uuid/random_generator.hpp>
#include "StringUtils.h"

using boost::uuids::detail::md5;

    std::string CryptoUtils::hashMD5(std::string value){
        md5 hash;
        md5::digest_type digest;

        hash.process_bytes(value.data(), value.size());
        hash.get_digest(digest);

        const auto charDigest = reinterpret_cast<const char *>(&digest);
        std::string result;
        boost::algorithm::hex_lower(charDigest, charDigest + sizeof(md5::digest_type), std::back_inserter(result));
        return result;
    };

    std::string CryptoUtils::getMD5uuid(std::string value){
        auto md5 = CryptoUtils::hashMD5(value);
        std::string uuid = md5.substr(0,8) + "-" + md5.substr(8,4) + "-" + md5.substr(12, 4) + "-" + md5.substr(16, 4)+ "-" + md5.substr(20, 12);
        return uuid;
    }

    std::string CryptoUtils::getUuidAsDecimal(std::string uuid) {
        std::string trimmed = uuid.substr(19,4) + uuid.substr(24,12);
        std::string test = boost::algorithm::hex(trimmed);
        return test;
    }

    std::string CryptoUtils::getRandomUuid() {
        boost::uuids::random_generator gen;
        boost::uuids::uuid randomUuid = gen();
        std::string randomUuidAsStr = std::string(randomUuid.begin(), randomUuid.end());
        std::string randomUuidAsHexStr = boost::algorithm::hex_lower(randomUuidAsStr);
        std::string uuid = randomUuidAsHexStr.substr(0,8) + "-" + randomUuidAsHexStr.substr(8,4) + "-" + randomUuidAsHexStr.substr(12, 4) + "-" + randomUuidAsHexStr.substr(16, 4)+ "-" + randomUuidAsHexStr.substr(20, 12);
        return uuid;
    }



