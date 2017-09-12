#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll long long int
#define ull unsigned long long int
#define l long int
#define ul unsigned long int
 
//stl
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef map<ll,ll> mpll;
#define sz(a) (a).size()
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
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll n;
	cin>>n;

	ll arr[n];
	for(ll i=0; i<n; i++)
		cin>>arr[i];
	ll k;
	cin>>k;

	deque<ll> Q;

	for(int i=0; i<k; i++)
	{
		while(!Q.empty() && arr[i] >= arr[Q.back()])
			Q.pop_back();
		Q.push_back(i);
	}

	for(ll i= k; i< n; i++)
	{
		cout<<arr[Q.front()]<<" ";

		while(!Q.empty() && Q.front() <= i-k)
			Q.pop_front();
		while(!Q.empty() && arr[i] >= arr[Q.back()])
			Q.pop_back();
		Q.push_back(i);
	}
	cout<<arr[Q.front()]<<endl;
	return 0;
}