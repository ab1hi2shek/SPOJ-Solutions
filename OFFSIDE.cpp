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

	while(1)
	{
		ll n,m;
		cin>>n>>m;

		if(n==0 && m==0)	break;

		ll def1,def2,attack;
		vi def(m);
		vi attck(n);
		loop(i,0,n-1)
			cin>> attck[i];
		loop(i,0,m-1)
			cin>> def[i];
		sort(def.begin(), def.end());
		sort(attck.begin(), attck.end());


		//ll flag = 0;
		if(attck[0] < def[1])
		{
			cout<<"Y"<<endl;
		}
		else
			cout<<"N"<<endl;
	}
	return 0;
}