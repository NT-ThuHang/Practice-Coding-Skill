#include <iostream>
#include <vector>

using namespace std;

void minimumBribes(vector<int> q) 
{
    int total=0;
    for (int i = q.size()-1;i>=0;i--)
    {
        if (q[i]-i-1 > 2)
        {
            cout << "Too chaotic \n";
            return;
        }
        for (int j = max(0,q[i]-2); j<i ; j++)
        {
            if (q[j]>q[i])
                total++;
        }
    }
    cout << total << "\n";
}

int main()
{
    int t;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        int n,x;
        cin >> n;
        vector<int> q;
        for (int j=0; j<n;j++)
        {
            cin >> x;
            q.push_back(x);
        }
        minimumBribes(q); 
    }
    return 0;
}