#include "CryptoUtils.h"
#include "boost/algorithm/hex.hpp"
#include "boost/uuid/detail/md5.hpp"

using boost::uuids::detail::md5;

    std::string CryptoUtils::hashMD5(std::string value){
        md5 hash;
        md5::digest_type digest;

        hash.process_bytes(value.data(), value.size());
        hash.get_digest(digest);

        const auto charDigest = reinterpret_cast<const char *>(&digest);
        std::string result;
        boost::algorithm::hex(charDigest, charDigest + sizeof(md5::digest_type), std::back_inserter(result));
        return result;
    };

    std::string CryptoUtils::getMD5uuid(std::string value){
        auto md5 = CryptoUtils::hashMD5(value);
        std::string uuid = md5.substr(0,8) + "-" + md5.substr(8,4) + "-" + md5.substr(12, 4) + "-" + md5.substr(16, 4)+ "-" + md5.substr(20, 12);
        return uuid;
    }


