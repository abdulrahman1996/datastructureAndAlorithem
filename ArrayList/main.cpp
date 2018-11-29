#include <iostream>
#include  <stdlib.h>
using namespace std;
 struct Node
 {
     int key ;
     Node * next ;
     Node * prev ;
 };
 Node * pLast = NULL ;
 Node  * pStart = NULL;


 Node  * newNode (int key )
 {
     Node * pNode  = new Node ;
     if (pNode == NULL)
        exit(0);

     pNode ->  next = NULL ;
     pNode -> prev = NULL ;

     //cout<<"Enter key" << endl ;
     pNode->key  = key;
     return pNode ;
 }

 void ADDNode(int key )
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
 Node * search (int key )
 {
     Node *  pSearch = pStart ;
     while (pSearch)
     {
         if(key == pSearch -> key)
            return  pSearch ;
         pSearch = pSearch->next;
     }
     return NULL ;
 }
 void display(int key)
 {
     Node * res = search(key);
     if(res == NULL)
        cout << "not found " << endl;
     else
        cout <<key << endl ;
 }
  void displayAll()
 {
     Node * pNode ;
     pNode = pStart ;
     while(pStart)
     {
         cout << pNode ->key << endl ;
          pNode = pNode->next;
     }
 }
 void deleteNode  ( int key)
 {
     Node * pNode  = search(key );
     if(pNode == NULL)
     {
         cout << "not found" << endl ;
     }

     else{
        if(pLast == pStart)
        {
            pStart = pLast = NULL;
        }
        else if  (pNode == pStart)
        {
            pStart = pStart ->next ;
            pStart->prev = NULL ;
        }
        else if (pLast == pNode)
        {
            pLast =   pLast -> prev ;
            pLast->prev = NULL ;
        }
        else
        {
          pNode -> prev -> next = pNode -> next ;
          pNode -> next -> prev = pNode -> prev ;
        }

     }
     delete pNode ;
 }
 void insertNode (int key)
 {
     Node * pNode = newNode(key);

     if(pStart == NULL)
        pStart = pLast = pNode ;
     else
     {
            Node * pSearch = pStart ;
            while(pSearch && pSearch->key < pNode->key)
            pSearch = pSearch->next ;


            if(pSearch == pStart )
            {

               // cout<<"1" << endl;
                pNode->next =pStart ;
                pNode->prev = pNode ;
                pStart = pNode ;
            }
            else if (pSearch == NULL)
            {
                 // cout<<"2x" << endl;
                 pNode->prev = pLast;
                 pLast->next = pNode ;
                 pLast = pNode ;
            }
            else
            {
               //   cout<<"3" << endl;
                pNode->prev = pSearch ->prev ;
                pNode->next = pSearch ;
                pNode->prev ->next = pNode ;
                pSearch->prev = pNode;
            }

     }
 }
 Node * searchSorted (int key )
 {
     Node *  pSearch = pStart ;

     while (pSearch &&   pSearch->key <= key)
     {
         //  cout<<"xxxx>>" << pSearch->key << endl;
         if(key == pSearch -> key)
            return  pSearch ;
         pSearch = pSearch->next;
     }
     return NULL ;
 }
int main()
{
Node * n = new Node;
Node * s;
insertNode(2);
insertNode(3);
insertNode(5);
insertNode(0);
insertNode(6);
insertNode(7);
s = searchSorted(7);
if(s)
cout<< s->key;
else
    cout << "not found " << endl;

    displayAll();
    return 0;
}
