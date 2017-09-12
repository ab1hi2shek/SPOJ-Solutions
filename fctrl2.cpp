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
typedef map<ll,ll> mapll;
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

map<ll,string> mp;
void dpFact()
{
	string s = "1";
	mp[0] = mp[1] = s;

	for(ll i=2;i<=100;i++)
	{
		ll carry = 0;
		for(ll j=s.length()-1; j>=0; j--)
		{
			ll val = (s[j]-'0')*i + carry;
		//	cout<<" i = "<<i<<" s[j] = "<<s[j]<<" val = "<<val<<endl;;
			s[j] = val%10 + '0';
			carry = val/10;
		}
		//cout<<" s befor carry = "<<s<<endl;
		if(carry)
		{
			string temp = to_string(carry);
			s = temp + s;
		}
		//cout<<"s after carry = "<<s<<endl;
		mp[i] = s;
	}
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	dpFact();

	//map<ll,string>::iterator it;
	//for(it = mp.begin(); it!=mp.end();it++)
	//	cout<<it->second<<endl;

	while(t--)
	{
		ll n;
		cin>>n;

		cout<<mp[n]<<endl;
	}
	return 0;
}