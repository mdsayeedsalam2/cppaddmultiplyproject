// CppUnit test driver program:
#include <iostream>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/CompilerOutputter.h>

#include "CBasicMath.h"

using namespace std;

class TestBasicMath : public CPPUNIT_NS::TestCase
{
    CPPUNIT_TEST_SUITE(TestBasicMath);
    CPPUNIT_TEST(testAddition);
    CPPUNIT_TEST(testSubtraction);
    CPPUNIT_TEST(testMultiply);
    CPPUNIT_TEST(testDivision);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testAddition(void);
    void testSubtraction(void);
    void testMultiply(void);
    void testDivision(void);

private:

    CBasicMath *mTestObj;
};

//-----------------------------------------------------------------------------

void
TestBasicMath::testAddition(void)
{
    CPPUNIT_ASSERT(5 == mTestObj->Addition(2,3));
}

void
TestBasicMath::testSubtraction(void)
{
    CPPUNIT_ASSERT(-1 == mTestObj->Subtraction(2,3));
}

void
TestBasicMath::testMultiply(void)
{
    CPPUNIT_ASSERT(6 == mTestObj->Multiply(2,3));
}

void
TestBasicMath::testDivision(void)
{
    CPPUNIT_ASSERT(2 == mTestObj->Division(6,3));
}

void TestBasicMath::setUp(void)
{
    mTestObj = new CBasicMath();
}

void TestBasicMath::tearDown(void)
{
    delete mTestObj;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestBasicMath );

int main(int argc, char* argv[])
{
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();


    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}
