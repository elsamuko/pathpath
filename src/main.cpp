// Copyright 2012 FD Imaging
// All rights reserved.
//
// THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.

#include <iostream>
#include <vector>

#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string.hpp>

#include "win.h"
#include "log.h"
#include "io.h"

void usage() {
    LOG( "Usage: pathpath.exe read/write" );
    LOG( "Read needs no admin rights and writes all path variables to \"path.txt\"" );
    LOG( "Write needs admin rights and reads all path variables from \"path.txt\"" );
}

int main( int argc, char* argv[] ) {

    LOGBEGIN( "Running pathpath" );

    if( argc != 2 ) {
        usage();
    } else if( std::string( argv[1] ) == "read" ) {

        LOG( "Read path from registry" );
        std::vector< std::string > paths = readPath();
        std::string path = boost::algorithm::join( paths, "\n" );
        writeFile( "path.txt", path );

    } else if( std::string( argv[1] ) == "write" ) {

        LOG( "Write path to registry" );
        std::string path = readFile( "path.txt" );
        std::vector< std::string > paths;
        boost::split( paths, path, boost::is_any_of( "\n\r" ), boost::token_compress_on );

        if( !paths.empty() ) {
            writePath( paths );
        } else {
            LOG( "Could not read \"path.txt\"" );
        }

    } else {
        usage();
    }

    LOGEND( "Bye bye..." );

    return 0;
}
