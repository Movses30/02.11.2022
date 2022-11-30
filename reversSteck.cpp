#include <stack>
#include <iostream>
using std::stack;    
int main (){
stack< int > numbers;
numbers.push( 1 );
numbers.push( 2 );

while (!numbers.empty( ) )
{
    int number = numbers.top( );
    numbers.pop( );
    std::cout << number <<"\t";
}
}