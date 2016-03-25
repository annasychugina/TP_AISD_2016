/*   Copyright (C) 2016 Sychugina Anna */
#include <iostream> 
#include <stack>

template<class T> class Queue
{
    std::stack<T> lifoStack, fifoStack; //lifo--push, fifo--pop

    void fillFifoStack()
    {
        while (!lifoStack.empty())
        {
            fifoStack.push(lifoStack.top());
            lifoStack.pop(); //удаление
        }
    }
public:

    bool empty()
    {
        return fifoStack.empty() && lifoStack.empty();
    }

    T dequeue()
    {
        if (empty()) return -1;

        if (fifoStack.empty()) fillFifoStack();

        T ret = fifoStack.top();
        fifoStack.pop(); //удаление
        return ret;
    }

    void enqueue(T v)
    {
        lifoStack.push(v);
    }
};

int main()
{
    int n = 0;
    std::cin >> n;
    Queue<int> queue;
    bool result = true;
    for (int i = 0; i < n; i++)
    {
        int operation = 0;
        std::cin >> operation;
        int number = 0;
        std::cin >> number;
        switch (operation)
        {

        case 2:

            if (number != queue.dequeue())
            {
                result = false;
            }
            break;
        case 3:
            queue.enqueue(number);
            break;
        }
    }
    std::cout << (result ? "YES" : "NO");
    return 0;

}
