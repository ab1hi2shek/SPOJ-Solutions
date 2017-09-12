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
	
	string s;
	while(cin>>s)
	{
		if(!s.length())
		{
			cout<<s<<endl;
			continue;
		}

		if(s[0]=='_' || s[s.length()-1] == '_')
		{
			cout<<"Error!"<<endl;
			continue;
		}

		bool under = false, caps = false;
		for(ll i=0;i<s.length(); i++)
		{
			if(s[i]=='_')
				under = true;
			if(s[i] >= 'A' && s[i] <= 'Z')
			{
				caps = true;
				if(i==0)
					under = true;
			}
			if(i !=0 && s[i-1] == '_' && s[i-1] == s[i])
			{
				under = true;
				caps = true;
			}
		}

		if(caps && under)
		{
			cout<<"Error!"<<endl;
			continue;
		}

		string ans = "";
		ll i = 0;
		while(i<s.length())
		{
			if(s[i] =='_')
			{
				i++;
				ans += (s[i] - 32);
				i++;
			}

			else if(s[i] >= 'A' && s[i] <= 'Z')
			{
				if(i!=0)
					ans += '_';
				ans += (s[i]+32);
				i++;
			}

			else
			{
				ans += s[i];
				i++;
			}
		}

		cout<<ans<<endl;
	}
}
