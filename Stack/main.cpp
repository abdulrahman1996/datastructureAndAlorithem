#include <iostream>

using namespace std;
class Stack
{
    int tos, size ;
    int *stk;
public:
    Stack (int L = 5 )
    {
        size = L ;
        tos = 0 ;
        stk = new int [size];
    }
    Stack(Stack &oldStack)
    {
        size = oldStack.size ;
        tos = oldStack.tos;
        stk = new int[size];
        for(int i =0 ; i< tos ; i++)
        {
            stk[i] = oldStack.stk[i];

        }
        cout <<"copy\n";
    }
    ~Stack()
    {

        for(int i =0 ; i<tos ; i++)
            stk[i] = -1;

        delete [] stk;
        //  cout <<"des \n " ;
    }
    Stack& operator =  (const Stack& s)
    {
        delete [] stk;
        size = s.size ;
        tos = s.tos;
        stk = new int[size];
        for(int i =0 ; i< tos ; i++)
        {
            stk[i] = s.stk[i];

        }

        return *this;
    }
    int operator == (Stack& s2)
    {
        if(s2.tos != tos)
            return 0 ;
        for(int i = 0 ; i<tos ; i++)
            if(s2.stk[i] != stk[i])
                return 0;

        return 1;
    }

    Stack operator +(Stack s2)
    {
        int i ;

     //   int Btos = (tos<s2.tos) ? tos :s2.tos;
        Stack s3 (s2.size+ size);
        s3.tos = tos + s2.tos;
        for(i = 0 ; i<tos ; i++)
            s3.stk[i] = stk[i];

        for(int j=0 ; j<s2.tos ; i++ , j++)
        {
            s3.stk[i] = s2.stk[j];
        }

        return s3;
    }

    int isFull()
    {
        return (tos==size) ;
    }
    int isEmpty()
    {
        return (tos == 0 );
    }

    void push(int number)
    {

        if(!isFull())
        {
            stk[tos++]
                = number;
        }
        else
            cout <<("stack over flow \n");
    }
    int pull()
    {
        if(!isEmpty())
        {
            return stk[--tos] ;
        }
        return -1 ;
    }
    int peak()
    {
        if(!isEmpty())
        {
            return stk[tos-1] ;
        }

        return -1 ;
    }
    Stack reverseStack()
    {
        Stack r(size);
        int temp ;
        for(int i =0 ; i<tos ; i++)
        {
            r.stk[i] = stk[tos-i-1];
            r.tos++;
        }
        return r ;

    }
    friend void viewContent(Stack s);
};
void viewContent(Stack s)
{
    for(int i = 0 ; i<s.tos ; i++)
        cout  <<s.stk[i] <<endl;

}
int main()
{
    //  cout << "Hello world!" << endl;

    //case 1
    Stack s ;

    s.push(0);
    s.push(1);




    viewContent(s);

    Stack s3(10);
    s3 = s ;
    s3.push(123);
    s3.push(983);

    Stack c ;
    c = s+s3;
    c.push(67);
    viewContent(s);
    viewContent(s3);
    viewContent(c);
    /*// case 2
    cout <<s.reverseStack().pull()<<endl;

    // case 3
        Stack s2(s);

        viewContent(s2);


    */
    return 0;
}
