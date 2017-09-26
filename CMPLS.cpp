/*
	CODE BY - ABHISHEK KUMAR
			  NIT DURGAPUR
*/

#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll int
#define ull unsigned long long
 
//stl
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef map<ll,ll> mpll;
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
 
//loops
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define loopr(i,a,b) for(ll i=a;i>=b;i--)
 
//others
#define isPowerOfTwo(S) !(S & (S - 1))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define nline cout<<endl
#define M0D 1000000007
#define MAXM 100005

void nextTermsInSequence(int sequence[], int N, int terms)
{
    int diff[N + terms];
    for (int i = 0; i < N; i++)
        diff[i] = sequence[i];
 
    bool more = false;
    vector<int> first;
    int len = N;
 
    while (len > 1)
    {
        first.push_back(diff[0]);
        len--;
        for (int i = 0; i < len; i++)
            diff[i] = diff[i + 1] - diff[i];
        int i;
        for (i = 1; i < len; i++)
            if (diff[i] != diff[i - 1])
                break;
        if (i != len)
           break;
    }
 
    int iteration = N - len;
    for (int i = len; i < len + terms; i++)
        diff[i] = diff[i - 1];
    len += terms;
 
    for (int i = 0; i < iteration; i++)
    {
        len++;
        for (int j = len - 1; j > 0; j--)
            diff[j] = diff[j - 1];
        diff[0] = first[first.size() - i - 1];
        for (int j = 1; j < len; j++)
            diff[j] = diff[j - 1] + diff[j];
    }
    for (int i = N; i < len; i++)
        cout << diff[i] << " ";
    cout << endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		ll n,c;
		cin>>n>>c;

		ll arr[n];
		loop(i,0,n-1)
			cin>>arr[i];
		nextTermsInSequence(arr, n, c);
	}
		
	return 0;
}