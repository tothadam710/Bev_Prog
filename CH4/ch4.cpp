#include "std_lib_facilities.h"

//We had to change it thats why I commented it.

/*void expr(double elso,double masodik){
	if(elso>masodik){
		cout << "The smaller value is: " << masodik << "\n";
		cout << "The larger value is: " << elso << "\n";
		
		if((elso - masodik < 0.01)){
			cout << "The numbers almost equal\n";
		}
	}


	else if(elso<masodik){
		cout << "The smaller value is: " << elso << "\n";
		cout << "The larger value is: " << masodik << "\n";
		
		if((masodik - elso < 0.01)){
			cout << "The numbers almost equal\n";
		}
	}

	else{
		cout << "The numbers are equal\n";		
	}
}*/





double metric(double number,string u){

	constexpr double cm = 0.01;
	constexpr double in = 0.0254;
	constexpr double ft = 0.3048;


	if(u=="cm"){
		return number * cm;
	}

	else if(u=="in"){
		return number * in;
	}


	else if(u=="ft"){
		return number * ft;
	}

	else if(u=="m"){
		return number;
	}

	else{
		return 0;
	}


	return 0;
}


void kiiras(double s,int d,double lg,double sm){


	cout << "The sum converted to meter: " << s << "\n"; 
	cout << "The amount of the items: " << d << "\n";
	cout << "The largest number: " << lg << "\n";
	cout << "The smallest number: " << sm << "\n";

}


void sorting(vector<double> v){

	sort(v.begin(),v.end());

		cout << "The elements of the vector: [";

		for (int i = 0; i < v.size(); ++i)
		{
			cout  << v[i] << ";";
		}

		cout << "]";


}


int main()

{
	double num1,num2,sum;
	double largest = 0,smallest = 0;
	
	string unit;
	int db = 0;

	vector<double> vector_1;


	
	
	cout << "Please type a number and if you want ot terminate type '|' to the end of it:\n";


	while(cin >> num1 >> unit ){

		

		if(unit == "cm" || unit == "m" || unit == "ft" || unit == "in"){

		db++;

		}

		//cout << "Please type 2 numbers and if you want ot terminate type '|' to the end of it:\n";
	
		//expr(num1,num2);


		if (smallest == 0 && largest == 0) {
                smallest = num1;
                largest = num1;
            }



		else if(num1>largest){
			
			largest = num1;

			cout << num1 << " is the largest so far\n";
			
		}

		
		else if(num1 < smallest){
				smallest = num1;
				cout << num1  << " is the smallest so far\n";
				
			}

		
		

		sum = sum + metric(num1,unit);

	
		vector_1.push_back(metric(num1,unit));
		

	}


	
		kiiras(sum,db,largest,smallest);

		sorting(vector_1);

		

	return 0;


}

	

	

	


	


