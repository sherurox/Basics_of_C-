#include<iostream>
using namespace std;

class simplecalc{

public:
     int ans1;
    void add(int a, int b)
    {
         ans1=a+b;
    }
    void sub(int a,int b)
    {
         ans1=a-b;
    }
     void mul(int a,int b)
    {
         ans1=a*b;
    }
     void div(int a,int b)
    {
         ans1=a/b;
    }

    void display1(void)
    {

        cout<<"The answer from simple calc is "<<ans1<<endl;
    }
      
};

class complexcalc{

public:
    float ans2;
    void percentage(float a, float b)
    {
       ans2= a/b*100;
    }
    void greater(int a, int b)
    {
       if (a>=b)
        ans2 = a;
       else
         ans2 = b;
    }
    void display2(void)
    {
        cout<<"The answer is "<<ans2<<endl;
    }

};

class hybrid : public simplecalc, public complexcalc
{
  public:
    
     void display99(void)
     {
        cout<<"You chose hybrid calculator"<<endl;
     }
      
     

};

int main()
{
    int c;
    cout<<"ENTER 1 for SIMPLE CALCULATOR"<<endl;
    cout<<"ENTER 2 for COMPLEX CALCULATOR"<<endl;
    cout<<"ENTER 3 for HYBRID CALCULATOR"<<endl;
    cin>>c;

     switch(c){

     case 1 :

         simplecalc s;
        cout<<"YOU CHOOSE SIMPLE CALCULATOR"<<endl;

        cout<<"ENTER 1 for ADDITION"<<endl;
        cout<<"ENTER 2 for SUBTRACTION"<<endl;
        int x1;
         cin>>x1;
        switch(x1){
             case 1 :
                 cout<<"YOU CHOOSE ADDITION"<<endl;
                 s.add(100,20);
                 s.display1(); 
                 break;
              case 2 :
                 cout<<"YOU CHOOSE SUBTRACTION"<<endl;
                 s.sub(100,20);
                 s.display1(); 
                 break;
              default :
                  cout<<"WRONG CHOICE BRO"<<endl;
               break;
               
        }
        break;
     case 2 :
      complexcalc s2;
      cout<<"YOU CHOOSE COMPLEX CALCULATOR"<<endl;

        cout<<"ENTER 1 for PERCENTAGE"<<endl;
        cout<<"ENTER 2 for COMPARISON"<<endl;
         int x2;
         cin>>x2;
            switch(x2){
                case 1 : 
                cout<<"YOU CHOOSE PERCENTAGE"<<endl;
                s2.percentage(92.0 ,120.0);
                s2.display2();
                break;
                case 2 : 
                cout<<"YOU CHOOSE COMPARISON"<<endl;
                s2.greater(94.0,92.0);
                s2.display2();
                break;
                default :
                  cout<<"WRONG CHOICE BRO"<<endl;
                break;
                }
     break;
    case 3 :
      hybrid s3;
       
        cout<<"YOU CHOOSE HYBRID CALCULATOR"<<endl;

        cout<<"ENTER 1 for ADDITION"<<endl;
        cout<<"ENTER 2 for SUBTRACTION"<<endl;

        cout<<"ENTER 3 for PERCENTAGE"<<endl;
        cout<<"ENTER 4 for COMPARISON"<<endl;
       int x3;
       cin>>x3;
       switch(x3){
               case 1 :
                 cout<<"YOU CHOOSE ADDITION"<<endl;
                 s3.add(100,20);
                 s3.display99();
                 s3.display1(); 
                 break;
               case 2 :
                 cout<<"YOU CHOOSE SUBTRACTION"<<endl;
                 s3.sub(100,20);
                 s3.display99();
                 s3.display1(); 
                 break;

               case 3 : 
                cout<<"YOU CHOOSE PERCENRAGE"<<endl;
                s3.percentage(92 ,192);
                s3.display99();
                s3.display2(); 
                break;
               case 4 : 
                cout<<"YOU CHOOSE COMPARISON"<<endl;
                s3.greater(94 ,92);
                s3.display99();
                 s3.display2(); 
                break;
                default:
                 cout<<"WRONG CHOICE BRO"<<endl;
                 break;
       }
            
     break;
    default:
      cout<<"WRONG CHOICE BROOOOOOOOOOOO"<<endl;

    
     }

    
    
    
}