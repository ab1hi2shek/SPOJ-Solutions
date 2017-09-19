#include <bits/stdc++.h>
 
using namespace std;
 
#define fastio          std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define PAUSE_EXE       assert(false)
#define MAX             30002
#define MAX2            200002
#define SIZE            1000002
#define MOD             1000000007LL
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)
#define CREP(i,n)       for(__typeof(n) i=n-1; i>=0; --i)
#define MYREP(i,a,b)    for(__typeof(a) i=a; i<=b; ++i)
#define MYCREP(i,a,b)   for(__typeof(a) i=b; i>=a; --i)
#define sz(a)           int((a).size())
#define pb              push_back
#define mp              make_pair
#define fi              first
#define sec             second
#define all(c)          (c).begin(),(c).end()
#define allr(c)         (c).rbegin(),(c).rend()
#define loop(c,i)       for(typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define loopr(c,i)      for(typeof(c.end()) i = c.end(); i != c.begin(); )
 
int bucket_size, num[MAX], freq[SIZE];
 
int ans[MAX2];
 
struct query
{
    int ind, l, r;
}q[MAX2];
 
bool cmp(query a, query b)
{
    int ax = a.l/bucket_size;
    int bx = b.l/bucket_size;
    if (ax != bx)
        return ax < bx;
    return a.r < b.r;
}
 
int main()
{
    int n, m;
    scanf("%d", &n);
    MYREP(i, 1, n)
        scanf("%d", &num[i]);
    scanf("%d", &m);
    REP(i, m)
    {
        // inPos(q[i].l) , inPos(q[i].r);
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].ind = i;
    }
    bucket_size = ceil(sqrt(n));
    sort(q, q+m, cmp);
    int start, end;
    int sum;
    start = end = 0;
    sum = 0;
    REP(i, m)
    {
        while (start < q[i].l)
        {
            --freq[num[start]];
            if (freq[num[start]] == 0)
                sum--;
            ++start;
        }
        while (end > q[i].r)
        {
            --freq[num[end]];
            if (freq[num[end]] == 0)
                sum--;
            --end;
        }
 
        while (start > q[i].l)
        {
            --start;
            ++freq[num[start]];
            if (freq[num[start]] == 1)
                sum++;
        }
        while (end < q[i].r)
        {
            ++end;
            ++freq[num[end]];
            if (freq[num[end]] == 1)
                sum++;
        }
 
        ans[q[i].ind] = sum;
    }
    REP(i, m)
        printf("%d\n", ans[i]);
    return 0;
}