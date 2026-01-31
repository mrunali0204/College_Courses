#include<iostream>
using namespace std;
int area(int);
int area(int,int);
float area(float);
int main()
{
    int a,l,b;
    float r;
    cout<<"enter side of square:";
    cin>>a;
    cout<<"enter length and breadth of rectangle:";
    cin>>l>>b;
    cout<<"enter radius of circle:";
    cin>>r;
    cout<<"\n enter the sides of square:"<<area(a);
    cout<<"\n enter the length and breadth of rectangle:"<<area(l)<<area(b);
    cout<<"\n enter the radius of circle:"<<area(r);
}
int area(int a)
{
    return(a*a);
}
int area(int l,int b)
{
    return(l*b);
}
float area(float r)
{
    return(3.14*r*r);
}