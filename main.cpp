#include <iostream>
#include <cstdio>
#include<cmath>
using namespace std;
int board[10],n,count;
int main()
{
    int n,i,j;
    void queen(int row,int n);
    cin>>n;
    queen(1,n);
    return 0;
}
int print(int n)
{
    int i,j;
    cout<<"\nSolution:"<<endl;
    for(i=1;i<=n;i++)
        printf("\t%d",i);
    for(i=1;i<=n;i++)
    {
        printf("\n\n%d\n\n",i);
        for(j=1;j<=n;j++)
        {
            if(board[i]==j)
                printf("\tQ");
            else printf("\t-");
        }
    }
}
int place(int row,int column)
{
    int i;
    for(i=1;i<=row-1;++i)
    {
        if(board[i]==column)
            return 0;
        else{
            if(abs(board[i]-column)==abs(i-row))
                return 0;
        }
    }
    return 1;

}
int queen(int row,int n)
{
    int column;
    for(column=1;column<=n;++column)
    {
        if(place(row,column))
        {
           board[row]=column;
           if(row==n)
                print(n);
           else
            queen(row+1,n);
        }
    }
}
