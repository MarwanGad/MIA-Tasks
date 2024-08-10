#include <bits/stdc++.h>
#include <cstring>
#define MAX 100000
using namespace std;

int n;
int arr[MAX];
int Target;

int main()
{
    int index=0;
    int flag=0; // flag=0 target not found, flag=1 target found

    cout << "Enter how many elements in the array" << "\n" << "-->";
    cin >> n;
    if(n > MAX || n < 1)
    {
        cout << "Invalid number of elements must be less than or equal 100000";
    }
    else
    {
        for (index = 0; index < n; index++)
            {
                cin >> arr[index];
            }

            cout << "Enter the number you are searching for" <<  "\n" << "-->"; //Getting the target number
            cin >> Target;

            for (index = 0; index < n; index++) // checking if the desired number is found or not
                {
                    if(arr[index] == Target)
                    {
                        flag=1;
                        break;
                    }
                }

            if(flag==1)
            {
                cout << index;
            }
            else
            {
                cout << -1;
            }
    }

    return 0;
}
