#include <iostream>
#include <stdlib.h>
using namespace std;


class Stack
{

    struct Node
    {
        int key ;
        Node * next ;
        Node * prev ;
    };

    Node * pLast ;
    Node  * pStart;


    Node  * newNode (int key)
    {
        Node * pNode  = new Node ;
        if (pNode == NULL)
            exit(0);

        pNode ->  next = NULL ;
        pNode -> prev = NULL ;


        pNode->key = key ;
        return pNode ;
    }

    void ADDNode(int key)
    {
        Node * pNode ;
        pNode = newNode(key);
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
public:
    Stack (int L = 5 )
    {
        pLast=pStart= NULL;
    }

    int isFull()
    {
        return 1 ;
    }
    int isEmpty()
    {
        return (pStart == NULL );
    }

    void push(int number)
    {
        ADDNode(number);
    }
    int pop()
    {
        if(pLast )
        {
            Node * pNode  = pLast;
            pLast  = pLast ->prev;


            return pNode->key ;
        }

        throw      "";

    }

    int peak()
    {
        return pLast->key;
    }

    void viewContent()
    {


        Node * pNode ;
        pNode = pStart ;
        while(pStart)
        {
            cout << pNode ->key << endl ;
            pNode = pNode->next;
        }

    }
};

int main()
{
    //  cout << "Hello world!" << endl;

    //case 1
    Stack s ;

    s.push(0);

    s.push(1);

    cout << s.pop()<< endl;
    cout << s.pop()<< endl;


//    viewContent(s);

    Stack s3(10);
//    s3 = s ;
    s3.push(123);
    s3.push(983);


  //  cout <<s3.pop()<< endl;
  //  cout <<s3.pop()<< endl;
   // cout <<s3.pop()<< endl;

    s3.viewContent();
//    viewContent(c);
    //viewContent(c);
    /*// case 2
    cout <<s.reverseStack().pull()<<endl;

    // case 3
        Stack s2(s);

        viewContent(s2);


    */
    return 0;
}
