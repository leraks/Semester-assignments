#include <iostream>
using namespace std;
class type1
{
private:
    int val;

public:
    void setval(int v)
    {
        val = v;
    }
    int getval() { return val; }
};
class type2
{
private:
    int sol;

public:
    void setval(int v)
    {
        sol = v;
    }
    int getval() { return sol; }
};
class type2a : public type2
{
private:
    type1 t;

public:
    void setvalV(int v)
    {
        t.setval(v);
    }
    int getvalV()
    {
        return t.getval();
    }
};
int main(){
    type1 * t;
    type2 * t2;
    t2 = new type2a;
    t2->setval(2);
    ((type2a *)t2)->setvalV(3);
    int vv = ((type2a *)t2)->getvalV();
    cout << t2->getval() << " " << vv;
    return 0;
}