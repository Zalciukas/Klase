#include "STACK.h"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace StackProject;

int main() {
    try {
        Stack stack1;
        stack1 += 10;
        stack1 += 20;
        stack1 += 30;
        stack1 += 40;
        stack1 += 50;

        cout << "Stack1: " << stack1 << endl;
        cout << "Stack1 size: " << stack1.size() << endl;
        cout << "Top element: " << stack1.top() << endl;

        stack1.pop();
        cout << "Stack1 after popping: " << stack1 << endl;

        --stack1;
        cout << "Stack1 after using -- operator: " << stack1 << endl;

        Stack stack2 = stack1;
        cout << "Stack1 == Stack2: " << (stack1 == stack2 ? "True" : "False") << endl;

        stack2.push(60);
        cout << "Stack2 after pushing 60: " << stack2 << endl;

        !stack1;
        cout << "Stack1 after freeing memory: " << stack1 << endl;
        cout << "Stack1 is empty: " << (stack1.isEmpty() ? "True" : "False") << endl;

        cout << "Stack1: " << stack1 << endl;
        cout << "Stack2: " << stack2 << endl;
        cout << "Stack2 > Stack1: " << (stack2 > stack1 ? "True" : "False") << endl;
        cout << "Stack1 < Stack2: " << (stack1 < stack2 ? "True" : "False") << endl;

        try {
            stack1.top();
        } catch (const StackUnderflowException& e) {
            cerr << "Caught exception: " << e.what() << endl;
        }

    } catch (...) {
        cerr << "Unhandled unknown exception occurred." << endl;
        return 1;
    }
    cout << "Program completed successfully." << endl;

    return 0;
}