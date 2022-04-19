#include<iostream>
#include<string>
#include <stdexcept>
#include <map>
#include<numeric>

using namespace std;

//5.
void read(map<string,int>& map)
{
string text;
int number;
cin>>text>>number;
map.insert(pair<string,int>(text,number));
}

template <typename First, typename Second>
void write(const map<First,Second>& map)
{
cout<<"Map pairs:\n";
for(const auto& p : map)
    cout<<p.first<<" "<<p.second <<'\n';
}

int main()
try{
    //1.
map<string,int> map_entries;
    
    //2.
map_entries["DVSC"]=1;
map_entries["Ferencvaros"]=2;
map_entries["Videoton"]=4;
map_entries["ZTE"]=3;
map_entries["Kisvarda"]=5;
map_entries["Vamospercs"]=11;
map_entries["DSI"]=50;
map_entries["Kaposvar"]=12;

write(map_entries);	//Write-out
map_entries.erase(map_entries.begin(),map_entries.end());	//Erase
cout<<"Erease ok! \n";
write(map_entries);	//re-write-out

cout<<"Give 10 string,int pair for map:\n";
while(map_entries.size()!=10)
{
read(map_entries);
}
write(map_entries);
int sum = accumulate(map_entries.begin(),map_entries.end(),0,
[](auto prev_sum, auto &map_entries_entry){return prev_sum+map_entries_entry.second;});
cout<<"Map enty integers sum: "<<sum<<"\n";
map<int,string> Map_Entry_Sum;

for(auto& mapentry: map_entries)
    Map_Entry_Sum[mapentry.second] = mapentry.first;
write(Map_Entry_Sum);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Something went wrong! \n";
    return 2;
}