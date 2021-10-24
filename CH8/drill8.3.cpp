#include "../std_lib_facilities.h"

// define x namespace with own variable and function
namespace x{

int var;

int print(){
	
	cout << "x's variable: " << var << endl;	 	
	return var;
	}

}

//define y namespace with own variable and function
namespace y {

int var;

int print(){
	cout << "y's variable: " << var << endl;
	return var;
}

}

// define z namespace with own variable and function
namespace z{
int var;

int print(){
	cout << "z's variable: " << var << endl;
	return var;

}


}

int main(){
	//refference to x's variable and function from namespace x
	x::var = 7;
	x::print();

	//using namespace
using namespace y;
	var = 9;
	print();

	
	{
	
	using z::var;
	using z::print;
	var = 11;
	print();

	}

	print();
	x::print();

	return 0;
}
