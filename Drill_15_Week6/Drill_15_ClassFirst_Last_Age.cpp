/*
    g++ Drill_15_ClassFirst_Last_Age.cpp -o Drill_15_Class  
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
Person():fname_var(""), lname_var(""), age_var(0){};
Person(string f, string l, int a);
string fname() const {return fname_var;}
string lname() const {return lname_var;}
int age() const {return age_var;}
private:
    string fname_var;
    string lname_var;
    int age_var;
};

/*Person::Person(string f, string l, int a):fname_var(f),lname_var(l),age_var(a)
    {
        if (a<0 || a>=150) error("Age must be in range [0,150)");
        string fullname=f+l;
        for (char c : fullname)
        {
            switch(c) {
            case ';': case ':': case '"': case '[': case ']': case '*':
            case '&': case '^': case '%': case '$': case '#': case '@':
            case '!':
                error("Person(): bad char in names");
                break;
            default:
                break;
            }
        }
    }
*/

Person::Person(string f, string l, int a):fname_var(f),lname_var(l),age_var(a)
{
    if (a<0 || a>=150) error("Age must be in range [0,150).");
    const string bad_chars=";:\"'[]*&^%$#@!";
    for (int i = 0; i < f.size(); ++i)
    {
        for (int j = 0; j < bad_chars.size(); ++j)
        {
            if(f[i]==bad_chars[j]) error("Character is not allowed in first name: ",string(1,f[i]));
        }
    }
    for (int i = 0; i < l.size(); ++i)
    {
        for (int j = 0; j < bad_chars.size(); ++j)
        {
            if(l[i]==bad_chars[j]) error("Character is not allowed in last name: ",string(1,l[i]));
        }
    }
}

istream& operator>>(istream& is, Person& p)
{
string fname,lname;
int age;
is>>fname>>lname>>age;
if(!is) error("Can not read into Person.");
p = Person(fname,lname,age);
return is;
}

ostream& operator<<(ostream& os, const Person& p)
{
return os<<"First name: "<<p.fname()<<" Last name: "<<p.lname()<<" age: "<<p.age()<<"\n";
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
cout << "Enter first and last names and ages. Terminate the loop with first name: 'exit'\n";
for (Person p; cin >> p; ) 
{
if (p.fname() == "exit") break;
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