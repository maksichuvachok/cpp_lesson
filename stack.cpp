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

        unsigned int stack_empty()
        {
            return top != 0;
        }

        void push(int x)
        {
            if (top > 5)
                throw "overflow";
            top++;
            stack_space[top - 1] = x;
            
        }

        void pop()
        {
            if (!stack_empty())
                throw "underflow";
            top--;
        }

        void show_last()
        {
            cout << stack_space[top - 1];
        }

    private:
        int *stack_space;
        unsigned int top;
};

int main()
{
    Stack s1;
    cout << s1.stack_empty() << endl;
    try 
    {
        s1.push(4);
        s1.push(1);
        s1.push(3);
        s1.push(7);
        s1.push(7);
        s1.push(7);
        cout << s1.stack_empty() << endl;

        for (s1.stack_empty(); s1.stack_empty() != 0; s1.pop())
        {
            s1.show_last();
            cout << ' ';       
        }
    }
    catch (const char *error_message)
    {
        cout << error_message << endl;
    }
    
    cout << endl;
    return 0;
}