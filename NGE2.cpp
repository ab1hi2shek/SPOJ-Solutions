/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date -	12/09/2017
	Logic -	Basic Math	
	Category - Easy
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
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	if(t==0)
	{
		cout<<"0"<<endl;
		return 0;
	}

	vector<ll> v;
	while(t!=0)
	{
		ll rem = t % -2;
		t = t / (-2);
		if(rem < 0)
		{
			rem +=2;
			t++;
		}
		v.push_back(rem);
	}
	reverse(v.begin(), v.end());

	loop(i,0,v.size()-1)
		cout<<v[i];
	cout<<endl;
}