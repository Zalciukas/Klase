#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <memory>  // For std::unique_ptr

namespace StackProject {

    /**
     * @brief Represents a single node in the Stack.
     */
    struct StackNode {
        double value;         // The value stored in the node.
        StackNode* next;      // Pointer to the next node.

        /**
         * @brief Constructs a StackNode with a given value.
         * @param val The value to store in the node.
         */
        explicit StackNode(double val)
            : value(val), next(nullptr) {}
    };

    class StackImpl;  // Forward declaration of the implementation class

    /**
     * @brief Represents a Stack (Last-In-First-Out) data structure.
     * 
     * This class provides a public interface for interacting with the Stack,
     * while hiding implementation details using the PImpl idiom.
     */
    class Stack {
    private:
        std::unique_ptr<StackImpl> pImpl;  ///< Pointer to the implementation class.

    public:
        /**
         * @brief Constructs an empty Stack.
         */
        Stack();

        /**
         * @brief Destroys the Stack and frees all associated memory.
         */
        ~Stack();

        /**
         * @brief Constructs a deep copy of another Stack.
         * @param other The Stack to copy.
         */
        Stack(const Stack& other);

        /**
         * @brief Deleted copy assignment operator to prevent copying.
         */
        Stack& operator=(const Stack& other) = delete;

        /**
         * @brief Move constructor to transfer ownership of resources.
         * @param other The Stack to move from.
         */
        Stack(Stack&& other) noexcept;

        /**
         * @brief Move assignment operator to transfer ownership of resources.
         * @param other The Stack to move from.
         * @return Reference to the current Stack.
         */
        Stack& operator=(Stack&& other) noexcept;

        /**
         * @brief Pushes a value onto the top of the Stack.
         * @param val The value to push.
         */
        void push(const double& val);

        /**
         * @brief Removes the top element from the Stack.
         */
        void pop();

        /**
         * @brief Returns the top element of the Stack.
         * @return The value at the top of the Stack.
         * @throws std::runtime_error if the Stack is empty.
         */
        double top() const;

        /**
         * @brief Checks if the Stack is empty.
         * @return True if the Stack is empty, false otherwise.
         */
        bool isEmpty() const;

        /**
         * @brief Returns the number of elements in the Stack.
         * @return The size of the Stack.
         */
        size_t size() const;

        /**
         * @brief Clears all elements from the Stack.
         */
        void clear();

        /**
         * @brief Prints the contents of the Stack from top to bottom.
         */
        void print() const;

        /**
         * @brief Returns a string representation of the Stack.
         * @return A string containing the Stack elements.
         */
        std::string toString() const;

        // Arithmetic and utility operators

        /**
         * @brief Pushes a value onto the Stack using the += operator.
         * @param val The value to push.
         * @return Reference to the current Stack.
         */
        Stack& operator+=(const double& val);

        /**
         * @brief Removes the top element using the -- operator.
         * @return Reference to the current Stack.
         */
        Stack& operator--();

        /**
         * @brief Clears the Stack using the ! operator.
         */
        void operator!();

        // Comparison operators

        /**
         * @brief Compares two Stacks for equality.
         * @param other The Stack to compare with.
         * @return True if the Stacks are equal, false otherwise.
         */
        bool operator==(const Stack& other) const;

        /**
         * @brief Compares two Stacks for inequality.
         * @param other The Stack to compare with.
         * @return True if the Stacks are not equal, false otherwise.
         */
        bool operator!=(const Stack& other) const;

        /**
         * @brief Checks if the current Stack has a greater total value than another Stack.
         * @param other The Stack to compare with.
         * @return True if the current Stack is greater, false otherwise.
         */
        bool operator>(const Stack& other) const;

        /**
         * @brief Checks if the current Stack has a lesser total value than another Stack.
         * @param other The Stack to compare with.
         * @return True if the current Stack is less, false otherwise.
         */
        bool operator<(const Stack& other) const;

        // Stream insertion operator

        /**
         * @brief Outputs the Stack contents to a stream.
         * @param os The output stream.
         * @param stack The Stack to output.
         * @return The output stream.
         */
        friend std::ostream& operator<<(std::ostream& os, const Stack& stack);
    };

    /**
     * @brief Exception class for handling stack underflow.
     */
    class StackUnderflowException : public std::runtime_error {
    public:
        /**
         * @brief Constructs a StackUnderflowException.
         */
        StackUnderflowException()
            : std::runtime_error("Stack is empty") {}
    };

}
#endif // STACK_H