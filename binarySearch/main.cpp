#include <iostream>

using namespace std;
/*int BSearch(int  * arr , int first , int last , int key)
{
    cout << "ssss" << endl ;
    if(first <= last)
    {
        int mid = (first +last ) /2 ;
        if(key > arr[mid])
               return  BSearch(arr , mid+1 , last , key );
        else  if(key < arr[mid])
            return  BSearch(arr ,first, mid-1, key );
        else
            return mid;
    }
    return - 1 ;
}*/
int BSearch(int  * arr , int first , int last , int key)
{
     int mid = (first +last ) /2 ;
     if(arr[mid] == key)
        return mid;
    while (first <= last)
    {
      mid = (first +last ) /2 ;
      if(key > arr[mid])
      {
        first = mid+1 ;
      }
       else  if(key < arr[mid])
          last =  mid-1;
       else
            return mid ;
    }

    return -1 ;
}
int main()
{
    int arr[8] = {1,2,3,5,6,6,7,9};
     cout << BSearch(arr ,0, 7 , 5) ;



    return 0;
}
