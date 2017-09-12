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
#define MAXN 1010

char a[MAXN], b[MAXN];
 
int main()
{
	std::ios::sync_with_stdio(false);
	//string a,b;

	while(scanf("%s%s", a,b) !=EOF)
	{
		//cin>>b;

		vi hashA(26,0);
		vi hashB(26,0);

		loop(i,0,strlen(a)-1)
			hashA[a[i]-'a']++;
		loop(i,0,strlen(b)-1)
			hashB[b[i]-'a']++;

		string s = "";
		loop(i,0,25)
		{
			
			while(hashA[i] !=0 && hashB[i] !=0 )
			{
				s += ( i + 'a');
				hashA[i]--;
				hashB[i]--;
			}
		}

		cout<<s<<endl;
	}
}