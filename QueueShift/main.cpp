#include <iostream>

using namespace std;
class Queue
{
    int  tail = -1   ;
    int q[5];
public:
    int isFull()
    {
        return (tail ==4) ;
    }
    int isEmpty()
    {
        return (tail == -1 );
    }

    void enqueu(int number)
    {

        if(!isFull())
        {
            q[++tail] = number;
        }
        else
            cout <<("queue is full \n");
    }
    int dequeu()
    {
        int  i ;
        if(!isEmpty())
        {

                int x = q[0];
                for( i =0 ; i<tail ; i++)
                {
                    q[i] = q[i+1];
                }



            tail -- ;


            return x;

        }
        return -1 ;
    }
    int peak()
    {
        if(!isEmpty())
        {

            return q[0] ;
        }

        return -1 ;
    }
};
int main()
{

    // cout << "Hello world!" << endl;
    Queue q ;
    q.enqueu(2);
    q.enqueu(3);
    q.enqueu(4);
    q.enqueu(5);
    q.enqueu(6);
    q.enqueu(7);
    cout << q.dequeu() << endl;
    cout << q.dequeu() << endl;
    q.enqueu(7);
    cout << q.dequeu() << endl;
    cout << q.peak() << endl;
    cout << q.dequeu() << endl;
    cout << q.dequeu() << endl;
    cout << q.dequeu() << endl;
    cout << q.dequeu() << endl;



    return 0;
}
