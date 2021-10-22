#include <iostream>
#include <>

using namespace std;

void swap_v(int a,int b){
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << a << b << "\n";
}

void swap_r(int& a,int& b){
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << a << b << "\n";
}


/*void swap_cr(const int& a, const int& b){
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << a << b << "\n";
}*/


int main(){

	int x = 7;
	int y = 9;
	const int cx = 7;
	const int cy = 9;


	swap_r(x,y);	
	swap_v(7,9);
	//swap_cr(cx,cy); won't complie cuz' they declared as consts 
	swap_v(7.7,9.9);
	//swap_r(7.7,9.9);

	double dx = 7.7;
	double dy = 9.9;

	swap_v(dx,dy);
	//swap_r(7.7,9.9);


	

	return 0;


}