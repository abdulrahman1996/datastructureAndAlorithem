#include <iostream>
#include <stdlib.h>

using namespace std;



struct Node
{
    int code ;
    Node * pLeft ;
    Node * pRight ;
};

Node * pTree = NULL ;

/*
this function allocate new struct in heap memory
*/
Node * AllocNode()
{
    Node * pRoot = new Node ;
    if(!pRoot)
        exit(0);
    pRoot->pLeft  = pRoot ->pRight = NULL ;
    cout << "enter the key" << endl ;
    cin >> pRoot->code ;

    return pRoot ;
}
/*
insert new node to tree
method 1
*/
void insetNode(Node *& pRoot , Node * pNew)
{
    if(!pRoot)
        pRoot = pNew ;
    else if (pNew ->code < pRoot->code)
        insetNode(pRoot->pLeft , pNew);
    else
        insetNode(pRoot->pRight , pNew);
}
/*
insert new node to tree
method 2
*/
void insetNode(Node *&pRoot ,Node *pLeaf ,  Node * pNew)
{
    if(!pLeaf)
        if(pRoot)
            if(pRoot->code > pNew->code)
                pRoot->pLeft = pNew ;
            else
                pRoot->pRight = pNew ;
         else
                pTree = pNew;
    else if (pLeaf->code > pNew ->code)
        insetNode(pLeaf , pLeaf->pLeft , pNew);
    else
        insetNode(pLeaf , pLeaf->pRight , pNew);

}
void TreeTravarse(Node * pRoot)
{
    if(pRoot)
    {
          cout  << pRoot->code << " " ;
        TreeTravarse(pRoot->pLeft);

        TreeTravarse(pRoot->pRight);
    }
}

int countTree(Node * pRoot)
{
    if(pRoot)
    {
        return countTree(pRoot->pLeft) + 1 + countTree(pRoot->pRight);

    }
    return 0 ;
}
Node * Search(Node * pRoot , int key)
{
    if(!pRoot || pRoot->code == key)
        return pRoot ;
    else if (key > pRoot->code   )
        return Search(pRoot->pRight , key);
    else
        return Search(pRoot->pLeft , key);


}
void RemoveNode(Node *& pRoot);
void DeleteNode(Node * & pRoot , int key)
{
  if(pRoot)
   {
        if(pRoot->code > key)
            DeleteNode(pRoot->pLeft , key);
        else if (pRoot ->code < key)
            DeleteNode(pRoot->pRight , key);
        else
            RemoveNode (pRoot);
   }
}
int GetMax(Node * pRoot);
void RemoveNode(Node *& pRoot)
{
    Node * temp = pRoot ;

    if (!pRoot->pLeft)
    {
        pRoot = pRoot->pRight  ;
        delete temp ;
    }
    else if (!pRoot->pRight)
    {
        pRoot = pRoot->pLeft  ;
        delete temp ;
    }
    else
    {
        int Max = GetMax(pRoot->pLeft);
        pRoot->code = Max ;
        delete temp ;

    }
}
int GetMax(Node * pRoot)
{
    while ( pRoot->pRight)
        pRoot = pRoot->pRight;

    return pRoot->code ;

}

void storeBSTNodes(Node* root, int* nodes , int index)
{
    // Base case
    if (root==NULL)
        return;

    // Store nodes in Inorder (which is sorted
    // order for BST)
    storeBSTNodes(root->pLeft, nodes , index+1);
    nodes[index] = root->code;
    storeBSTNodes(root->pRight, nodes , index+1);
}
Node* buildTreeUtil(int * nodes, int start,int end)
{

    if (start > end)
        return NULL;


    int mid = (start + end)/2;
    Node *root  = new Node ;
   root->code =  nodes[mid];


    root->pLeft  = buildTreeUtil(nodes, start, mid-1);
    root->pRight = buildTreeUtil(nodes, mid+1, end);

    return root;
}
Node* buildTree(Node* root)
{

    int  * nodes = new int [10];
    storeBSTNodes(root, nodes , 0);


    return buildTreeUtil(nodes, 0,9);
}
int main()
{

    for(int i =0 ; i<10 ; i++)
        insetNode(pTree , pTree , AllocNode());

  //  TreeTravarse(pTree);


    cout << countTree(pTree) << endl;

    Node *pSearch = Search(pTree , 9);

    pSearch ? cout << " Found"  << endl: cout << "not found" << endl ;

    /*for(int i =0 ; i<6 ; i++)
    {
        TreeTravarse(pTree);
        DeleteNode(pTree , i+1);
        cout << "new root is " << pTree->code << endl;
    }

   // int * x = new int[6];
   // storeBSTNodes (pTree , x , 0);

    */

      Node * c =  buildTree(pTree);

     Node * r  = c->pRight;




      TreeTravarse(r);cout<<endl;
        r = c->pLeft;
      TreeTravarse(r);cout<<endl;







    return 0;
}
