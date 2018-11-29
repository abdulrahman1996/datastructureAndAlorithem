#include <iostream>

using namespace std;

void SWAP(int& x ,int& y  )
{
    int temp = x ;
    x = y ;
    y=temp;
}

void BSort(int * Arr , int Size)
{
    int flag =  1 ;
  for( int i  =0 ; i<Size&& flag ==1  ; i++)
  {
        flag = 0 ;

    for (int j = 0 ; j<Size-i-1 ; j++ )
    if(Arr[j]>Arr[j+1])
    {
     SWAP(Arr[j] , Arr[j+1]);
     flag = 1 ;
    }
  }

}

int main()
{

    cout << "Hello world!" << endl;
    return 0;
}
