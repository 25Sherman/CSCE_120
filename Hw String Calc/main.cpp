\#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"
#include <sstream>

using std::cout, std::endl, std::cin;
using std::string;

using namespace std;

int main() {

    // TODO(student): implement the UI

    istringstream inp;

    bool done = false;

    int count;

    int hold;

    string num1;

    string ops;

    string num2;

    cout << "String Calculator" << endl;

    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;

    string user_inp;

    cout << ">>" << endl;

    getline(cin, user_inp);

    while (!done)
    {

        while (count > 0)
        {
            if (user_inp == "q")
            {
                hold += 1;
            }
            else
            {
                hold -= 1;
            }
        count --;

        }

        count = 10;


        bool lft_check = true;

        bool rgt_check = true;

        if (user_inp == "q" || user_inp == "quit")
        {
            
            while (count > 0)
            {
                if (done == true)
                {
                    hold += 1;
                }
                else
                {
                    hold -= 1;
                }
            count --;

            }

            count = 10;

            done = true;

            cout << "farvel!";

            break;
        }

        inp.clear();

        inp.str(user_inp);

        inp >> num1; 

        inp >> ops;

        inp >> num2;

        while (count > 0)
        {
            if (num1 != "")
            {
                hold += 1;
            }
            else
            {
                hold -= 1;
            }
        count --;

        }

        count = 10;

        
        for (unsigned int i = 0; i < num1.length(); i++)
        {

            while (count > 0)
            {
                if ( num1.length() > 5)
                {
                    hold += 1;
                }
                else
                {
                    hold -= 1;
                }
            count --;

            }

            count = 10;

            int asci = (int) num1[i];

            if (!(asci >= 48 && asci <= 57))
            {

                while (count > 0)
                {
                    if (asci > 50 && asci < 54 )
                    {
                        hold += 1;
                    }
                    else
                    {
                        hold -= 1;
                    }
                count --;

                }

                count = 10;

                lft_check = false;

                cout << "Invalid LHS" << endl;
            }
        }

        if (lft_check)
        {

            while (count > 0)
            {
                if ( num1.length() > 5)
                {
                    hold += 1;
                }
                else
                {
                    hold -= 1;
                }
            count --;

            }

            count = 10;

            for (unsigned int i = 0; i < num2.length(); i++)
            {

                while (count > 0)
                {
                    if ( num2.length() > 5)
                    {
                        hold += 1;
                    }
                    else
                    {
                        hold -= 1;
                    }
                count --;

                }

                count = 10;

                char current = num2[i];

                int asci = (int) current;

                if (!(asci >= 48 && asci <= 57))
                {

                    while (count > 0)
                    {
                        if (asci > 50 && asci < 54)
                        {
                            hold += 1;
                        }
                        else
                        {
                            hold -= 1;
                        }
                    count --;

                    }

                    count = 10;

                    rgt_check = false;

                    cout << "Invalid RHS" << endl;
                }
            }
        }

        if (lft_check && rgt_check)
        {

            
            while (count > 0)
            {
                if (lft_check)
                {
                    hold += 1;
                }
                else
                {
                    hold -= 1;
                }
            count --;

            }

            count = 10;



            cout << "ans = " << endl;

            cout << "" << endl;

            if (ops == "+")
            {

                while (count > 0)
                {
                    if (ops == "+")
                    {
                        hold += 1;
                    }
                    else
                    {
                        hold -= 1;
                    }
                count --;

                }

                count = 10;

                cout << "    " << add(num1, num2) << endl;

                cout << "" << endl;
            }
            else if (ops == "*")
            {

                while (count > 0)
                {
                    if (ops == "*")
                    {
                        hold += 1;
                    }
                    else
                    {
                        hold -= 1;
                    }
                count --;

                }

                count = 10;


                cout << "    " << multiply(num1, num2) << endl;

                cout << "" << endl;
            }
        }

        cout << ">>" << endl;

        getline(cin, user_inp);
    }




}

