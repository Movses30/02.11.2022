
#include <iostream>
#include <stack>
using namespace std;
template <class T>
 class Steck
{
private:
   int count = 0;
   T arr[5];
  
public :

T push(T a)
{
    int size = sizeof(arr)/ sizeof(arr[0]);
    if (count == size)
    {
       // cout << "===";
        T* array = new T [(size) *2];
        for (int i=0;i < (size) ;i++){
            array[i] = arr[i];
          //  cout << *(arr+i)<<"=\t=\n";

        }
        *arr = *array;
        
    }else{
  arr[count] = a;
  count ++;  
  return arr[count];
    }

}
T  pop()
{
      //  cout << "==77=";

    count --;
   return arr[count] ;
}
bool empty()
{
      return count == 0;

}
int size()
{   // cout << sizeof(arr)/sizeof(arr[0]);
    //cout << arr[4]<<"\n";
    return count;
}
T top()
{   
    return arr[count -1];
}

};
 int  main ()
{
    Steck<int> obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
cout << boolalpha << obj.empty() << "\n";
cout << obj.empty()<<"\tempty\n";
cout << obj.top()  << "\ttop\n";
cout << obj.size() <<"\tsize\n";
cout << obj.pop()  <<"\topo";

   // cout<< obj.top();
}

