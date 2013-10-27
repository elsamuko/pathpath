// Copyright 2012 FD Imaging
// All rights reserved.
//
// THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.

#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/foreach.hpp>

#include "windows.h"

#include "log.h"

#pragma comment( lib, "advapi32.lib" )

std::string toString( const std::wstring& wide ) {
    return std::string( wide.begin(), wide.end() );
}

std::wstring fromString( const std::string& multi ) {
    int size = MultiByteToWideChar( CP_ACP, 0, multi.c_str(), multi.size(), 0, 0 );
    std::wstring wide( L" ", size );
    MultiByteToWideChar( CP_ACP, 0, multi.c_str(), multi.size(), ( LPWSTR )wide.c_str(), size );
    return wide;
}

std::string getKey( HKEY hKey, const std::wstring& value ) {

    std::wstring result;
    DWORD size = 0;

    if( RegQueryValueExW( hKey, value.c_str(), 0, NULL, NULL, &size ) == ERROR_SUCCESS ) {
        result.resize( size / 2 );
        RegQueryValueExW( hKey, value.c_str(), 0, NULL, ( LPBYTE )result.c_str(), &size );
    };

    std::string path = toString( result );

    // remove last zero
    if( ! path.empty() ) {
        path.resize( path.size() - 1 );
    }

    return path;
}

bool setKey( HKEY hKey, const std::wstring& value,  const std::string& data ) {

    std::wstring dataw = fromString( data );

    LONG ok = RegSetValueEx( hKey, value.c_str(), 0, REG_SZ, ( LPBYTE )dataw.c_str(), dataw.size() * 2 );

    return ok == ERROR_SUCCESS;
}

std::vector< std::string > readPath() {

    std::vector< std::string > paths;
    HKEY hKey = 0;

    LONG lRes = RegOpenKeyExW( HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment", 0, KEY_READ, &hKey );

    if( lRes != ERROR_SUCCESS ) {
        LOG( "Failed to access PATH key" );
    }

    std::string path = getKey( hKey, L"Path" );

    if( path.empty() ) {
        LOG( "Failed to read PATH key" );
    } else {
        boost::algorithm::trim( path );
        boost::split( paths, path, boost::is_any_of( ";" ), boost::token_compress_on );
    }

    RegCloseKey( hKey );

    return paths;
}

std::string writePath( const std::vector< std::string >& paths ) {
    HKEY hKey = 0;

    LONG lRes = RegOpenKeyExW( HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment", 0, KEY_WRITE, &hKey );

    if( lRes != ERROR_SUCCESS ) {
        LOG( "Failed to access PATH key" );
    }

    std::string path = boost::algorithm::join( paths, ";" );

    if( ! setKey( hKey, L"Path", path ) ) {
        LOG( "Failed to write PATH key" );
    }

    RegCloseKey( hKey );

    return path;
}
