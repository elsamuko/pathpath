
set ASTYLE=AStyle.exe --style=java --add-brackets --indent-col1-comments --break-blocks --pad-oper --pad-paren-in --unpad-paren --indent-namespaces --align-pointer=type --align-reference=type --convert-tabs --lineend=windows 

%ASTYLE% -r src/*.cpp
%ASTYLE% -r src/*.h

%ASTYLE% -r Testing/*.cpp
%ASTYLE% -r Testing/*.h
