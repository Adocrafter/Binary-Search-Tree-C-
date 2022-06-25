#include <iostream>
#include "stablo.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Stablo<int> s;
    s.add(2);
    s.add(3);
    s.add(5);
    s.add(1);
    s.Ispisi();
    cout<<endl;
    cout<<s.NajmanjiElement()<<endl;
    cout<<"Zesca proba"<<endl;
    s.Brisi(1);
    s.Ispisi();



    return 0;
}
