// This file contains template classes for data structures

#include <iostream>

template <typename T>
class Stack
{
private:
    int size;
    int top;
    T *stack;

public:
    Stack()
    {
        this->size = 5;
        top = -1;

        try
        {
            stack = new T[this->size];
        }
        catch (const std::bad_alloc &e)
        {
            std::cout << "Memory Allocation"
                      << " is failed: " << e.what() << std::endl;
        }
    }
    Stack(int size)
    {
        this->size = size;
        top = -1;

        try
        {
            stack = new T[this->size];
        }
        catch (const std::bad_alloc &e)
        {
            std::cout << "Memory Allocation is failed: " << e.what() << std::endl;
        }
    }
    ~Stack()
    {
        delete[] stack;
    }

    void push(T data, bool passMessage = 0)
    {
        if (top == size - 1)
            std::cout << "Overflow !" << std::endl;
        else
        {
            top++;
            stack[top] = data;
            if (passMessage == 1)
                std::cout << data << " inserted in stack" << std::endl;
        }
    }

    T pop(bool passMessage = 0)
    {
        if (top == -1)
            std::cout << "Underflow !" << std::endl;
        else
        {
            T returnValue = stack[top];
            top--;
            if (passMessage == 1)
                std::cout << returnValue << " removed from stack" << std::endl;
            return returnValue;
        }
    }

    void display(bool passMessage = 0)
    {
        if (top == -1)
        {
            if (passMessage == 1)
                std::cout << "Empty list" << std::endl;
            return;
        }
        else
        {
            std::cout << "| ";
            for (int i = 0; i <= top; i++)
                std::cout << stack[i] << " | ";
            std::cout << std::endl;
        }
    }

    T peek()
    {
        if (top == -1)
            return NULL;
        else
            return stack[top];
    }

    bool isFull()
    {
        return (top == (this->size - 1));
    }

    bool isNull()
    {
        return (top == -1);
    }
};

int main()
{
    Stack<int> ms(5); //default size = 5    std::cout<<std::endl;
    std::cout << "IsNull = " << ms.isNull() << std::endl;
    std::cout<<std::endl;
    std::cout << "Peek = " << ms.peek() << std::endl;
    std::cout<<std::endl;
    std::cout << "TEST CASE: Displaying empty stack" << std::endl;
    ms.display(1); // setting display to print message
    ms.display();  // setting display not to print message
    std::cout<<std::endl;
    std::cout << "TEST CASE: Pop from empty list" << std::endl;
    ms.pop();
    std::cout<<std::endl;
    std::cout << "TEST CASE: Pushing 11 with message pass = 1" << std::endl;
    ms.push(11, 1); // setting to print message
    std::cout<<std::endl;
    std::cout << "TEST CASE: Pushing 22 with message pass = 0" << std::endl;
    ms.push(22, 0); // setting no message printing
    std::cout<<std::endl;
    std::cout << "TEST CASE: Display operation" << std::endl;
    ms.display();
    std::cout<<std::endl;
    std::cout << "TEST CASE: Pushing 33" << std::endl;
    ms.push(33, 1); // Setting pass message = 1
    std::cout<<std::endl;
    std::cout << "TEST CASE: Display operation" << std::endl;
    ms.display();
    std::cout<<std::endl;
    std::cout << "TEST CASE: Pop operation" << std::endl;
    ms.pop(1); // setting pop to print message
    std::cout<<std::endl;
    std::cout << "TEST CASE: Display operation" << std::endl;
    ms.display();
    std::cout<<std::endl;
    std::cout << "TEST CASE: Pushing 44" << std::endl;
    ms.push(44, 0); // setting no message printing
    std::cout<<std::endl;
    std::cout << "TEST CASE: Display operation" << std::endl;
    ms.display();
    std::cout<<std::endl;
    std::cout << "TEST CASE: Pushing 55" << std::endl;
    ms.push(55, 0); // setting no message printing
    std::cout<<std::endl;
    std::cout << "TEST CASE: Display operation" << std::endl;
    ms.display();
    std::cout<<std::endl;
    std::cout << "TEST CASE: Pushing 66" << std::endl;
    ms.push(66, 0); // setting no message printing
    std::cout<<std::endl;
    std::cout << "TEST CASE: Display operation" << std::endl;
    ms.display();
    std::cout<<std::endl;
    std::cout << "TEST CASE: Pushing 77 in full stack" << std::endl;
    ms.push(77, 1); // setting message printing = 1
    std::cout<<std::endl;
    std::cout << "TEST CASE: Display operation" << std::endl;
    ms.display();
    return 0;
}