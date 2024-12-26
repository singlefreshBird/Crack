#pragma once
// Source Insight4.0ע�������
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
    // ������㼶Ŀ¼
    auto makeDirectory(const std::string& path)->bool;
    auto genNocontinuousNumber()->std::string;
    auto transform(const std::string& str)->std::string;
    auto randomChoice(const char* table, int count)->std::string;
    // ����ActId
    auto genActId()->std::string;
    // �������к�
    auto genSerial()->std::string;
    auto genSignature(const std::string& src)->std::string;
    auto encode(const std::string& src, size_t size, BYTE** encData, size_t round, size_t pos)->bool;
    // ��ȡ�������
    auto getComputerName()->std::string;
    // ��ȡ��ǰ��¼�û�
    auto getLoginUser()->std::string;
    // ��ȡϵͳ�����к�
    auto getSystemDiskSerial()->std::string;
public:
    auto genLicenseFile(const std::string& name, const std::string& company, const std::string& email)->bool;
    auto importLicenseFile()->bool;
};

