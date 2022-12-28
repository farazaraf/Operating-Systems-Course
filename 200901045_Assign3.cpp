//Faraz Ahmad Qureshi 200901045
//OS Assignment 
//Section B
//==============================|
#include <iostream>
#include <thread>
#include <cstdlib>
using namespace std;

void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;    //indexes that we use to denote left right and center
    int n1 = middle - left + 1; //name of sub arrays we use for combining
    int n2 =  right - middle;

    int L[n1], R[n2];   //declaring the sub arrays

    for (i = 0; i < n1; i++)    //copying values of the array from sub array to the combined array
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1+ j];

   i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)        //logic to decide whether to combine the index with left array or right array
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    this_thread::sleep_for (std::chrono::seconds(1));
    if (left < right)
    {
        int middle = left+(right-left)/2;
        
        thread leftSorter(mergeSort,arr,left,middle);
        thread rightSorter(mergeSort,arr,middle+1,right);

        cout << "< Left-sort-threadID: " << leftSorter.get_id();
        cout << endl;
        cout << "> Right-sort-threadID: " << rightSorter.get_id() ;

        leftSorter.join();
        rightSorter.join();
        merge(arr, left, middle, right);
        //
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

int main()
{
    int* array1;
    int arr_size;
    cout << "Number of cores on this system: 2\n";
    cout << "Enter size of array you want to sort: ";
    cin >> arr_size;
    array1 = new int[arr_size] ;
    for (int i = 0; i < arr_size; i++)
    {
        array1[i] = (rand()%100);
    }
    cout<<"Given array is \n";
    printArray(array1, arr_size);

    mergeSort(array1, 0, arr_size - 1);

    cout<<"\n==========\nSorted array is \n";
    printArray(array1, arr_size);
    return 0;
}
