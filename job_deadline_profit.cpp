#include<bits/stdc++.h>
using namespace std;

struct job{
    int id;
    int deadline;
    int profit;
};

void jobScheduling(vector<job>&v1)
{
    int cnt_job = 0;
    int maxProfit = 0;
    int n = v1.size();
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<n;i++)
    {
        auto it = v1[i];
        pq.push({it.profit,it.deadline});
    }

    vector<int>hash(n,0);
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        for(int i = it.second-1;i>=0;i--)
        {
            if(hash[i]==0)
            {
                cnt_job++;
                maxProfit+=it.first;
                hash[i]=1;
                break;
            }
        }
    }

    cout<<"Total number of jobs = "<<cnt_job<<endl;
    cout<<"Total Profit "<<maxProfit;
}

int main()
{   
    int n;
    vector<job>v1 = {{1,4,20},{2,1,10},{3,1,40},{4,1,30}};
    jobScheduling(v1);
    return 0;

}