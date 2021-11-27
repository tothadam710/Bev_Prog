#include "../std_lib_facilities.h"


int ga[10] = {};

void init_arr(){

for (int i = 0; i < sizeof(ga); ++i)
{
	ga[i] = pow(2,i);
}

}


void f(int array1[],int db){
	int la[10] = {};



	for (int i = 0; i < db; ++i)
	{
		la[i] = array1[i];
	}

	cout << "The elements of the copied array: ";

	for(int i : la){

		cout << i << " ";
	}

	int* p = new int[db];

     cout << endl;
	for (int i = 0; i < db; ++i)
	{
		p[i] = array1[i];
	}

	cout << "The elements of the copied array(pointer): ";

	for (int i = 0; i < db; ++i)
	{
		cout << p[i] << " ";
	}

	delete[] p;

}

int main(){

init_arr();

int ga_size = sizeof(ga)/sizeof(ga[0]);


f(ga,ga_size);

cout <<endl;

int aa[10] = {};
int aa_size = sizeof(aa)/sizeof(aa[0]);

for (int i = 0; i < 10; ++i)
{
	aa[i] = tgamma(i+1);
}

f(aa,aa_size);

return 0;	
}
