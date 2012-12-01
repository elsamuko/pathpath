// Copyright 2012 FD Imaging
// All rights reserved.
//
// THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.

#include <iostream>
#include <fstream>
#include <sstream>

#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string.hpp>

#include "log.h"

#include <time.h>

unsigned long getTime() {
    clock_t time = clock();
    time *= 1000;
    time /= CLOCKS_PER_SEC;
    return time;
}

void writeLog( int line, const char* function, std::string content, bool trim ) {

    std::stringstream ss;

    // time
    ss.width( 6 );
    ss << getTime() << " ms";

    // line
    ss.fill( ' ' );
    ss << " L:";
    ss.width( 4 );
    ss.setf( std::ios::right );
    ss << line << " F:";

    // function
    ss.width( 20 );
    ss.setf( std::ios::left );
    ss << function << " : ";

    // beautify
    std::string alignment = std::string( ss.str().size(), ' ' );
    std::string formatted = trim ? boost::trim_right_copy( content ) : content;
    boost::replace_all( formatted, std::string( "\n" ), std::string( "\n" ) + alignment );

    ss << formatted << std::endl;

    std::cout << ss.str();
}
