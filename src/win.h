#include <vector>
#include <string>

std::string toString( const std::wstring& wide );
std::wstring fromString( const std::string& multi );

std::vector< std::string > readPath();
void writePath( const std::vector< std::string >& paths );
