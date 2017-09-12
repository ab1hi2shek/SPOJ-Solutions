#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
 
//data types
#define ll long long int
 
int main()
{
	ll t;
	scanf("%lld", &t);

	while(t--)
	{
		ll n,m,q;
		scanf("%lld%lld%lld", &n, &m, &q);

		multiset<ll> xcoord, ycoord, xdiff, ydiff;
		xcoord.insert(0);
		xcoord.insert(n);
		ycoord.insert(0);
		ycoord.insert(m);
		xdiff.insert(n);
		ydiff.insert(m);

		while(q--)
		{
			ll type, val;
			scanf("%lld%lld", &type, &val);
			ll x,y;

			if(type == 0)
			{
				multiset<ll>::iterator it1 = xdiff.end(), it2;
				it1--;

				if(xcoord.find(val) != xcoord.end())
					x = (*it1);
				else
				{
					it1 = upper_bound(xcoord.begin(), xcoord.end(), val);
					it2 = it1;
					it2--;
					ll u = *it1, v = *it2;
					xdiff.erase(xdiff.find(u-v));
					xdiff.insert(u-val);
					xdiff.insert(val-v);
					it1 = xdiff.end();
					it1--;
					x = (*it1);
				}

				it2 = ydiff.end();
				it2--;
				y = *it2;
				xcoord.insert(val);
			}
			else
			{
				multiset<ll>::iterator it1 = ydiff.end(), it2;
				it1--;

				if(ycoord.find(val) != ycoord.end())
					y = (*it1);
				else
				{
					it1 = upper_bound(ycoord.begin(), ycoord.end(), val);
					it2 = it1;
					it2--;
					ll u = *it1, v = *it2;
					ydiff.erase(ydiff.find(u-v));
					ydiff.insert(u-val);
					ydiff.insert(val-v);
					it1 = ydiff.end();
					it1--;
					y = (*it1);
				}

				it2 = xdiff.end();
				it2--;
				x = *it2;
				ycoord.insert(val);
			}
			printf("%lld\n", x*y);
		}
	}
}