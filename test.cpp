#include "STACK.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace StackProject;

ofstream logFile("log.txt");

void log(const string& message) {
    cout << message << endl;
    logFile << message << endl;
}

#define RUN_TEST(testFunc, testName) \
    try { \
        testFunc(); \
        log(testName " - PASSED"); \
    } catch (...) { \
        log(testName " - UNPASSED"); \
    }

// 1 test
void testConstructor() {
    Stack stack;
    if (stack.toString() != "" || !stack.isEmpty()) throw runtime_error("Constructor test failed");
}

// 2 test   
void testPushAndPlusEquals() {
    Stack stack;
    stack.push(10);
    stack += 20;
    stack += 30;
    if (stack.toString() != "30 20 10 ") throw runtime_error("Push/+= test failed");
}

// 3 test
void testPopAndMinusEquals() {
    Stack stack;
    stack += 10;
    stack += 20;
    stack += 30;
    stack.pop();
    if (stack.toString() != "20 10 ") throw runtime_error("Pop test failed");
    --stack;
    if (stack.toString() != "10 ") throw runtime_error("-- Operator test failed");
}

// 4 test
void testTop() {
    Stack stack;
    stack += 10;
    stack += 20;
    if (stack.top() != 20) throw runtime_error("Top test failed");
}

// 5 test
void testStackUnderflow() {
    Stack stack;
    try { stack.pop(); throw runtime_error("Expected exception"); } catch (const StackUnderflowException&) {}
    try { stack.top(); throw runtime_error("Expected exception"); } catch (const StackUnderflowException&) {}
}

// 6 test
void testClear() {
    Stack stack;
    stack += 10;
    stack += 20;
    stack.clear();
    if (!stack.isEmpty()) throw runtime_error("Clear test failed");
}

// 7 test
void testMoveConstructor() {
    Stack stack;
    stack += 10;
    stack += 20;
    Stack movedStack = std::move(stack);
    if (movedStack.toString() != "20 10 " || stack.toString() != "") throw runtime_error("Move constructor failed");
}

// 8 test
void testEqualityAndInequalityOperators() {
    Stack stack1, stack2;
    stack1 += 10;
    stack1 += 20;
    stack2 += 10;
    stack2 += 20;
    if (!(stack1 == stack2)) throw runtime_error("Equality test failed");
    stack2 += 30;
    if (!(stack1 != stack2)) throw runtime_error("Inequality test failed");
}

// 9 test
void testFreeMemory() {
    Stack stack;
    stack += 10;
    stack += 20;
    !stack;
    if (stack.toString() != "") throw runtime_error("Free memory test failed");
}

// 10 test
void testComparisonOperators() {
    Stack stack1, stack2;
    stack1 += 10;
    stack1 += 20;
    stack2 += 10;
    stack2 += 20;
    stack2 += 30;
    if (!(stack1 < stack2) || !(stack2 > stack1)) throw runtime_error("Comparison operators test failed");
}

// 11 test
void testSizeMethod() {
    Stack stack;
    if (stack.size() != 0) throw runtime_error("Size test failed");
    stack += 10;
    stack += 20;
    if (stack.size() != 2) throw runtime_error("Size test failed");
    stack.pop();
    if (stack.size() != 1) throw runtime_error("Size test failed");
}

void runTests() {
    RUN_TEST(testConstructor, "Test 1: Constructor");
    RUN_TEST(testPushAndPlusEquals, "Test 2: Push and += Operator");
    RUN_TEST(testPopAndMinusEquals, "Test 3: Pop and -- Operator");
    RUN_TEST(testTop, "Test 4: Top Element");
    RUN_TEST(testStackUnderflow, "Test 5: Stack Underflow");
    RUN_TEST(testClear, "Test 6: Clear");
    RUN_TEST(testMoveConstructor, "Test 7: Move Constructor");
    RUN_TEST(testEqualityAndInequalityOperators, "Test 8: Equality and Inequality Operators");
    RUN_TEST(testFreeMemory, "Test 9: Free Memory (! Operator)");
    RUN_TEST(testComparisonOperators, "Test 10: Comparison Operators");
    RUN_TEST(testSizeMethod, "Test 11: Size Method");
    log("All tests completed.");
}

int main() {
    if (!logFile.is_open()) {
        cerr << "Error: Could not open log.txt for writing." << endl;
        return 1;
    }
    runTests();
    logFile.close();
    return 0;
}