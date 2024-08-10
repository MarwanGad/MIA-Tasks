#include <bits/stdc++.h>
#include <cstring>
#define MAX 100
using namespace std;

int r; // rows
int c; // columns
int JusticePower[MAX][MAX];
int VillianPower[MAX][MAX];


void FillGrid(int r , int c);
void GetTheWinner(int r , int c);

int main()
{ 
    cout << "Enter rows and columns" << endl;  
    cin >> r >> c;
    
    FillGrid(r,c);

    return 0;
}

void FillGrid(int r , int c)
{
    int i=0;  
    int j=0;  
    cout << "Fill justice's grid: ";
    for(i = 0 ; i < r ; i++)
    {
        for (j = 0; j < c; j++)
        {
            cin >> JusticePower[i][j];
            
        }
        
    }
    cout << "\n" << "Fill Villian's grid";
    for(i = 0 ; i < r ; i++)
        {
            for (j = 0; j < c; j++)
            {
                cin >> VillianPower[i][j];
                
            }
            
        }
    GetTheWinner(r,c);
}

void GetTheWinner(int r , int c)
{
    int i=0;  
    int j=0; 
    int JusticeScore=0;
    int VillianScore=0;
    for(i = 0 ; i < r ; i++)
        {
            for (j = 0; j < c; j++)
            {
               if(JusticePower[i][j] > VillianPower[i][j])
               {
                    JusticeScore+=1;
               }
               else if(JusticePower[i][j] < VillianPower[i][j])
               {
                    VillianScore+=1;
               }
                
            }
            
        }
    if(JusticeScore > VillianScore)
    {
        cout << "Justice League";
    }
    else if(JusticeScore < VillianScore )
    {
        cout << "Villains";
    }
    else
    {
        cout << "Tie";
    }
}
