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
	ll P = 1;
	
	while(1)
	{
		ll n;
		cin>>n;

		if(n==0)
			break;

		ll a[n][3];
		for(ll i=0;i<n;i++)
			cin>>a[i][0]>>a[i][1]>>a[i][2];

		a[0][2] += a[0][1];
		a[1][0] += a[0][1];
		a[1][1] += min(a[1][0], min(a[0][1], a[0][2]));
		a[1][2] += min(a[1][1], min(a[0][1], a[0][2]));

		for(ll i=2;i<n;i++)
		{
			a[i][0] += min(a[i-1][0], a[i-1][1]);
			a[i][1] += min(a[i][0], min(a[i-1][0], min(a[i-1][1], a[i-1][2])));
			a[i][2] += min(a[i][1], min(a[i-1][1], a[i-1][2]));
		}

		// for(ll i=0;i<n;i++)
		// 	cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<endl; 

		cout<<P++<<". "<<a[n-1][1]<<endl;
		
	}
}