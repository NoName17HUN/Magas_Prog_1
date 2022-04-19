#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <stdexcept>
#include <algorithm>
#include <list>

using namespace std;

struct Item 
{
 string name;
 int iid;
 double value;
}
ostream& operator<<(ostream& os, Item& it)
{
 return os << it.name <<" "<<it.iid<<" "<<it.value<<"\n";
}
istream& operator>>(istream& is, Item& it)
{
 string ss;
 int ii;
 double dd;
 is>>ss>>ii>>dd;
 Item final_it {ss,ii,dd};
 it = final_it;
 return is;
}
//template for printing
template<typename C>
void write(C& c, string s)
{
cout<<s<<"\n";
for (auto p = c.begin();p!=c.end(); ++p)
    cout<<*p;
cout<<"\n";
}
int main()
try{
vector<Item> Vector;
string input_name {"Input.txt"};
ifstream ist {input_name};
if (!ist) runtime_error("can't open input file "+ input_name);
for (Item it; ist >> it; ) Vector.push_back(it); 
    write(Vector,"Original vector:");
    
string Name_A,Name_B;

sort(Vector.begin(), Vector.end(),
	[](const Item& Name_A, const Item& Name_B){return Name_A.name < Name_B.name;});
write(Vector,"After sort by name:");
sort(Vector.begin(), Vector.end(),
	[](const Item& Name_A, const Item& Name_B){return Name_A.iid < Name_B.iid;});
 
write(Vector,"After sort by id:");
sort(Vector.begin(), Vector.end(),
	[](const Item& Name_A, const Item& Name_B){return Name_A.value > Name_B.value;});  
write(Vector,"After sort by value:");
Item Congo {"Republic of Congo",1000,5.5};
Item NKorea {"North Korea",9999,99.99};
Vector.insert(Vector.begin(), Congo);
Vector.insert(Vector.begin(), NKorea);
write(Vector,"After insert:");
string name="North Korea";
Vector.erase(find_if(Vector.begin(),Vector.end(),
[name](const Item& Name_A){return Name_A.name == name;}));
  
write(Vector,"Remove by name:");
int id=1000;
Vector.erase(find_if(Vector.begin(),Vector.end(),
[id](const Item& Name_A){return Name_A.iid == id;}));
write(Vector,"Remove by id:");

//Same with lists
list<Item> li;
string input_name2 {"Input.txt"};
ifstream ist2 {input_name2};
if (!ist) runtime_error("can't open input file "+ input_name2);
   for (Item it; ist2 >> it; ) li.push_back(it);  
write(li,"Original list:");

string Name_A2,Name_B2;
li.sort([](const Item& Name_A2, const Item& Name_B2){return Name_A2.name < Name_B2.name;});
write(li,"After sort by name:");


li.sort([](const Item& Name_A2, const Item& Name_B2){return Name_A2.iid < Name_B2.iid;});
write(li,"After sort by id:");
    

li.sort([](const Item& Name_A2, const Item& Name_B2){return Name_A2.value > Name_B2.value;});
write(li,"After sort by value:");

li.insert(li.begin(), Congo);
li.insert(li.begin(), NKorea);
write(li,"After insert:");
    

string name2="North Korea";

list<Item>::iterator itr = 
find_if(li.begin(),li.end(),
    [name2](const Item& Name_A){return Name_A.name == name2;});
    
li.erase(itr);
write(li,"Remove by name:");

int id2=1000;

itr=find_if(li.begin(),li.end(),
    [id2](const Item& Name_A){return Name_A.iid == id2;});

li.erase(itr);
write(li,"Remove by id:");

    return 0;
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Something went wrong! \n";
    return 2;
}