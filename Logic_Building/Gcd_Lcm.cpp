#include<iostream>

using namespace std;

//Using Loop - O(min(a, b)) Time and O(1) Space
//The idea is to find the minimum of the two numbers and find its highest factor which is also a factor of the other number. 
int GcdUsingLoop(int num1, int num2){
    int result = min(num1,num2);
    
    while(result > 0){
        if(num1 % result == 0 && num2 % result == 0){
            break;
        }
        result--;
    }
    return result;
    
}

//[Approach - 2] Euclidean Algorithm using Subtraction - O(min(a,b)) Time and O(min(a,b)) Space
int GcdUsingSubtraction(int num1, int num2){
    if (num1 == 0)
        return num2;
    if(num2 == 0)
        return num1;
    
    if( num1 == num2){
        return num1;
    }

    if(num1 > num2)
        GcdUsingSubtraction(num1-num2, num2);
    else
        GcdUsingSubtraction(num1, num2-num1);
}

int LcmUsingLoop(int num1, int num2){
    int smaller = min(num1,num2);
    int greater = max(num1, num2);

    for(int i = greater ; i < num1 * num2 ; i = i + greater){
        if((i % smaller) == 0){
            return i;
        }
    }
}

int LcmUsingGcd(int num1, int num2){
    int gcd = GcdUsingLoop(num1, num2);

    int product = num1 * num2;

    return product/gcd;
}

int main (){
    int num1, num2;
    cout<< "Enter numbers : ";
    cin>> num1 >> num2 ;
    int option ;

    while(true){
        cout<< "1. GCD (Approach-1)\n2. GCD (Approach-2) \n3. LCM\n4. LCM using GCD\n5. Exit\n";
        cout<< " You choose : ";
        cin>>option ;

        switch(option){
            case 1:
                cout<< "\nGCD of "<< num1 <<" and "<< num2 <<" using GcdUsingLoop is "<< GcdUsingLoop(num1,num2)<< endl;
                break;
            case 2:
                cout<< "\nGCD of "<< num1 <<" and "<< num2 <<" using GcdUsingSubtraction is "<< GcdUsingSubtraction(num1,num2)<<endl;
                break;
            case 3:
                cout<< "\nLCM of "<< num1 <<" and "<< num2 <<" using GcdUsingLoop is "<< LcmUsingLoop(num1,num2)<<endl;
                break;
            case 4:
                cout<< "\nLCM of "<< num1 <<" and "<< num2 <<" using LcmUsingGcd is "<< LcmUsingGcd(num1,num2)<<endl;
                break;
            default:
                cout << "\nInvalid Option! Exiting... \n" << endl;
                return 0;   
            
        }
    }

}