#include <iostream>
using std::cout;
using std::endl;

class queue
{
    public:
        queue(unsigned int size)
        {
            queue_size = size + 1;
            queue_space = new int[queue_size];
            head = 1;
            tail = 1;
        }
        ~queue()
        {
            delete [] queue_space;
        }
        unsigned int empty()
        {
            return head != tail;
        }
        void enqeue(int i)
        {
            if (head == tail + 1)
                throw "overflow";
            queue_space[tail - 1] = i;
            tail++;
            if (tail > queue_size)
                tail %= queue_size;
        }
        void dequeue()
        {
            if (head == tail)
                throw "underflow";
            head = head % queue_size + 1;
        }
        void show_head()
        {
            cout << queue_space[head - 1];
        }
    private:
        int *queue_space;
        unsigned int head;
        unsigned int tail;
        unsigned int queue_size;
};

int main()
{
    queue q1(5);
    
    try
    {
        q1.enqeue(1);
        q1.enqeue(2);
        q1.dequeue();
        q1.enqeue(3);
        q1.enqeue(4);
        q1.enqeue(5);
        q1.enqeue(6);

        while (q1.empty())
        {
            q1.show_head();
            cout << ' ';
            q1.dequeue();
        }
    }
    catch(const char *error)
    {
        cout << error << endl;
    }

    return 0;
}