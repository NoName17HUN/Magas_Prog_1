#include "Matrix.h"
#include "MatrixIO.h"
#include <iostream>
#include <cmath>
#include <cerrno>
#include <complex>
#include <iomanip>

using namespace std;
using namespace Numeric_lib;

int main(){
try{
cout << "sizeof:\n";
cout << "char\t" << sizeof(char) << endl;
cout << "short\t" << sizeof(short) << endl;
cout << "int\t" << sizeof(int) << endl;
cout << "long\t" << sizeof(long) << endl;
cout << "float\t" << sizeof(float) << endl;
cout << "double\t" << sizeof(double) << endl;
cout << "int*\t" << sizeof(int*) << endl;
cout << "double*\t" << sizeof(double*) << endl;
	
cout << "\nMatrix sizes:\n";
Matrix<int> Mat_A(10);
Matrix<int> Mat_b(100);
Matrix<double> Mat_C(10);
Matrix<int, 2> Mat_d(10, 10);
Matrix<int, 3> e(10, 10, 10);
	
cout << "1D int, 10 elem\t\t" << sizeof(Mat_A) << endl;
cout << "1D int, 100 elem\t" << sizeof(Mat_b) << endl;
cout << "1D double, 10 elem\t" << sizeof(Mat_C) << endl;
cout << "2D int, 10*10 elem\t" << sizeof(Mat_d) << endl;
cout << "3D int, 10*10*10 elem\t" << sizeof(Mat_E) << endl;
		
cout << "\nNumber of elements:\n";
cout << "Mat_A:\t" << Mat_A.size() << endl;
cout << "Mat_b:\t" << Mat_b.size() << endl;
cout << "Mat_C:\t" << Mat_C.size() << endl;
cout << "Mat_d:\t" << Mat_d.size() << endl;
cout << "Mat_E:\t" << Mat_E.size() << endl;
	
cout << "\nEnter an integer (outputs the sqrt() of it), if input is null, then exit:\n";
int value;
cin >> value;
while(value != 0){
if(value < 0){
	cout << "Enter a positive number!" << endl;
	cout << "Enter another integer (outputs the sqrt() of it), if input is null, then exit:\n";
	cin >> value;
}else{
cout << "Squareroot of " << value << " is: " << sqrt(value) << endl;
cout << "Enter another integer (outputs the sqrt() of it), if input is null, then exit:\n";
cin >> value;
}
}
	
cin.clear(); //removes error-flags for continued working...
cin.ignore(); //deletes input puffer
	
cout << "\nEnter 10 floats:\n";
Matrix<double> Mat_m(10);
double d2;
for(int i = 0; i < Mat_m.size(); ++i){
	cin >> d2;
	if(!cin) throw runtime_error("Problem reading from cin");
		Mat_m[i] = d2;
}
cout << "Matrix:\n" << Mat_m << '\n';	
int Mat_m2;
int n;
cout << "Multiplication table" << endl; 
cout << "Enter n:";
cin >> n;
cout << "Enter second Mat_m:";
cin >> Mat_m2;	
Matrix<int, 2> mtable(n, Mat_m2);
for(int i = 0; i < n; ++i){
	for(int k = 0; k < Mat_m2; ++k){
		mtable(i, k) = (i+1)*(k+1);
		cout << '\t' <<mtable(i, k);
	}
	cout << '\n';
}

Matrix<complex<double>> mcomp(10);    //complex number
cout << "\nEnter 10 complex numbers (re, im): ";
complex<double> comp;
for(int i = 0; i < 10; ++i){
	cin >> comp;
	if(!cin) throw runtime_error("Problem reading complex numbers");
	mcomp[i] = comp;
}
complex<double> sum;
for(Index i = 0; i < mcomp.size(); ++i){
	sum += mcomp[i]; 
}
cout << "sum: " << sum << '\n';

Matrix<int,2> Mat_m3(2,3);
int in_int;
cout << '\n';
for(int i = 0; i < 2; ++i){
	for(int k = 0; k < 3; ++k){
		cout << "Enter the (" << i+1 << ", " << k+1 << ") element of the 2*3 matrix: ";
		cin >> in_int;
		Mat_m3(i, k) = in_int;
	}
}
for(int i = 0; i < 2; ++i){
	for(int k = 0; k < 3; ++k){
		cout << '\t' <<Mat_m3(i, k);
	}
	cout << '\n';
}
}
catch(exception& e){
	cerr << e.what() << '\n';
	return 1;
}
catch(...){
	cerr << "Unknown exception!" << '\n';
	return 2;
}
}