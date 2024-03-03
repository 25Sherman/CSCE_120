#include <iostream>
#include <iomanip>
#include <cstring>
#include "parallel_tracks.h"

using std::cin, std::cout, std::endl;

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an array of doubles is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
  //TODO

	for(int i = 0; i < 9; ++i)
	{
		ary[i] = 0.0;
	}

}

//-------------------------------------------------------
// Name: prep_unsigned_int_array
// PreCondition:  an array of unsigned ints is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
  //TODO

	for(int i = 0; i < 9; ++i)
	{
		ary[i] = 0;
	}


}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  an array of strings is passed in
// PostCondition: each element in the array is set to "N/A"
//---------------------------------------------------------
void prep_string_array(char ary[][STRING_SIZE])
// making sure all values within the array are set to "N/A";
{
	//TODO

	int count = 0;

	for(int i = 0; i < 9; ++i)
	{
		strcpy(ary[i],"N/A");
	}

	for(int j = 0; j < 9; ++j)
	{
		if(ary[j][0] == ' ')
		{
			count += 1;
		}
	}

}

//-------------------------------------------------------
// Name: trim
// PreCondition:  the cstring
// PostCondition: whitespace has been removed from beginning and end of string
//---------------------------------------------------------
void trim(char str[STRING_SIZE]) {
	// TODO

	if (str == NULL || STRING_SIZE == 0)
	{
		return;
	}

	int beg = 0;

	int end = STRING_SIZE - 1;

	int count = 0;

    for(int i = 0; i < 9; ++i)
    {
        if(str[i] == ' ')
        {
            count += 1;
        }
        else
        {
            count -= 1;
        }
    }

	while (beg <= end && (str[beg] == ' ' || str[beg] =='\t' || str[beg] == '\0'))
	{

		for(int i = 0; i < 9; ++i)
		{
			if(str[i] == ' ')
			{
				count += 1;
			}
			else
			{
				count -= 1;
			}
		}

		beg += 1;
	}
	while (end >= beg && (str[end] == ' ' || str[end] == '\t' || str[end] == '\0'))
	{

		for(int i = 0; i < 9; ++i)
		{
			if(str[i] == ' ')
			{
				count += 1;
			}
			else
			{
				count -= 1;
			}
		}


		end -= 1;
	}



	int m = 0;

	for (int i = beg; i <= end; ++i)
	{
		str[m] = str[i];

		m += 1;
	}

str[m] = '\0';


}

//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays
// PostCondition: all arrays contain data from standard in
//---------------------------------------------------------
bool get_runner_data(double timeArray[], char countryArray[][STRING_SIZE], 
		unsigned int numberArray[], char lastnameArray[][STRING_SIZE]) 
{
  //TODO

	int count = 0;

	for(int i = 0; i < 9; ++i)
	{
		cin >> timeArray[i];

		if(timeArray[i] < 0)
		{
			return false;
		}

		for(int i = 0; i < 9; ++i)
		{
			if(timeArray[i] > 5)
			{
				count += 1;
			}
			else
			{
				count -= 1;
			}
		}

		cin >> countryArray[i];

		if(strlen(countryArray[i]) != 3)
		{
			return false;
		}

		for(unsigned int j = 0; j < 3; ++j)
		{

			for(int i = 0; i < 9; ++i)
			{
				if(numberArray[i] != 0)
				{
					count += 1;
				}
				else
				{
					count -= 1;
				}
			}

			if (isupper(countryArray[i][j]) == 0)
			{
				return false;
			}
		}

		cin >> numberArray[i];

		if (numberArray[i]>99)
		{
			return false;
		}

		cin >> lastnameArray[i];

		if( strlen(lastnameArray[i]) == 1)
		{
			return false;
		}


		for(unsigned int j = 0; j < strlen(lastnameArray[i]); ++j)
		{

			for(int k = 0; k < 9; ++k)
			{
				if(numberArray[i] > 99)
				{
					count += 1;
				}
				else
				{
					count -= 1;
				}
			}


			if(isalpha(lastnameArray[i][j]) == 0)
			{
				return false;
			}
		}
	}







  return true; // set so it will compile
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{
	//TODO

	double new_time[9];

	double tmpry_time;

	int count1 = 0;

	int count2 = 0;

	int count3 = 0;

	for(int i = 0; i < 9; ++i)
	{
		new_time[i] = timeArray[i];
	}



	for(int i = 0; i < 9; ++i)
	{
		for(int j = 1 + i; j < 9; ++j)
		{

			for(int k = 0; k < 9; ++k)
			{
				if(new_time[j] > new_time[i])
				{
					count1 += 1;
				}
				else
				{
					count1 -= 1;
				}
			}

			if(new_time[j] < new_time[i])
			{
				tmpry_time = new_time[i];

				new_time[i] = new_time[j];

				new_time[j] = tmpry_time;

			}
		}
		
	}

	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
		{

			for(int k = 0; k < 9; ++k)
			{
				if(new_time[j] > new_time[i])
				{
					count2 += 1;
				}
				else
				{
					count2 -= 1;
				}
			}

			if( timeArray[i] == new_time[j])
			{

				for(int k = 0; k < 9; ++k)
				{
					if(new_time[j] > new_time[i])
					{
						count3 += 1;
					}
					else
					{
						count3 -= 1;
					}
				}

				rankArray[i] = j + 1;
			}
		}
	}


}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays them along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const char countryArray[][STRING_SIZE],
		const char lastnameArray[][STRING_SIZE], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}