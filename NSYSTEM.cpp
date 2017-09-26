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

ll change(char c)
{
	if(c== 'm')	return 1000;
	else if(c == 'c') return 100;
	else if(c == 'x') return 10;
	else if(c == 'i') return 1;
	else return 0;
}

char invChange(ll val)
{
	if(val == 1000)	return 'm';
	if(val == 100) return 'c';
	if(val == 10) return 'x';
	if(val == 1) return 'i';
}

ll conv(string s)
{
	ll ans = 0;
	loop(i,0,s.size()-1)
	{
		ll temp = change(s[i]);
		if(temp != 0)
		{
			if(i-1 >= 0 && s[i-1] >= '2' && s[i-1] <= '9')
				ans += temp * (s[i-1] - '0');
			else
				ans += temp;
		}
	}
	return ans;
}

string revConv(ll a)
{
	string s = "";
	ll temp = 1000;
	loop(i,0,3)
	{
		ll rem = a/temp;
		if(rem >= 2) s+= (rem + '0');
		if(rem >= 1) s+= invChange(temp);
		a = a%temp;
		temp /= 10;
	}
	return s;
}

int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		string a, b;
		cin>>a>>b;
		// ll p = conv(a) + conv(b);
		// cout<<" p = "<<p<<endl;
		cout<<revConv(conv(a) + conv(b))<<endl;		
	}
	return 0;
}