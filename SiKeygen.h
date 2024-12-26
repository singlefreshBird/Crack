#pragma once
// Source Insight4.0注册机主类
#include <string>
#include <memory>
#include <windows.h>
#include <random>
#include <time.h>

struct deleter
{
    using pointer = HANDLE;
    void operator()(HANDLE h)
    {
        if (h) ::CloseHandle(h);
    }
};

using unique_handle_t = std::unique_ptr<HANDLE, deleter>;

class SiKeygen
{
private:
    // 创建多层级目录
    auto makeDirectory(const std::string& path)->bool;
    auto genNocontinuousNumber()->std::string;
    auto transform(const std::string& str)->std::string;
    auto randomChoice(const char* table, int count)->std::string;
    // 生成ActId
    auto genActId()->std::string;
    // 生成序列号
    auto genSerial()->std::string;
    auto genSignature(const std::string& src)->std::string;
    auto encode(const std::string& src, size_t size, BYTE** encData, size_t round, size_t pos)->bool;
    // 获取计算机名
    auto getComputerName()->std::string;
    // 获取当前登录用户
    auto getLoginUser()->std::string;
    // 获取系统盘序列号
    auto getSystemDiskSerial()->std::string;
public:
    auto genLicenseFile(const std::string& name, const std::string& company, const std::string& email)->bool;
    auto importLicenseFile()->bool;
};

