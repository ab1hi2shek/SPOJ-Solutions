/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date -
	Logic -
	Category - 
	Platform
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
#define MAXM 100005
#define POW(k) int(1<<k)

ll arr[MAXM];
ll lookup[MAXM][50];

void preprocess(ll n)
{
	// for(ll i=0; i<n; i++)
	// 	sparse[i][0] = i;

	// for(ll j=1; POW(j) <=n; j++)
	// {
	// 	for(ll i=0; i+POW(j)-1 < n; i++)
	// 	{
	// 		if(arr[sparse[i][j-1]] <= arr[sparse[i+POW(j-1)][j-1]])
	// 			sparse[i][j] = sparse[i][j-1];
	// 		else
	// 			sparse[i][j] = sparse[i+POW(j-1)][j-1];
	// 	}
	// }

	for (int i = 0; i < n; i++)
        lookup[i][0] = i;
 
    // Compute values from smaller to bigger intervals
    for (int j=1; (1<<j)<=n; j++)
    {
        // Compute minimum value for all intervals with size 2^j
        for (int i=0; (i+(1<<j)-1) < n; i++)
        { 
            // For arr[2][10], we compare arr[lookup[0][7]] and
            // arr[lookup[3][10]]
            if (arr[lookup[i][j-1]] < arr[lookup[i + (1<<(j-1))][j-1]])
                lookup[i][j] = lookup[i][j-1];
            else
                lookup[i][j] = lookup[i + (1 << (j-1))][j-1];      
        }
    }
}

ll query(ll L, ll R)
{
	// ll diff = y-x+1;
	// diff = log(diff);

	// return min( arr[sparse[x][diff]],  arr[sparse[y-POW(diff)+1][diff]]);

	int j = (int)log2(R-L+1);
 
    // For [2,10], we compare arr[lookup[0][7]] and
    // arr[lookup[3][10]], 
    if (arr[lookup[L][j]] <= arr[lookup[R-(int)pow(2,j)+1][j]])
        return arr[lookup[L][j]];
 
   else return arr[lookup[R-(int)pow(2,j)+1][j]];
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	//ll t;
	//cin>>t;
	//ll p = 1;
	//while(t--)
	//{
		ll n;
		cin>>n;

		loop(i,0,n-1)
			cin>>arr[i];

		preprocess(n);

		 ll q;
		 cin>>q;
		//cout<<"Scenario #"<<p++<<":"<<endl;
		while(q--)
		{
			ll a,b;
			cin>>a>>b;

			cout<<query(a, b)<<endl;
		}
	//}
	//return 0;
}