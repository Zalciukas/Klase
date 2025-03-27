#include "STACK.h"
#include <iostream>
#include <sstream>
#include <algorithm>

namespace StackProject {

    class StackImpl {
    public:
        StackNode* top;
        size_t stackSize;

        StackImpl() : top(nullptr), stackSize(0) {}
        ~StackImpl() { freeMemory(); }

        void freeMemory();
        StackNode* copyStack(const StackNode* otherTop) const;
        double sumValues() const;
        bool compareStacks(const StackNode* a, const StackNode* b) const;
    };

    Stack::Stack() : pImpl(std::make_unique<StackImpl>()) {}

    Stack::~Stack() {
        // No need to manually free memory; unique_ptr handles it
    }

    Stack::Stack(const Stack& other) : pImpl(std::make_unique<StackImpl>()) {
        if (other.pImpl && other.pImpl->top) {
            pImpl->top = pImpl->copyStack(other.pImpl->top);
            pImpl->stackSize = other.pImpl->stackSize;
        }
    }

    Stack::Stack(Stack&& other) noexcept {
        pImpl = std::move(other.pImpl); // Transfer ownership
        other.pImpl = std::make_unique<StackImpl>(); // Reset the moved-from object to a new, empty state
    }

    Stack& Stack::operator=(Stack&& other) noexcept {
        if (this != &other) {
            // Release any existing resources
            pImpl.reset();

            // Transfer ownership of pImpl
            pImpl = std::move(other.pImpl);

            // Reset the moved-from object to a new, empty state
            other.pImpl = std::make_unique<StackImpl>();
        }
        return *this;
    }

    void Stack::push(const double& val) {
        StackNode* newNode = new StackNode(val);
        newNode->next = pImpl->top;
        pImpl->top = newNode;
        pImpl->stackSize++;
    }

    void Stack::pop() {
        if (isEmpty()) {
            throw StackUnderflowException();
        }

        StackNode* temp = pImpl->top;
        pImpl->top = pImpl->top->next;
        delete temp;
        pImpl->stackSize--;
    }

    double Stack::top() const {
        if (isEmpty()) {
            throw StackUnderflowException();
        }
        return pImpl->top->value;
    }

    bool Stack::isEmpty() const {
        return pImpl->top == nullptr;
    }

    size_t Stack::size() const {
        return pImpl->stackSize;
    }

    void Stack::clear() {
        pImpl->freeMemory();
        pImpl->top = nullptr;
        pImpl->stackSize = 0;
    }

void Stack::print() const {
    StackNode* current = pImpl->top;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

    std::string Stack::toString() const {
        std::ostringstream os;
        StackNode* current = pImpl->top;
        while (current) {
            os << current->value << " ";
            current = current->next;
        }
        return os.str();
    }

    Stack& Stack::operator+=(const double& val) {
        push(val);
        return *this;
    }

    Stack& Stack::operator--() {
        pop();
        return *this;
    }

    void Stack::operator!() {
        clear();
    }

    bool Stack::operator==(const Stack& other) const {
        return pImpl->compareStacks(pImpl->top, other.pImpl->top);
    }

    bool Stack::operator!=(const Stack& other) const {
        return !(*this == other);
    }

    bool Stack::operator>(const Stack& other) const {
        return pImpl->sumValues() > other.pImpl->sumValues();
    }

    bool Stack::operator<(const Stack& other) const {
        return pImpl->sumValues() < other.pImpl->sumValues();
    }

    std::ostream& operator<<(std::ostream& os, const Stack& stack) {
        StackNode* current = stack.pImpl->top;
        while (current) {
            os << current->value << " ";
            current = current->next;
        }
        return os;
    }

    // StackImpl Private Methods
    void StackImpl::freeMemory() {
        while (top) {
            StackNode* temp = top;
            top = top->next;
            delete temp;
        }
        stackSize = 0;
    }

    StackNode* StackImpl::copyStack(const StackNode* otherTop) const {
        if (!otherTop) return nullptr;

        // Create a dummy head node for reverse copying
        StackNode* newTop = nullptr;
        const StackNode* current = otherTop;

        // First, create a stack in reverse order
        while (current) {
            StackNode* newNode = new StackNode(current->value);
            newNode->next = newTop;
            newTop = newNode;
            current = current->next;
        }

        return newTop;
    }

    double StackImpl::sumValues() const {
        double sum = 0;
        StackNode* current = top;
        while (current) {
            sum += current->value;
            current = current->next;
        }
        return sum;
    }

    bool StackImpl::compareStacks(const StackNode* a, const StackNode* b) const {
        while (a && b) {
            if (a->value != b->value) return false;
            a = a->next;
            b = b->next;
        }
        return !a && !b;
    }

} // namespace StackProject