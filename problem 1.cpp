#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/////////////////////////////////////////problem 2
void insertionsort (int arr[], int n)
{
    int key,j;
      for (int i = 1; i < n; i++)
      {
        key = arr[i];
        j = i-1;
         while( j >= 0 && arr[j] > key)
        {
           arr[j+1] = arr[j];
           j = j-1;
        }
        arr[j+1] = key;
      }
}
void findthreeNumbers(int arr[], int n, int sum)
{
    for (int i = 0; i < n - 2; i++)
    {
         for (int j = i + 1; j < n - 1; j++)
        {
             for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                {
                    cout << "three numbers for this sum are " << arr[i] <<
                        ", " << arr[j] << ", " << arr[k]<<endl;
                }
            }
        }
    }

}

int linearsearch (int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        return i;
    }
    return -1;
}

 int main()
{
    //input array
    int arr[] = { 8,6,2,7,4,0,9,5,1,3 };
    // get array size
    int n = sizeof(arr) / sizeof(arr[0]);
     // sort array
    insertionsort(arr,n);

    //search if number is found or not
    int num;
    cout << "enter your number";
    cin >> num;
    int res = linearsearch(arr,n,num);
    if (res == -1)
    {
      cout << "number is not found"<< endl;
    }
    else
        cout << "number is " << arr[res] << endl;

    int sum = num;
    findthreeNumbers(arr, n, sum);
    return 0;
}
