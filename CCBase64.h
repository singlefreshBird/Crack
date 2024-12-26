#pragma once
// ÔÓÏîÀà
#include <string>
#include <openssl\evp.h>

#pragma comment(lib,"libssl.lib")
#pragma comment(lib,"libcrypto.lib")
#pragma comment(lib,"libcrypto.lib")

const std::string b64_tbl = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
const uint8_t db64_tbl[] = { 
             0,0,0,0,0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,62,0,0,0,
             63,52,53,54,55,56,57,58,
             59,60,61,0,0,0,0,0,0,0,0,
             1,2,3,4,5,6,7,8,9,10,11,12,
             13,14,15,16,17,18,19,20,21,
             22,23,24,25,0,0,0,0,0,0,26,
             27,28,29,30,31,32,33,34,35,
             36,37,38,39,40,41,42,43,44,
             45,46,47,48,49,50,51 };

class CCBase64
{
private:
    CCBase64();
public:
    static auto b64_encode(const std::string& src)->std::string;
    static auto b64_encode(const BYTE* src, const size_t len)->std::string;
    static auto b64_decode(std::string& str)->std::string;
};

