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
 
int main()
{
    std::ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    set<ll> set1, set2;
    vector<pii> vp;

    loop(i,1,n-1)
    {
        ll a,b;
        cin>>a>>b;
        vp.push_back(make_pair(min(a,b), max(a,b)));
    }

    if(n==1)
    {
        cout<<"0"<<endl;
        return 0;
    }

    sort(vp.begin(), vp.end());
    set1.insert(vp[0].first);
    set2.insert(vp[0].second);

    loop(i,1,vp.size()-1)
    {
        ll a = vp[i].first;
        ll b = vp[i].second;
        if(set1.find(a) != set1.end())
            set2.insert(b);
        else
            set1.insert(b);
    }


    //cout<<set1.size()<<" "<<set2.size()<<endl;
    ll ans = (set1.size()) * (set2.size());
    //cout<<ans<<endl;
    cout<<ans-n+1<<endl;
    return 0;
}