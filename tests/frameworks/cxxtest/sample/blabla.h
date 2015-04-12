/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>

#include "DeltaTest.h"

static DeltaTest suite_DeltaTest;

static CxxTest::List Tests_DeltaTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_DeltaTest( "DeltaTest.h", 7, "DeltaTest", suite_DeltaTest, Tests_DeltaTest );

static class TestDescription_DeltaTest_testSine : public CxxTest::RealTestDescription {
public:
 TestDescription_DeltaTest_testSine() : CxxTest::RealTestDescription( Tests_DeltaTest, suiteDescription_DeltaTest, 18, "testSine" ) {}
 void runTest() { suite_DeltaTest.testSine(); }
} testDescription_DeltaTest_testSine;

#include <cxxtest/Root.cpp>
