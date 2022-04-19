#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <stdexcept>
#include <algorithm>
#include<iterator>
#include<numeric>

using namespace std;

void fill_vec(istream& is, vector<double>& vec_d)
{
for (double d; is >> d; ) vec_d.push_back(d);
}

int main()
try{

vector<double> Vec_Dub;
string Input_Name {"Input2.txt"};
ifstream ist {Input_Name};
if (!ist) runtime_error("can't open input file "+ Input_Name);
fill_vec(ist,Vec_Dub);
//2.
cout<<"Vector elements:\n";
for(auto& x : Vec_Dub)
  	cout<<x<<"\n";
vector<int> Vec_Int (Vec_Dub.size());
copy(Vec_Dub.begin(),Vec_Dub.end(),Vec_Int.begin());  
cout<<"Vector elements (Vec_Dub[i],Vec_Int[i]):\n";
for (int i = 0; i <  Vec_Dub.size(); ++i)
cout<<"("<<Vec_Dub[i]<<","<<Vec_Int[i]<<") \n";
    //5.	
double Vec_Dub_Sum = accumulate(Vec_Dub.begin(),Vec_Dub.end(),0.0);
cout<<"Vec_Dub elements sum: "<<Vec_Dub_Sum<<"\n";

    //6.
double Vec_Int_Sum = accumulate(Vec_Int.begin(),Vec_Int.end(),0);
cout<<"Vec_Dub-Vec_Int difference: "<<Vec_Dub_Sum-Vec_Int_Sum<<"\n";

    //7.
reverse(Vec_Dub.begin(),Vec_Dub.end());
cout<<"Reverse:\n";
for(auto& x : Vec_Dub)
cout<<x<<"\n";

    //8. 
double mean = Vec_Dub_Sum/Vec_Dub.size();
cout<<"Mean value of Vec_Dub: "<<mean<<"\n";
//9.
vector<double> Vec_Doub_2;
copy_if(Vec_Dub.begin(),Vec_Dub.end(),back_inserter(Vec_Doub_2),
 	[mean](auto& Vec_Doub_Entry){ return Vec_Doub_Entry<mean;});

cout<<"Vec_Doub_2 elements:\n";
for(auto& x : Vec_Doub_2)
cout<<x<<"\n";

    //10.
sort(Vec_Dub.begin(),Vec_Dub.end());
cout<<"Vec_Dub sort:\n";
for(auto& x : Vec_Dub)
  	cout<<x<<"\n";

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