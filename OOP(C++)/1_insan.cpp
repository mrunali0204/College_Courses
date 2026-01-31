#include<iostream>
using namespace std;

class Insan
{
    public:
    char name[50];
    int age;
    
    void get_data()
    {
        cout<<"Enter the name: ";
        cin>>name;
        cout<<"Enter age: ";
        cin>>age;
    }

    void print_data()
    {
        cout<<"Name: "<< name << endl;
        cout<<"Age: "<< age << endl;
    }

};

int main()
{
    Insan s;
    s.get_data();
    s.print_data();

    return 0;
}