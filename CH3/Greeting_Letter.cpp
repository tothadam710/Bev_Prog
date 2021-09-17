#include "std_lib_facilities.h"


int main()

{	

	string first_name,friend_name,own_name;
	char friend_sex = 0;
	int age;

	

	cout << "Please enter your first name(followed by enter):\n";
	cin >>  first_name;
	own_name = first_name;

	cout << "Hello," << first_name <<"!\n";
	

	cout << "Enter the name of the person you want to write to:\n";
	cin >> first_name;

	cout << "Dear " << first_name << ",\n\n";
	cout << "How are you?\n";
	cout << "Im so glad to hear about you.\n";
	cout << "Hope you will wrtite back to me.\n";

	cout << "Enter the name of another friend:\n";
	cin >> friend_name;
	cout << "Have you seen " << friend_name << " lately?\n\n";

	cout << "Please enter " << friend_name << "'s sex.(m=male/f=female):\n";
	cin >> friend_sex;

	if((friend_sex == 'm') or (friend_sex == 'M'))
	{
		cout << "If you see " << friend_name << " please ask him to call me.\n";
	}

	else if((friend_sex == 'f') or (friend_sex == 'F'))
	{
		cout << "If you see " << friend_name << " please  ask her to call me.\n";
	}


	else
	{
		cout << "You must choose male or female!\n";
	}


	cout << "Please enter the age of the recipient:";
	cin >> age;

	cout << "If I hear you just had a birthday and you are " << age << " years old.\n\n";

	if((age <=0) || (age >= 110))
	{
		simple_error("You're kidding!\n");
	}

	else

	{
		if(age < 12)
		{	
			age++;
			cout <<  "Next year you will be " << age << ".\n\n";
		}
		

		else if(age == 17)
		{
			cout << "Next year you will be able to vote.\n\n";
		}

		else if(age > 70)
		{
			cout << "I hope you are enjoying the the retriement.\n\n";
		}

	}


	

	cout << "Yours Sincenery,\n\n";

	cout <<  own_name <<  ".\n\n\n";
	return 0;

}
