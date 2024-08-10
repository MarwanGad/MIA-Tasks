#include <bits/stdc++.h>
#include <cstring>
#define MAX_MEASURMENTS 100000 // Max number of heights to be measured.
#define MAX_HEIGHT 1000000000 // Max height to be measured.
using namespace std;

int Heights[MAX_MEASURMENTS]; // Array to store the measured heights.
int n; // variable to store the number of heights measured.

int StoreHeights(int NumberOfHeights); // First funciton to store the measured heights.
int FindMaxHeight(int HeightsMeasured[MAX_MEASURMENTS], int MeasuredHeights); // Second function to find the maximum measured height.

int main()
{
    int MaxHeight=0; // variable used to store the max height returned from second fucntion at the end of the program.
    cout << "Enter number of height measurments" << "\n" << "-->";
    cin >> n;
    if( (n > MAX_MEASURMENTS) || (n < 1)) // checking if number of measured heights valid or not according to the Constraints 
    {
        cout << "Invalid number of heights!";
    }
    else
    {
        MaxHeight = StoreHeights(n); // calling the first function, passing it the number of measured heights to start storing the actual heights.
    }
    cout << Heights[0];
    cout << "Max height is" << " " << MaxHeight;

    return 0;
}

int StoreHeights(int NumberOfHeights)
{
    int index=0;

    for(index = 0 ; index < NumberOfHeights ; index++) // storing the actual heights
    {
        cin >> Heights[index];
        if( ( Heights[index] < 0 ) || ( Heights[index] > MAX_HEIGHT )) // checking if measured height is valid or not according to the constraints.
        {
            while(( Heights[index] < 0 ) || ( Heights[index] > MAX_HEIGHT )) // if not valid height, will keep asking for a valid one to store
            {
                cout << "Invalid Height!\nMust be more than or equal 0 and less than or equal 10 power 9\nEnter another height: ";
                cin >> Heights[index];
            }
            
        }
    }
    return FindMaxHeight(Heights,NumberOfHeights); // calling the second function, passing it the heights measured and the number of measured heights.
}

int FindMaxHeight(int HeightsMeasured[MAX_MEASURMENTS], int MeasuredHeights)
{
    int index=0;
    int MaxHeight=HeightsMeasured[0]; //Assume first element is the max height
    for (index = 0; index < MeasuredHeights; index++) // looping on the measured heights to find the max height of all.
    {
        if(MaxHeight < HeightsMeasured[index])
        {
            MaxHeight=HeightsMeasured[index];
        }
    }
    return MaxHeight; // returning the max height found.
}


