#include<bits/stdc++.h>
#define format(q) setpersesion(q)
using namespace std;
void fast()
{
 #ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    //fast();
    int n;
    cin>>n;
    list<int>l;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        l.push_back(x);
    }
    list<int>::iterator it;
    list<int>::iterator it2;
    for(it=l.begin();it!=l.end();it++)
    {
        int s=*it;
        if(s%2!=0)
        {
            it=l.erase(it);
            it--;

        }
    }
    for(it=l.begin();it!=l.end();it++)
    {
        cout<<(*it)<<" ";
    }
    return 0;
}
