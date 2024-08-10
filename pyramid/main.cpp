#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int n; // height of the pyramid (rows)
int k; // coloumns

int main()
{
    cout << "Enter how many rows you want : " << endl; 
    cin >> n; 
    if( (n < 1) || (n > 100))
    {
        cout << "Invalid height,\nmust be more than or equal to 1 and less than or equal to 100";
    }
    else
    {
        int i=0; // to loop on the rows.
        int j=0; // to loop on the columns.
        for( i = 0 ; i < n ; i++)
        {
            for (k = 0; k < i+1; k++)
            {
                cout << "*";
            }
            cout << "\n";
        }      
    }

    return 0;
}
