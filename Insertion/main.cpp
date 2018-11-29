#include <iostream>

using namespace std;

void SWAP(int& x,int& y  )
{
    int temp = x ;
    x = y ;
    y=temp;
}

void insertionSort(int * Arr, int Size)
{

    for(int i =  1 ; i<Size ; i++)
    {
        int refValue = Arr[i];
        for(int j = i-1 ; j<= 0 ; j++)
            if(Arr[j] > refValue)
                SWAP(Arr[j ], Arr[j+1])
                else
                    break ;
    }
}

int main()
{

    return 0;
}
