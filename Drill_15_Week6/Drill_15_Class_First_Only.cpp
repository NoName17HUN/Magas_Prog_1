/*
    g++ Drill_15_Class_First_Only.cpp -o Drill_15_Class_First_Only  
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std; 
void error(string s1)
{
throw runtime_error(s1);
}
void error(string s1, string s2)
{
    throw runtime_error(s1 + s2);
}
struct Person
{
Person():name_var(""), age_var(0){};
Person(string n, int a);
string name() const {return name_var;
int age() const {return age_var;}
private:
    string name_var;
    int age_var;
};
Person::Person(string n, int a):name_var(n),age_var(a)
{
    if (a<0 || a>=150) error("Age must be in range [0,150)");
    const string bad_chars=";:\"'[]*&^%$#@!";
    for (int i = 0; i < n.size(); ++i)
    {
        for (int j = 0; j < bad_chars.size(); ++j)
        {
            if(n[i]==bad_chars[j]) error("Character is not allowed: ",string(1,n[i]));
        }
    }
}
istream& operator>>(istream& is, Person& p)
{
string name;
int age;
is>>name>>age;
if(!is) error("Can not read into Person.");
p = Person(name,age);
return is;
}
ostream& operator<<(ostream& os, const Person& p)
{
return os<<"Name: "<<p.name()<<" age: "<<p.age()<<"\n";
}
int main()
try
{
    /*
    2.
    Person p;
    p.name_var = "Goofy";
    p.age_var = 63;
    cout<<"2. The person is: "<<p.name_var<<" his age: "<<p.age_var<<"\n";
    */

    /*
    7. Test out the age and name check:
    cout << "Give a name and age: ";
    Person p2;
    cin >> p2;
    cout << p2 << endl;
    */

    //8.
vector<Person> v;
cout << "Enter names and ages. Terminate the loop with name: 'exit'\n";
for (Person p; cin >> p; ) 
{
    if (p.name() == "exit") break;
    v.push_back(p);
}
for (Person p : v)
    cout << p;
}
catch (std::exception& e) 
{
std::cerr << "Exception: " << e.what() << '\n';
return 1;
}
catch (...) 
{
std::cerr << "Unknown error!\n";
return 2;
}