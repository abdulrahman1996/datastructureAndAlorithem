#include <stdlib.h>
#include <iostream>

using namespace std;
class Queue
{
    struct Node
    {
        int key ;
        Node * next ;
        Node * prev ;
    };
    Node * pLast = NULL ;
    Node  * pStart = NULL;
    Node  * newNode (int key)
    {
        Node * pNode  = new Node ;
        if (pNode == NULL)
            exit(0);

        pNode ->  next = NULL ;
        pNode -> prev = NULL ;


        pNode->key  = key ;

        return pNode ;
    }


public:
    int isFull()
    {
        return 1;
    }
    int isEmpty()
    {
        return pStart == NULL ;
    }
    void enqueu(int key )
    {
        Node * pNode = newNode(key);
        if(pStart == NULL)
        {

            pStart = pLast = pNode ;
        }
        else
        {

            pLast -> next = pNode ;
            pNode ->prev  = pLast ;
            pLast = pNode;
        }

    }

    int dequeu()
    {

        if(isEmpty() == 0 )
        {
            Node  * pDeq = pStart;

            pStart = pStart->next;
            return pDeq->key;
        }

        cout << "empty queue !";
        return -1;
    }
    int peak()
    {
        return pStart->key;
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
    cout << q.dequeu() << endl;
    cout << q.dequeu() << endl;
    cout << q.dequeu() << endl;
    cout << q.dequeu() << endl;
    cout << q.dequeu() << endl;
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
