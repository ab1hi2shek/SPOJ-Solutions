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

	while(1)
	{
		string s;
		cin>>s;

		if(s.compare("00e0") == 0)
			break;

		ll num = 0;
		num = s[0] - '0';
		num = num*10 + (s[1]-'0');

		num = num * pow(10, (s[3] - '0'));
		//cout<<num<<endl;

		ll i = 1;
		ll temp = 1;
		while( i + temp <= num)
		{
			temp += i;
			i = i*2;
		}

		//cout<<temp<<endl;

		cout<<( 1 + (num-temp)*2)<<endl;
	}
}