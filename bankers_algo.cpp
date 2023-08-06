#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter no. of processes: ";
    cin>>n;
    cout<<"Enter no. of resources: ";
    cin>>m;
    int max[n][m];
    int alloc[n][m];
    int need[n][m];
    int r[m];
    int work[n];
    int finish[n];

    for(int i=0;i<m;i++)
    {
        int x;
        cout<<"Enter no. instance of resource "<<(i)<<": ";
        cin>>x;
        r[i]=x;
    }

    for(int i=0;i<n;i++)
        finish[i]=0;

    cout<<"Read Matrix Max: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int y;
            cin>>y;
            max[i][j]=y;
        }
        
    }   

    cout<<"Read Matrix Allocation: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int y;
            cin>>y;
            alloc[i][j]=y;
        }
        
    }   
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            need[i][j]=(max[i][j]-alloc[i][j]); 

cout<<"max array: ";
for(int i=0;i<n;i++)
{  
    for(int j=0;j<m;j++)
    {
        cout<<max[i][j];
    }
    cout<<endl;
}         

cout<<"alloc array: ";
for(int i=0;i<n;i++)
{   
    for(int j=0;j<m;j++)
    {
        cout<<alloc[i][j];
    } 
    cout<<endl;
}        

cout<<"need array: ";
for(int i=0;i<n;i++)
{    
    for(int j=0;j<m;j++)
    {
        cout<<need[i][j];
    }  
    cout<<endl;
}   

for(int i=0;i<m;i++)
    work[i]=r[i];

for(int i=0;i<n;i++)
{
    int flag=1;
    if(finish[i]==0)
    {
        for(int j=0;j<m;j++)
        {
            if(need[i][j]<=work[j])
                    continue;
            else
            {
                flag=0;
                break;
            }        
            
        }
        if(flag==1)
        {
            finish[i]=1;
            cout<<"P"<<i<<"->";
            for(int k=0;k<m;k++)
                work[k]+=alloc[i][k];
            i=-1;
        }    
    }

    else
        continue;
}
    cout<<endl<<"work matrix: ";
    for(int l=0;l<m;l++)
        cout<<work[l]<<",";
    cout<<endl;
    return 0;
}