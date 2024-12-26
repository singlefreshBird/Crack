#include "pch.h"
#include "CCBase64.h"

CCBase64::CCBase64() {}

auto CCBase64::b64_encode(const std::string& src)->std::string
{
    return b64_encode((BYTE*)&src[0], src.size());
}

auto CCBase64::b64_encode(const BYTE* src, const size_t len)->std::string
{
    size_t fixLen = (len + 2) / 3 * 4;
    std::string result;
    result.resize(fixLen);
    
    EVP_EncodeBlock((unsigned char*)result.data(), src, len);

    return result;
}

auto CCBase64::b64_decode(std::string& str)->std::string
{
    if (str.size() % 4) return "";

    size_t fixLen = str.size() / 4 * 3;

    std::string result;
    result.resize(fixLen);

    if (EVP_DecodeBlock((unsigned char*)result.data(), (const unsigned char*)str.c_str(), str.size()) != -1)
        return result;
    else
        return "";
}
