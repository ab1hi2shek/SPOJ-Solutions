/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date -   { in format DDMMYYYY}
	Logic - [] { 1. Very Easy, 2.Easy, 3.Medium, 4.Hard, 5.Very Hard}
	Category - 
	Platform - SPOJ
*/	  

#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll long long
#define ull unsigned long long
 
//stl
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef map<ll,ll> mpll;
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
 
//loops
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define loopr(i,a,b) for(ll i=a;i>=b;i--)
 
//others
#define isPowerOfTwo(S) !(S & (S - 1))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define mem(x,val) memset(x, val, sizeof(mem))
#define nline cout<<endl
#define MOD 1000000007
#define MAXM 1005

struct node
{
	ll index;
	ll rank[2];
};

ll suffixArr[MAXM];
ll lcp[MAXM];

bool accompare(node a, node b)
{
	if(a.rank[0] < b.rank[0])
		return true;
	if(a.rank[0] == b.rank[0] && a.rank[1] < b.rank[1])
		return true;
	return false;
}

void buildSuffixArray(string s, ll n)
{
	node suffix[n];
	ll ind[n];

	for(ll i=0;i<n;i++)
	{
		suffix[i].index = i;
		suffix[i].rank[0] = int(s[i]);
		suffix[i].rank[1] = i+1 < n ? int(s[i+1]) : -1;
	}
	sort(suffix, suffix+n, accompare);
	for(ll k=4;k<2*n;k*=2)
	{
		ll rank = 0;
		ll prev_rank = suffix[0].rank[0];
		suffix[0].rank[0] = rank;
		ind[suffix[0].index] = 0;

		for(ll i=1;i<n;i++)
		{
			if(suffix[i].rank[0] == prev_rank && suffix[i].rank[1] == suffix[i-1].rank[1])
			{
				prev_rank = suffix[i].rank[0];
				suffix[i].rank[0] = rank;
			}
			else
			{
				prev_rank = suffix[i].rank[0];
				suffix[i].rank[0] = ++rank;
			}
			ind[suffix[i].index] = i;
		}
		for(ll i=0;i<n;i++)
		{
			ll kp = suffix[i].index + k/2;
			suffix[i].rank[1] = kp < n ? suffix[ind[kp]].rank[0] : -1;
		}
		sort(suffix, suffix+n, accompare);
	}
	loop(i,0,n-1)
		suffixArr[i] = suffix[i].index;
}

void kasai(string s, ll n)
{
	ll invSuff[n];
	loop(i,0,n-1)
		invSuff[suffixArr[i]] = i;
	ll k = 0;
	for(ll i=0;i<n;i++)
	{
		if(invSuff[i] == n-1)
			continue;
		ll j = suffixArr[invSuff[i] + 1];
		while(i+k < n && j+k < n  && s[i+k] == s[j+k]) 
			k++;
		lcp[invSuff[i]] = k;
		if(k>0) 
			k--;
	} 
}

ll distictSubstring(string s, ll n)
{
	buildSuffixArray(s,n);
	kasai(s,n);

	// loop(i,0,n-1)
	// cout<<suffixArr[i]<<" ";
	// cout<<endl;
	// loop(i,0,n-1)
	// cout<<lcp[i]<<" ";
	// cout<<endl;
	ll ans = n - suffixArr[0];

	loop(i,1,n-1)
		ans += (n - suffixArr[i]) - lcp[i-1];
	return ans;
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		string s;
		cin>>s;

		ll n = s.size();
		cout<<distictSubstring(s,n)<<endl;

	}
}