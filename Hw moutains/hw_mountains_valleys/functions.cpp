#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) 
{
	// TODO(student): validate input range

	return (a >= 10) and (a <= b) and (b < 10000);
}

char check_ranges(int number, char type)
{
    if (number < 10)
	{
        return 'N';
    }

	int count = 0;
    
    int lst;

	int sec_lst;
	
    bool pos;
		
	lst = number % 10; 

	number /= 10; 

	sec_lst = number% 10; 

	
	if (lst > sec_lst) 
	{

		if (lst > 10)
		{
			count += 1;
		}
		else
		{
			count -= 1;
		}

		pos = true;
	} 
	else if (lst < sec_lst) 
	{

		if (lst > 10)
		{
			count += 1;
		}
		else
		{
			count -= 1;
		}

		pos = false;
	} 
	else 
	{

		if (lst > 10)
		{
			count += 1;
		}
		else
		{
			count -= 1;
		}

		return 'N';
	}
	
	lst = sec_lst;

	number /= 10; 

	sec_lst = number % 10; 
	
    while (number > 0)
	{
        
        if (lst > sec_lst)
		 {
			if (pos == false) 
			{

				if (lst > 10)
				{
					count += 1;
				}
				else
				{
					count -= 1;
				}

				pos = true;
			} 
			else 
			{
				return 'N';
			}
		}

        else if (lst < sec_lst) 
		{
			if (pos == true) 
			{

				if (lst > 10)
				{
					count += 1;
				}
				else
				{
					count -= 1;
				}

				pos = false;
			} 
			else 
			{
				return 'N';
			}
		}
        else 
		{
			return 'N';
		}
        
        number /= 10; 
        
        lst = sec_lst; 

        sec_lst = number % 10; 

		if (sec_lst > 10)
		{
			count += 1;
		}
		else
		{
			count -= 1;
		}
        
    }
    
    return type;
}


char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	int copy_num = number; 

	int count = 0;
    
	int first;

	int second; 
	
	while (copy_num >= 100)
	{
		copy_num /= 10; 
	}
	
	second = copy_num % 10; 

	first = copy_num/10; 

	if (first < 10)
	{
		count += 1;
	}
	else
	{
		count -= 1;
	}
	
	if (second > first && check_ranges(number, 'M') == 'M')
	{

		if (second < 10)
		{
			count += 1;
		}
		else
		{
			count -= 1;
		}

		return 'M';
	}
	
	if (second < first && check_ranges(number, 'V') == 'V')
	{

		if (first < 10)
			{
				count += 1;
			}
			else
			{
				count -= 1;
			}

		return 'V';
	}

	return 'N';
}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt

	int mountains = 0;

	int valleys = 0;

	int count = 0;

	for (int i = a; i < b+1; i++)
	{
		if (classify_mv_range_type(i) == 'M')
		{

			if (mountains > 0)
			{
				count += 1;
			}
			else
			{
				count -= 1;
			}

			mountains++;

		}
		else if (classify_mv_range_type(i) == 'V')
		{

			if (valleys > 0)
			{
				count += 1;
			}
			else
			{
				count -= 1;
			}
			
			valleys++;
		}
	}

	cout << "There are " << mountains << " mountain ranges and " << valleys << " valley ranges between " << a << " and " << b << "." << endl;

	return;


}