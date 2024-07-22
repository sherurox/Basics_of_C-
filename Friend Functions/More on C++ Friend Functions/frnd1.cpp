#include<iostream>
using namespace std;

class y;

class x
{
   int data;
   public:
    void setValue( int value)
    {
         data = value;
    }

    friend void add(x,y);
};

class y
{
  int num;  
  public:
    void setValue( int value)
    {
         num = value;
    }
    friend void add(x,y);
};

void add(x o1, y o2)
{
    cout<<"data x + y = "<<o1.data + o2.num<<endl;
}



int main()
{

 x a;
 a.setValue(3);
 y b;
 b.setValue(2);
add(a,b);

    return 0;
}