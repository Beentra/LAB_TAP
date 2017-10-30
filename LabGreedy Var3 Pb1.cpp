#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;

struct element
{
    int val;
    int poz;
};

void afisare(vector<element> v)
{
    int i;
    for(i=0; i<v.size(); i++)
        cout<<v[i].val<<" ";
    cout<<endl;

}

int main()
{
    ifstream f("date.in");
    srand (time(NULL));
    int decizia_p2;
    int n,suma1=0,suma2=0,i,sumPozP=0,sumPozI=0,check=0;
    vector<element> v;
    element aux;
    char q;


    f>>n;//citire vector plus calcularea sumei pt elemente de pe poz pare si impare
    for(i=1; i<=n; i++)
    {
        f>>aux.val;
        aux.poz=i;
        if(i%2==0)
            sumPozP=sumPozP+aux.val;
        else
            sumPozI=sumPozI+aux.val;
        v.push_back(aux);
    }
    afisare(v);
    cout<<endl;

    if(sumPozP>=sumPozI)
        check=2;//par
    else
        check=1;//impar

    if(v[0].poz % 2 == 0 && check==2)
    {
        suma1=suma1+v[0].val;
        v.erase(v.begin());
        cout<<"S->";
    }
    else if(v[0].poz % 2 != 0 && check==1)
    {
        suma1=suma1+v[0].val;
        v.erase(v.begin());
        cout<<"S->";
    }
    if(v[v.size()-1].poz % 2 ==0 && check==2)
    {
        suma1=suma1+v[v.size()-1].val;
        v.pop_back();
        cout<<"D->";
    }
    else if(v[v.size()-1].poz % 2 !=0 && check==1)
    {
        suma1=suma1+v[v.size()-1].val;
        v.pop_back();
        cout<<"D->";
    }
    cout<<"Player1:"<<endl;
    afisare(v);
    cout<<endl;


    while(!v.empty())
    {
        decizia_p2=rand() %2 +1;//1-stanga  2-dreapta
        if(decizia_p2==1)
        {
            suma2=suma2+ v[0].val;
            v.erase(v.begin());
            cout<<"S->";
        }
        else
        {
            suma2=suma2+v[v.size()-1].val;
            v.pop_back();
            cout<<"D->";
        }
        cout<<"Player2:"<<endl;
        afisare(v);
        cout<<endl;
        if(v.empty())
            break;
        if(v[0].poz % 2 == 0 && check==2)
        {
            suma1=suma1+v[0].val;
            v.erase(v.begin());
            cout<<"S->";
        }
        else if(v[0].poz % 2 != 0 && check==1)
        {
            suma1=suma1+v[0].val;
            v.erase(v.begin());
            cout<<"S->";
        }
        if(v[v.size()-1].poz % 2 ==0 && check==2)
        {
            suma1=suma1+v[v.size()-1].val;
            v.pop_back();
            cout<<"D->";
        }
        else if(v[v.size()-1].poz % 2 !=0 && check==1)
        {
            suma1=suma1+v[v.size()-1].val;
            v.pop_back();
            cout<<"D->";
        }
        cout<<"Player1:"<<endl;
        afisare(v);
        cout<<endl;

    }

    cout<<"Player1:"<<suma1<<endl;
    cout<<"Player2(calc):"<<suma2;










    return 0;
}
