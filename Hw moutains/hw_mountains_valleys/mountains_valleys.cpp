#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;

int main() {
	// TODO(student): print prompt for input
	
	// TODO(student): read the numbers from standard input

	// TODO(student): validate input (and reprompt on invalid input)

	// TODO(student): compute and display solution

	int a ;

	int b ;

	cout << "Enter numbers 10 <= a <= b < 10000: ";
	

	cin >> a;

	cin >> b;

	
	bool loop_check = is_valid_range(a, b);


	while (loop_check == false)
	{
		cout << "Invalid Input" << endl;

		cout << "Enter numbers 10 <= a <= b < 10000: ";

		cin >> a;

		cin >> b;

		loop_check = is_valid_range(a, b);
		
	}


	
	count_valid_mv_numbers(a, b);



	
	return 0;
}