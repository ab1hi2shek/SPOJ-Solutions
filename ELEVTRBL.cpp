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
#define MAXM 1000005

bool visited[MAXM];

int main()
{
	std::ios::sync_with_stdio(false);
	memset(visited, false, sizeof(visited));
	ll floors, start, goal, up, down;
	cin>>floors>>start>>goal>>up>>down;

	queue<ll> q;
	q.push(start);
	q.push(-1);

	ll count = 0;
	while(!q.empty())
	{
		ll curr = q.front();
		//cout<<curr<<" "<<endl;
		q.pop();

		if(curr == -1)
		{
			if(!q.empty())
			{
				q.push(-1);
				count++;
			}
			continue;
		}

		if(visited[curr])
			continue;	

		if(curr == goal)
		{
			cout<<count<<endl;
			return 0;
		}
		visited[curr] = true;
		//cout<<" haha  = "<<(curr+up)<<" "<<curr-down<<endl;

		if(curr+up <= floors && !visited[curr+up])
		{
			q.push(curr+up);
			//visited[curr+up] = true;
		}
		if(curr-down > 0 && !visited[curr-down])
		{
			//visited[curr-down] = true;
			q.push(curr-down);
		}
	}

	cout<<"use the stairs\n";
	return 0;
}