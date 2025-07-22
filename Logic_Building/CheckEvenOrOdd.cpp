#include <iostream>
using namespace std;

/* [Naive Approach] By Finding the Remainder - O(1) Time and O(1) Space */
void findByReminder(int n){

    if(n%2 == 0){
        cout<<"Number is even"<<endl;
    }else{
        cout<<"Number is odd"<<endl;
    }   
} 

/* [Efficient Approach] Using Bitwise AND Operator - O(1) Time and O(1) Space */
/* The last bit of all odd numbers is always 1, while for even numbers it’s 0. 
So, when performing bitwise AND operation with 1, odd numbers give 1, 
and even numbers give 0. */
bool usingBitwise_AND_Operator(int n){  
    if( n & 1){
        cout<<"Number is odd"<<endl;
    }else{
        cout<<"Number is even"<<endl;
    }
}


int main (){
    int num, option;
    cout<<"Take input : ";
    cin >> num;

    cout<<"Choose method to perfom : ";
    cin>> option;

    switch(option){
        case 1: 
            findByReminder(num);
            break;
        case 2: 
            usingBitwise_AND_Operator(num);
            break;
        deafult:
            cout<<"Invalid Option"<<endl;
            break;
    }
    
}