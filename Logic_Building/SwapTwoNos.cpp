#include<iostream>
using namespace std;

void Arithmatic_Operator(int a , int b){
    cout<<"Before swap : "<< a << " and " << b << endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout<<"After swap : "<< a << " and " << b << endl;
}

void Bitwise_Xor(int a, int b)
{
    cout<<"Before swap : "<< a << " and " << b << endl;
    a = a ^ b;
    b = a ^ b;
    a = b ^ a;
    cout<<"After swap : "<< a << " and " << b << endl;
}

void Third_Variable(int a, int b)
{ 
    cout<<"Before swap : "<< a << " and " << b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout<<"After swap : "<< a << " and " << b << endl;
}
void In_Built_Swap(int a, int b){
    cout<<"Before swap : "<< a << " and " << b << endl;
    swap(a,b);
    cout<<"After swap : "<< a << " and " << b << endl;
}

int main (){
    cout<<"\nSwap two numbers using multiple approaches\n"<<endl;
    int num1, num2, option;
    cout<<"Take input of two numbers : ";
    cin >> num1 >> num2;

    while (true) {
        cout << "\nChoose method to perform \n1.Arithmatic_Operator\n2.Bitwise_Xor\n3.Third_Variable\n4.In_Built_Swap\n5.Exit\n";
        cout << "\nYou choose option number = ";
        cin >> option;

    switch(option){
        case 1: 
            Arithmatic_Operator(num1, num2);
            break;
        case 2: 
            Bitwise_Xor(num1, num2);
            break;
        case 3: 
            Third_Variable(num1, num2);
            break;
        case 4: 
            In_Built_Swap(num1, num2);
            break;
        default:
            cout << "\nInvalid Option! Exiting... \n" << endl;
            return 0;
        }
    }
    return 0;
}