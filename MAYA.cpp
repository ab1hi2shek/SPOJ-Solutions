/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date -	14/09/2017
	Logic -	AdHoc
	Category - very Easy
	Platform - SPOJ
*/	  

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

ll arr[9] = {1,20,360,7200,144000,2880000,57600000,1152000000,23040000000};
 
int main()
{
	std::ios::sync_with_stdio(false);
	//ll n;
	while(1)
	{
		ll n;
		cin>>n;

		if(n==0)
			break;
		ll ans = 0;

		for(ll i=0;i<n;i++)
		{
			string s;
			cin>>s;

			ll num = 0;
			if(s[0] =='S')
				num = 0;
			else
			{
				ll a=0,b=0;
				for(ll i=0;i<s.size();i++)
				{
					if(s[i]=='.')	a++;
					else	b++;
				}
				num = 5*b + a;
				//cout<<num<<endl;
			}

			ans += (num * arr[n-i-1]);
		}
		cout<<ans<<endl;
	}
}