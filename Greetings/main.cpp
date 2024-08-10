#include <bits/stdc++.h>
#include <cstring>
using namespace std;


string MemeberName; // A variable to store the name of the member.
void countName(string NameToCount); // First function to count how many characters in the name.
void Greetings(string name); // Second function to greet the member.



int main()
{
    cout << "Enter a Memeber Name" << endl;
    getline(cin , MemeberName); // Taking the name of the member.
    countName(MemeberName);  // Calling First fucntion.
    return 0;
}



void countName(string NameToCount)
{
    int count=0; // Variable to count how many characters in the name.
    count= NameToCount.length();

    if( (count <= 1) || (count > 100) ) // if the characters in the member's name less than or equal 1 or more than 100, will give an error.
    {
        cout << "Invalid name\nMemeber name should be less than or equal 100 characters and more than 1 character" << endl;
    }
    else{
        Greetings(NameToCount);

    }
}
void Greetings(string name)
{
    cout <<"Hello" << ", "<< name << "!" << endl;
}
