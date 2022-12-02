#include <bits/stdc++.h>
#include<math.h>
 
int thirdLargest(int arr[], int arr_size)
{   int cout=3;
    int max = *std::max_element(arr, arr + arr_size);
    for (int i =0;i < arr_size;i++)
    {
        if (max == arr[i]&& cout !=0)
        {
           arr[i]=0;
            max = *std::max_element(arr, arr + arr_size);
            cout--;
        } 
    }
  std::cout << max <<std::endl;
  return max;
}
 
int main()
{
    int arr[] = {12, 13, 1, 10, 34, 16};
    int n = sizeof(arr)/sizeof(arr[0]);
    //std::cout << *std::max_element(arr, arr + n);

    thirdLargest(arr, n);
    return 0;
}