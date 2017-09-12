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
typedef map<ll,ll> mp;
#define sz(a) (a).size()
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mp make_pair
#define fi first
#define se second

//loops
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define loopr(i,a,b) for(ll i=a;i>=b;i--)

//others
#define isPowerOfTwo(S) !(S & (S - 1))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define nline cout<<endl
#define MAX 1000000000
#define SQRT 31640

void seive(vi &prime)
{
	bool temp_arr[SQRT];
	memset(temp_arr, true, sizeof(temp_arr));

	loop(i,2,sqrt(SQRT))
	{
		if(temp_arr[i])
		{
			for(ll j=i*i; j<SQRT;j+=i)
				temp_arr[j] = false;
		}
	}

	for(ll i=2;i<SQRT;i++)
	{
		if(temp_arr[i])
			prime.pb(i);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	vi prime;
	seive(prime);

	ll t;
	cin>>t;

	while(t--)
	{
		ll m,n;
		cin>>m>>n;

		ll sizes = n-m+1;


		bool arr[sizes];
		memset(arr,true,sizeof(arr));

		//vi::iterator it;
		for(ll it = 0; it<prime.size(); it++)
		{
			ll i = prime[it];
			if(i >= sqrt(n)+1)
				break;
			ll indx;

			if(i >= m)  indx = i*2;
			else
                indx = m + ((i-m%i)%i);

			for (ll j=indx; j<=n; j+=i)
                arr[j-m] = false;
		}

		for (ll i = m; i<=n; i++){
            if (arr[i - m] == true && i>=2)
                cout << i << "  ";
		}
        nline;

	}
	return 0;
}
