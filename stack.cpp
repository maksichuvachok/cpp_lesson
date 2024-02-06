#include <iostream>
using std::cout;
using std::endl;

class Stack
{
    public:

        Stack()
        {
            stack_space = new int[6];
            top = 0;
        };
        ~Stack()
        {
            delete [] stack_space;
        };

    private:
        int *stack_space;
        unsigned int top;
    public:
        unsigned int stack_empty()
        {
            if (top == 0)
                return 0;
            else
                return top;
        }

        void push(int x)
        {
            if (top > 5)
                cout << "overflow" << endl;
            else
            {
                top++;
                stack_space[top - 1] = x;
            }
        }

        void pop()
        {
            if (stack_empty() == 0)
                cout << "underflow" << endl;
            else
                top--;
        }

        void show_last(unsigned int i)
        {
            cout << stack_space[i - 1];
        }
};

int main()
{
    Stack s1;
    s1.push(4);
    cout << s1.stack_empty() << endl;
    s1.push(1);
    s1.push(3);
    s1.push(7);
    s1.push(7);
    s1.push(7);
    cout << s1.stack_empty() << endl;

    s1.push(99);
    s1.push(99);
    
    for (s1.stack_empty(); s1.stack_empty() > 0; s1.pop())
    {
        s1.show_last(s1.stack_empty());
        cout << ' ';       
    }
    cout << endl;
    return 0;
}