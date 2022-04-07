#include <iostream>
#include <vector>
using namespace std;
long max(long a, long b)
{
    if (a>b)
        return a;
    else
        return b;
}
int main()
{
    long n,m;
    cin >> n >> m;
    vector < vector<long> > queries;
    vector <long> arr (n+1, 0);
    long a, b, k,res = 0;
    for (long i=0; i<m; i++)
    {
        cin >> a >> b >> k;
        arr[a-1] += k;
        arr[b] += -k;
    }
    long tmp = 0;
    for (int i=0; i<n; i++)
    {
        //cout << arr[i] << " ";
        tmp += arr[i];
        res = max(res, tmp);
    }
    cout << res;
    return 0;
}