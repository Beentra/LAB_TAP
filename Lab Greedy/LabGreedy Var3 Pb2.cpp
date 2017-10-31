#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void colorare(vector<int> v[],vector<int> &c, int nod, int tata, int& check)
{
    int i;
    if(c[tata]==2)
        check=1;
    else
        check=2;
    c[nod]=check;
    for(i=0; i<v[nod].size(); ++i)
        if(v[nod][i]!=tata)
            colorare(v, c, v[nod][i], nod, check);
}

int main()
{
    ifstream fin("date.in");
    int n,i;
    fin>>n;

    vector<int> v[n+1], c;

    for(i=0; i<n; ++i)
    {
        c.push_back(i);
        int x,y;
        fin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int contor_par=0, contor_impar=0, check=0;

    colorare(v, c, 1, 0, check);

    for(i=1; i<=n; ++i)
        if(c[i]==2)
            contor_par++;
        else
            contor_impar++;

    if(contor_par>contor_impar)
        check=2;
    else
        check=1;

    for(i=1; i<=n; ++i)
        if(c[i]==check)cout<<i<<" ";
    cout<<endl;

    return 0;
}
