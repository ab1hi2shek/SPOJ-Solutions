/*
	CODE BY - ABHISHEK KUMAR
			  NIT DURGAPUR
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

int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	ll p = 1;
	while(cin>>s)
	{
		ll i = 0;
		ll count = 0;
		while(1)
		{
			//cout<<i<<" ";
			while(i < s.size() && s[i] =='0')
				i++;
			if(i == s.size())
				break;
			else
				count++;
			loop(j,i,s.size()-1)
				s[j] = (s[j] == '0') ? '1'  : '0';
		}
		cout<<"Game #"<<p++<<": "<<count<<endl;


	}
	return 0;
}