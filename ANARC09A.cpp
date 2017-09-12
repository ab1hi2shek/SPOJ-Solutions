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
	// ll t;
	// cin>>t;
	ll p = 1;

	while(1)
	{
		string s;
		cin>>s;
		if(s[0]=='-')
			break;

		stack<char> st;

		//cout<<s.size()<<endl;

		for(ll i=0;i<s.length();i++)
		{
			if(s[i]=='{')
				st.push(s[i]);
			else if(s[i]=='}' && !st.empty() && st.top()=='{')
				st.pop();
			else
				st.push(s[i]);
		}

		ll count = 0;
		//cout<<st.size()<<endl;
		while(!st.empty())
		{
			char a = st.top();
			st.pop();
			char b = st.top();
			st.pop();

			if(a=='{' && b=='}')
				count += 2;
			else
				count += 1;
		}
		cout<<p++<<". "<<count<<endl;
	}
	return 0;
}