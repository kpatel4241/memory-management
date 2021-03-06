//
// Created by KP on 18-03-2019.
//

#include<bits/stdc++.h>

using namespace std;

void worst_fit(int block_size[] , int m , int requested_size[] , int n)
{
    int allocation[n],worst_block,i,j;

    memset(allocation,-1,sizeof(allocation));

    for(i=0;i<n;i++)
    {
        worst_block = -1;
        for(j=0;j<m;j++)
        {
            if(block_size[j] >= requested_size[i])
            {
                if(worst_block == -1)
                    worst_block = j;
                else if(block_size[worst_block] < block_size[j])
                    worst_block = j;
            }
        }

        if(worst_block != -1)
        {
            allocation[i] = worst_block;
            block_size[worst_block] -= requested_size[i];
        }
    }

    cout<<"\n Process No. \tRequested Size \tBlock No.\n";
    for(i=0;i<n;i++)
    {
        cout<<" "<<i+1<<"\t\t"<<requested_size[i]<<"\t\t";
        if(allocation[i] != -1)
            cout<<allocation[i]+1;
        else
            cout<<"Not Allocated";
        cout<<endl;
    }
}


/*
int main()
{
    int i,n,m;
    cout<<"\n Enter the no. of block_sizes : ";
    cin>>m;

    int block_size[m];
    cout<<"\n Enter the Block Sizes : ";
    for(i=0;i<m;i++)
        cin>>block_size[i];

    cout<<"\n Block Size : ";
    for(auto i=0;i<m;i++)
        cout<<block_size[i]<<" ";
    cout<<endl;

    cout<<"\n Enter the no. of requested_size : ";
    cin>>n;

    int request_size[n];
    cout<<"\n Enter the Array of Block Size : ";
    for(i=0;i<n;i++)
        cin>>request_size[i];

    first_fit(block_size,m,request_size,n);

    return 0;
}
*/



int main()
{
    int block_size[] = {100, 500, 200, 300, 600};
    int requested_size[] = {212, 417, 112, 426};
    int m = sizeof(block_size)/sizeof(block_size[0]);
    int n = sizeof(requested_size)/ sizeof(requested_size[0]);

    cout<<"\n Block Size : ";
    for(auto i=0;i<m;i++)
        cout<<block_size[i]<<" ";
    cout<<endl;

    worst_fit(block_size , m , requested_size , n);

    return 0;
}