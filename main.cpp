#include <iostream>
#include "windows.h"

#pragma comment( lib, "advapi32.lib" )

using std::cout;
using std::wcout;
using std::cerr;
using std::wcerr;
using std::endl;

std::wstring GetStringRegKey( HKEY hKey, const std::wstring &strValueName )
{
    std::wstring result;
    DWORD size = 0;

    if( RegQueryValueExW(hKey, strValueName.c_str(), 0, NULL, NULL, &size) == ERROR_SUCCESS ){
        result.resize( size + 1 );
        RegQueryValueExW(hKey, strValueName.c_str(), 0, NULL, (LPBYTE)result.c_str(), &size );
    };
    return result;
}

int main()
{
    HKEY hKey = 0;
    LONG lRes = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment", 0, KEY_READ, &hKey);
    if( lRes != ERROR_SUCCESS ) {
        cerr << "Failed to read PATH key" << endl;
    }
    std::wstring path = GetStringRegKey( hKey, L"Path" );

    wcout << L"Path" << path.c_str() << endl;
    return 0;
}
