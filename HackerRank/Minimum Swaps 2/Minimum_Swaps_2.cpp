#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int res = 0;
    for (int i=0;i<arr.size();i++)
    {
        if (arr[i]==i+1)
            continue;
        
        swap(arr[i],arr[arr[i]-1]);
        res++;
        i--;
    }
    return res;
}


int main()
{
    long n;
    int x;
    cin >> n;
    vector <int> arr;
    for (long i=0; i<n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    cout << minimumSwaps(arr);
    return 0;
}