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

ll findGCD(ll a, ll b)
{
	if(b==0)
		return a;
	else
		return findGCD(b, a%b);
}

ll pour(int c, int x, int y)
{
	ll a = 0, b = 0, count = 0;
	while( a != c && b!=c )
	{
		if(a==0)
			a = x;
		else if(b==y)
			b = 0;
		else
		{
			ll temp = y-b;
			if(temp >= a)
			{
				b += a;
				a = 0;
			}
			else
			{
				b += temp;
				a -= temp;
			}
		}
		count++;
	}

	return count;
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		ll a,b,c;
		cin>>a>>b>>c;

		ll gcd = findGCD(max(a,b), min(a,b));

		if(c % gcd !=0 || c > max(a,b))
		{
			cout<<"-1"<<endl;
			continue;
		}

		cout<<min(pour(c,a,b), pour(c,b,a))<<endl;
	}
	return 0;
}