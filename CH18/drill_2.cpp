#include "../std_lib_facilities.h"

vector<int> gv;

// init the gv vector with the pows of 2
void init_gv(){

	for (int i = 0; i < 10; ++i)
	{
		gv.push_back(pow(2,i));
	}

}


//define f void to copy the vectors

void f(vector<int> v){

	vector<int> lv;

	for (int i = 0; i < v.size(); ++i)
	{
		lv.push_back(v[i]);
	}

	cout << "The elements of the lv vector are: ";

	for(int i : lv){
		cout << i << " ";
	}

    vector<int>lv2;

    cout <<endl;

    for (int i = 0; i < lv.size(); ++i)
	{
		lv2.push_back(lv[i]);
	}

	cout << "The elements of the lv2 vector are: ";

	for(int i : lv2){
		cout << i << " ";
	}

}






int main(){

//call the method to init the gv vector

init_gv();


// call the f method
f(gv);

vector<int> vv;

//fill the vector with factorials to 10
for (int i = 0; i < 10; ++i)
{
	vv.push_back(tgamma(i+1));
}

cout << endl;	

cout << "Factorial:" << endl;



//call the f method again with vv vector arg.
f(vv);

cout << endl;	
return 0;
}
