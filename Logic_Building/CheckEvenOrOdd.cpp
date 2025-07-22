#include <iostream>
using namespace std;

/* [Naive Approach] By Finding the Remainder - O(1) Time and O(1) Space */
void findByReminder(int n){

    if(n%2 == 0){
        cout<<"\nNumber is even"<<endl;
    }else{
        cout<<"\nNumber is odd"<<endl;
    }   
} 

/* [Efficient Approach] Using Bitwise AND Operator - O(1) Time and O(1) Space */
/* The last bit of all odd numbers is always 1, while for even numbers it’s 0. 
So, when performing bitwise AND operation with 1, odd numbers give 1, 
and even numbers give 0. */
bool usingBitwise_AND_Operator(int n){  
    if( n & 1){
        cout<<"\nNumber is odd"<<endl;
    }else{
        cout<<"\nNumber is even"<<endl;
    }
}


int main (){
    int num, option;
    cout<<"Take input : ";
    cin >> num;

    while (true) {
        cout << "\nChoose method to perform \n1.Remainder\n2.Bitwise\n3.Exit\n";
        cout << "You choose option number = ";
        cin >> option;

    switch(option){
        case 1: 
            findByReminder(num);
            break;
        case 2: 
            usingBitwise_AND_Operator(num);
            break;
        default:
            cout << "Invalid Option! Exiting..." << endl;
            return 0;
        }
    }
    return 0;
}