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

	ll a1 = 0, a2 = 0, a3 = 0;
	//ll ans = 1;

	while(n--)
	{
		string a;
		cin>>a;

		if(a=="1/2")
			a2++;
		else if(a=="1/4")
			a1++;
		else
			a3++;
	}

	ll ans=a3;
	a1=a1-a3;
	ans+=(a2-a2%2)/2;

	if(a2%2)
	{
    	ans++;
    	a1-=2;
	}

	if(a1 > 0) 
	{
		ans+=(a1-(a1%4))/4;
		if(a1%4>0) {
			ans++;
		}
	}

	cout<<ans+1<<endl;
	return 0;
}