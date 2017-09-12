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
		ll arr[8];
		ll count = 0;
		loop(i,0,7)
		{
			cin>>arr[i];
			if(arr[i] == -1) count++;
		}

		if(count==8)
			break;

		ll a = arr[0]%arr[4]==0?arr[0]/arr[4]:arr[0]/arr[4] + 1;
		ll b = arr[1]%arr[5]==0?arr[1]/arr[5]:arr[1]/arr[5] + 1;
		ll c = arr[2]%arr[6]==0?arr[2]/arr[6]:arr[2]/arr[6] + 1;
		ll d = arr[3]%arr[7]==0?arr[3]/arr[7]:arr[3]/arr[7] + 1;

		ll maxm = max(a,max(b, max(c,d)));
		//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

		ll ans1 = arr[4]*maxm - arr[0];
		ll ans2 = arr[5]*maxm - arr[1];
		ll ans3 = arr[6]*maxm - arr[2];
		ll ans4 = arr[7]*maxm - arr[3];

		cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<endl;


	}
}