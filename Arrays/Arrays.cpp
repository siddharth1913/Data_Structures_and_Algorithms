#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
//====================================================================
void ReverseInteger(){
    int num;
    cout<< "\nEnter the number : ";
    cin >> num;
    int original_Num = num;
    int reverse_Num = 0;
    int rem;

    while(num > 0){
        rem = num % 10;
        reverse_Num = reverse_Num * 10 + rem;
        num = num / 10;
    }

    cout << "Reverse of " << original_Num << " is " << reverse_Num << endl;
}

//====================================================================
// XOR = n ^ 0 => n (n!=0)  and n ^ n = 0
void SingleNumber(){
    int size;
    int result = 0;
    cout<< "Enter size of an array : ";
    cin >> size;
    if(size%2==0){
        cout<< "Array size should be odd number, please re-enter it\n";
    }

    cout<< "Enter size of an array : ";
    cin >> size;

    vector<int> number(size);
    cout<< "Enter value in array : ";
    for (int i = 0; i < size ; i++){
        cin >> number[i];
    }

    for(int num : number){
        result  = result ^ num;
    }

    cout << "Unique element in given array : " << result << endl;

}
//====================================================================
string ReverseVowels() {

    string s;
    cout<< "Enter the string : ";
    cin >> s;

    int i = 0;
    int j = s.size()-1;
    while(i < j){
        if( (s[i] == 'a' || s[i] == 'A' || s[i]== 'e' || s[i] == 'E' || s[i] == 'i' 
        || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U' )  
        && ( s[j] == 'a' || s[j] == 'A' || s[j] == 'e' || s[j] == 'E' || s[j] == 'i' 
        || s[j] == 'I' || s[j] == 'o' || s[j] == 'O' || s[j] == 'u' || s[j] == 'U' ) )
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }  
        else if( !(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' 
        || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U' ))
        {
            i++;
        }
        else if( !(s[j] == 'a' || s[j] == 'A' || s[j] == 'e' || s[j] == 'E' || s[j] == 'i' 
        || s[j] == 'I' || s[j] == 'o' || s[j] == 'O' || s[j] == 'u' || s[j] == 'U' ) )
        {
            j--;
        }
    }
    cout << "Reverse Vowel string : " << s << endl;

}

//====================================================================


void FindMaxAverage() {
    int n;
    int k;
    cout<<"Enter Size : ";
    cin >> n;
    cout<<"Enter Window Size : ";
    cin >> k;

    vector<int> nums(n);
    cout<<"\nEnter Array elements : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int left = 0;
    int right = left+k-1;
    double maxAvg = 0;
    double currentSum = 0;
    for(int i=0 ; i < k; i++){
        currentSum += nums[i];
    }
    maxAvg = currentSum;
    for(int i = k; i < nums.size(); i++){
        currentSum = currentSum + nums[i] - nums[i-k];
        if(currentSum >= maxAvg){
            maxAvg = currentSum;
        }
    }
    cout << "Maximum average of subarray : "<< maxAvg/k;
}

void MaxFrequency() {
    int n;
    int k;
    cout<<"Enter Size : ";
    cin >> n;
    cout<<"Enter number of operations to perform : ";
    cin >> k;

    vector<int> nums(n);
    cout<<"\nEnter Array elements : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    std::sort(nums.begin(), nums.end());
        
    long currentSum = 0;
    int left = 0;
    int maxFrequency = 0;
    for(int right = 0; right < nums.size(); right++){
        currentSum += nums[right];
        long cost = (long)nums[right] * (right-left + 1) - currentSum;
        while(cost > k){
            currentSum -= nums[left];
            left++;
            cost = (long)nums[right] * (right-left+1) - currentSum;
        }
        maxFrequency = max(maxFrequency,(right-left+1));
    }
    cout << "Maximum average of subarray : "<< maxFrequency;
    
}

int main(){
    cout <<"\n======= Welcome to Array problems =======" << endl;
    int choice;
    char continueChoice;

    do {
        cout << "\n--------Choose what to perform---------\n";
        cout << "=========================================" << endl;
        cout << "1.[ 7. Reverse Integer] \n2.[ 136. Single Number - Bitwise_Xor] \n3.[ 345. Reverse Vowels in a string]\n4.[ 643. Maximum Average Subarray I]\n5.[ 1838. Frequency of the Most Frequent Element]\n6.X \n7.Exit\n";
        cout << "=========================================" << endl;
        cout << "\nYou choose option number = ";
        
        cin >> choice;

        switch (choice){
            case 1: 
                ReverseInteger();
                break;
            case 2: 
                SingleNumber();
                break;
            case 3: 
                ReverseVowels();
                break;
            case 4:
                FindMaxAverage();
                break;
            case 5:
                MaxFrequency();
                break;
            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid Option! Please try again." << endl;
        }

       cout << "\nDo you want to go back to the main menu? (y/n) : ";
       cin >> continueChoice;  

    } while (continueChoice == 'y' || continueChoice == 'Y');

    cout << "Exiting the program. Goodbye!" << endl;
    return 0;

}
