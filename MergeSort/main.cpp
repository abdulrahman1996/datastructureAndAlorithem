#include <iostream>

using namespace std;
int callFun =0  ;

void Merge(int * Arr, int lFirst,  int lLast, int rFirst, int rLast)
{
    int arrSize = rLast - lFirst +1;
  //  cout << "arr size is :" << arrSize << endl;
    int *temaArr = new int [arrSize];
    int index = 0, safeIndex = lFirst;
    while((lFirst <= lLast ) && (rFirst <=rLast))
        if(Arr[lFirst] < Arr[rFirst])
            temaArr[(index++) ] = Arr[lFirst++];
        else
            temaArr[(index++)  ] = Arr[rFirst++];



    while(lFirst<= lLast)
        temaArr[(index++)] = Arr[lFirst++];

    while(rFirst<= rLast)
        temaArr[(index++) ] = Arr[rFirst++];



        for(int i = safeIndex ; i<=rLast; i++)
            Arr[i] = temaArr[i-safeIndex];





}
void MergeSort(int * Arr, int F, int L  )
{

 for(int i = 0 ; i< 11; i++)
           cout << Arr[i] << " " ;

    cout << endl ;

   // cout << "call number" << callFun << endl ;
    //callFun ++ ;
    if (F<L)
    {
        int m = (F +L) / 2 ;

        MergeSort(Arr, F, m);
        MergeSort(Arr, m+1, L);
        Merge(Arr, F, m, m+1, L);
    }
}
int main()
{
    int unSortedArray[] = {2, 8, 1, 99, 63, 2, 3, 0, 78, 10, 8};
    MergeSort(unSortedArray, 0, 10);


      for(int i = 0 ; i<11; i++)
           cout<< " " << unSortedArray[i] ;

    return 0;
}
