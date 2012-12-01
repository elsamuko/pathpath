#include <QtCore/QString>
#include <QtTest/QtTest>

#include <string>

#include "win.h"

class TestConversion : public QObject {
    Q_OBJECT

public:
    TestConversion() {}

private Q_SLOTS:
    void testToString();
    void testFromString();
};


void TestConversion::testFromString() {
    QVERIFY( fromString( "München\n" ) == L"München\n" );
}

void TestConversion::testToString() {
    QVERIFY( toString( L"München\n" ) == "München\n" );
    QVERIFY( toString( L"0xab0xcd0xef\n" ) == "0xab0xcd0xef\n" );
}

QTEST_MAIN( TestConversion )

#include "testConversion.moc"
