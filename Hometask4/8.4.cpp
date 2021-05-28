#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void output(int m, const vector<int>& a, const vector<int>& b)
{
    if (m < 0) return;
    if (b[m] == a[m] + b[m-1]) output(m-1,a,b);
    else output(m-2,a,b);
    cout << m+1 << " ";
}

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> b(N);
    for(int i = 0; i < N; ++i)
        cin >> a[i];

    b[0] = a[0];
    b[1] = max(a[1],a[0]+a[1]);
    for(int i = 2; i < N; ++i)
        b[i] = a[i] + max(b[i-1],b[i-2]);

    cout << b[N-1] << endl;
    output(N-1,a,b);
    cout << endl;
}
