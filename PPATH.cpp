#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll int
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

bool prime[10001];
int visited[10001];

ll convString(string s)
{
	ll ans = 0;
	for(ll i=0;i<4;i++)
		ans = ans*10 + (s[i] - '0');
	return ans;
}

bool sieve()
{
	memset(prime,true,sizeof(prime));
	for(ll i=2;i <= sqrt(10001); i++)
	{
		if(prime[i])
		{
			for(ll j= i*i; j<10001; j+=i)
				prime[j] = false;
		}
	}
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	sieve();
	//memset(visited,0,sizeof(visited));
	//cout<<prime[1033]<<" "<<prime[1733]<<" "<<prime[1737]<<" "<<prime[8179]<<endl;
	ll t;
	cin>>t;

	while(t--)
	{
		memset(visited,0,sizeof(visited));
		string a,b;
		cin>>a>>b;

		ll count = 0;
		string hash = "####";

		queue<string> q;
		q.push(a);
		q.push(hash);

		//visited[convString(a)] = 1;
		ll flag = 1;
		ll xxx = 0;
		while(!q.empty())
		{
			string temp = q.front();
			q.pop();

			if(temp.compare(hash)==0 && !q.empty())
			{
				q.push(hash);
				count++;
			}

			else
			{
				visited[convString(temp)] = 1;
				//xxx++;

				if(temp.compare(b)==0)
				{
					cout<<count<<endl;
					flag = 0;
					break;
				}
				for(int i=3;i>=0;i--)
				{
					int rem = temp[i]-'0';
					string s = temp;
					for(int j=0;j<10;j++)
					{
						if(j==rem || (i==0 && j==0))
							continue;
						s[i] = j + '0';

						int p = convString(s);
						if(visited[p] == 0 && prime[p]){
							q.push(s);
							//cout<<s<<endl;
							visited[p] = 1;
						}
					}
				}
			}
		}
		//cout<<xxx<<endl;

		if(flag==1)
			cout<<"Impossible"<<endl;
	}
}