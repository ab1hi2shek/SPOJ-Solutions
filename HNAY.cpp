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

void computeLps(ll lps[], string needle, ll n)
{
	lps[0] = 0;
	ll len = 0;
	ll j = 1;
	while(j<n)
	{
		if(needle[len] == needle[j])
		{
			len++;
			lps[j] = len;
			j++;
		}

		else
		{
			if(len != 0)
				len = lps[len-1];
			else
			{
				lps[j] = 0;
				j++;
			}
		}
	}
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	
	ll n;
	while(cin>>n)
	{
		string needle;
		string haystack;

		cin>>needle>>haystack;

		ll lps[n];
		computeLps(lps, needle, n);

		ll i=0, j=0;

		while(i < haystack.size())
		{
			if(haystack[i] == needle[j])
			{
				i++;
				j++;
			}

			if(j==n)
			{
				cout<<i-n<<endl;
				j = lps[j-1];
			}

			else if(haystack[i] != needle[j] && i < haystack.size())
			{
				if(j!=0)
					j = lps[j-1];
				else
					i++;
			}
		}
		cout<<endl;
	}
	return 0;
}