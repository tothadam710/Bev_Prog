#include "../std_lib_facilities.h"

using namespace std;


 ostream& print_array10(ostream& os,int* a){

 	cout <<"The elements of the array(using print_array function): [";

 	for(int i = 0;i<10;i++){
 		os <<  a[i] << " ";
 	}	

 	 cout << "]" << endl;

 	return os;

 }


//7.feladat
  ostream& print_array(ostream& os,int* a,int n){

 	cout <<"The elements of the array(using print_array function): [";

 	for(int i = 0;i<n;i++){
 		os <<  a[i] << " ";
 	}	

 	 cout << "]" << endl;

 	return os;

 }


 


 ostream& print_vector(ostream& os,vector<int> vec){

 	cout <<"The elements of the vector: [";

 	for(int i = 0;i<vec.size();++i){
 		os <<  vec[i] << " ";
 	}	

 	 cout << "]" << endl;

 	return os;

 }


 

 void init_array(int * ar,int length){
 	for(int i = 0;i<length;i++){
 		
 			ar[i] = pow(2,i);		
 	}

 }


 void copy(int* first,int* second){
 	for(int i = 0;i<10;i++){
 		
 			first[i] = second[i];		
 	}

 }


 




int main(){



//1-2-3. feladat

	cout <<"The elements of the array: [";

int* arr= new int[10];



for(int i = 0;i<10;i++){

	cout << arr[i] << " ";
}

cout << "]" << endl;

delete[] arr;

//4.feladat
print_array10(cout,arr);

//5.feladat

cout << endl;

cout <<"The elements of the  2nd array: [";

int* arr2 = new int[10] {100,101,102,103,104,105,106,107,108,109};

for(int i = 0;i<10;i++){

	cout << arr2[i] << " ";
}

cout << "]" << endl;

//6.feladat

cout <<"The elements of the  3rd array: [";

int* arr3 =  new int[11] {100,101,102,103,104,105,106,107,108,109,110};

for(int i = 0;i<11;i++){

	cout << arr3[i] << " ";
}

cout << "]" << endl;






//8.feladat

cout <<"The elements of the  5th array: [";

int* arr4  = new int[20] {100,101,102,103,104,105,106,107,108,
			  109,110,111,112,113,114,115,116,117,118,119};

for(int i = 0;i<20;i++){

	cout << arr4[i] << " ";
}

cout << "]" << endl;


//9.feladat

delete arr2;
delete arr3;
delete arr4;


//10


    vector<int>vektor;
    for (int i = 100; i<110; ++i)
        vektor.push_back(i);
    print_vector(cout,vektor);

    
    vector<int> vektor2;
    for (int i = 100; i<111; ++i)
        vektor2.push_back(i);
    print_vector(cout,vektor2);

    
    vector<int>vektor3;
    for (int i = 100; i<120; ++i)
        vektor3.push_back(i);
    print_vector(cout,vektor3);


    


//Masodik Drill:

//1

int a = 7;

int* p1 = &a; 

//2

cout << "The variable a's value is " << a << " and pointing to " << p1<<" memory address "<<endl;

//3
int* array1 = new int[7];

init_array(array1,a);

int* p2 = array1;

//4


print_array(cout,array1,7);
cout << "The memory address of array1 is: "<<p2<<endl;;



//5

int * p3 = p2;


//6
p2 = p1;


//7
p2 = p3;


//8
cout << " p1: " << p1 << endl;
cout << "*p1: " << *p1 << endl;


//9
delete[] p2;



//10


init_array(array1,10);

p1 = array1;


//11

p2 = new int[10];

//12

copy(p1,p2);


//13


vector<int> v1;
vector<int> v2;

for (int i = 0; i < 10; i++)
 	{
 		v1.push_back(pow(i,2));
 	}

 	for (int i = 0; i < v1.size(); i++)
 	{
 		v2.push_back(v1[i]);
 	}



delete[] p2;





return 0;

}
