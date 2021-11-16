#include "../std_lib_facilities.h"


double metric(double number, string u) {

	constexpr double cm = 0.01;
	constexpr double in = 0.0254;
	constexpr double ft = 0.3048;


	if (u == "cm") {
		return number * cm;
	}

	else if (u == "in") {
		return number * in;
	}


	else if (u == "ft") {
		return number * ft;
	}

	else if (u == "m") {
		return number;
	}

	else {
		return 0;
	}


	return 0;
}


void print_values(double s, int d, double lg, double sm) {


	cout << "The sum converted to meter: " << s << "\n";
	cout << "The amount of the items: " << d << "\n";
	cout << "The largest number: " << lg << "\n";
	cout << "The smallest number: " << sm << "\n";

}


void original_and_sorting(vector<double> v) {

	cout << "The  original elements of the vector: [";

	for (int i = 0; i < v.size(); ++i)
	{			
			cout << v[i] << ";";

			if (i == v.size() -1 ) {
				cout << v[i];
			}
	}

	cout << "]";

	cout << "\n";

	sort(v.begin(), v.end());

	cout << "The  sorted elements of the vector: [";

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << ";";

		if (i == v.size() - 1) {
			cout << v[i];
		}
	}

	cout << "]";


}


int main()

{
	double num1, num2, sum = 0;
	double largest = 0, smallest = 0;

	string unit;
	int db = 0;

	vector<double> vector_1;




	cout << "Please type a number and if you want ot terminate type '|' to the end of it:\n";


	while (cin >> num1 >> unit) {



		if (unit == "cm" || unit == "m" || unit == "ft" || unit == "in") {

			db++;

		}

		//cout << "Please type 2 numbers and if you want ot terminate type '|' to the end of it:\n";

		//expr(num1,num2);


		if (smallest == 0 && largest == 0) {
			smallest = num1;
			largest = num1;
		}



		else if (num1 > largest) {

			largest = num1;

			cout << num1 << " is the largest so far\n";

		}


		else if (num1 < smallest) {
			smallest = num1;
			cout << num1 << " is the smallest so far\n";

		}




		sum = sum + metric(num1, unit);


		vector_1.push_back(metric(num1, unit));


	}



	print_values(sum, db, largest, smallest);

	original_and_sorting(vector_1);

	

	return 0;


}

	
