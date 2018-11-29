#include <iostream>

using namespace std;
void SWAP(int& x ,int& y  )
{
    int temp = x ;
    x = y ;
    y=temp;
}
int  indexOfMinValue(int * Arr , int first , int last)
{
    int index = first ;
    for (int i = first+1 ; i<last ; i++)
        if(Arr[i] <Arr[index])
            index = i ;

    return index ;
}
void selectionSort(int * Arr , int Size)
{
    int index = 0 ;
    for(int j =0 ; j<Size ; j++)
    {
         index = indexOfMinValue(Arr , j, Size);

        SWAP(Arr[j] , Arr[index]);
    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
