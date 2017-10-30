#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
//este O(n*d) -n-am stiu sa fac nlogn
struct interval
{
    int a,b,c;
};

struct sala
{
    interval a[100];
    int nr;
};

int cmp(interval x,interval y)
{
    return x.a<y.a;
}

int main()
{
    int n,i,nr_procesoare=1,j;
    interval aux;
    ifstream f("date.in");
    vector<interval> v;
    vector<interval> a;

    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>aux.a>>aux.b;
        aux.c=i;
        v.push_back(aux);
    }

    sort(v.begin(),v.end(),cmp);

    a.push_back(v[0]);
    for(i=1;i<n;i++)
    {
        int check=0;
        for(j=0;j<a.size();j++)
            if(a[j].b<=v[i].a)
            {
                a[j]=v[i];

                check=1;
                break;
            }
        if(check==0)
        {
             a.push_back(v[i]);
             nr_procesoare++;
        }
    }









    cout<<nr_procesoare;





    return 0;
}
