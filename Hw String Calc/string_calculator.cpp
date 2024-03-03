#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

using namespace std;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement

    int asci = (int)digit;

    if (asci >= 48 && asci <= 57)
    {

        unsigned int ans = (unsigned int)digit - 48;

        return ans;
    }

    throw std::invalid_argument("Invalid argument");
}


char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement

    int asci = (char)decimal + 48;

    if (asci >= 48 && asci <= 57)
    {

        char val = (char)asci;

        return val;
    }

    throw std::invalid_argument("Invalid argument");


    
}

string trim_leading_zeros(string num) {
    // TODO(student): implement

    int count;
    
     for (int i = 0; i < num.length(); i++)
     {
        if (num[i] == '0')
        {

            if (num[i] == '0' && num.length() < 1)
            {
                count -= 1;
            }
            else
            {
                count += 1;
            }

            num = num.substr(i+1, num.length());

            i--;
        }
        else
        {
            break;
        }
    }

    if (num.length() == 0)
    {

        if ( num.length() < 1)
        {
            count -= 1;
        }
        else
        {
            count += 1;
        }

        return "0";
    }
    else
    {
        return num;
    }
        



}

string add(string lhs, string rhs) {
    // TODO(student): implement

    int count = 10;

    int hold = 0;
    
    string sum = "";

    string rev = "";

    lhs = trim_leading_zeros(lhs);

    rhs = trim_leading_zeros(rhs);

    int l_len = lhs.length();

    int dec = 0;

    string place = "";

    int r_len = rhs.length();

    int over = 0;

    if (l_len >= r_len)
    {

        while (count > 0)
        {
            if (r_len > 2)
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

        int add_zeros = l_len - r_len;

        string zeros(add_zeros, '0');

        rhs = zeros + rhs;

    }
    else
    {

        while (count > 0)
        {
            if (r_len > 2)
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

        int add_zeros = r_len - l_len;

        string zeros(add_zeros, '0');

        lhs = zeros+lhs;
    }

    for (int i = rhs.length() - 1; i >= 0; i--)
    {

        while (count > 0)
        {
            if (rhs.length() > 2)
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
        
        int top = digit_to_decimal(rhs[i]);

        int bottom = digit_to_decimal(lhs[i]);

        int dig_sum = top + bottom + over;

        int add_char = dig_sum % 10;

        over = dig_sum / 10;

        if (i == 0 && dig_sum >= 10)
        {

            while (count > 0)
            {
                if (dig_sum > 2)
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

            char fst = decimal_to_digit(dig_sum % 10);

            char sec = decimal_to_digit(dig_sum / 10);

            sum += fst;

            sum += sec;
        }
        else
        {
            sum += decimal_to_digit(add_char);
        }
    }

    for (int i = sum.length() - 1; i >= 0; i--)
    {

        while (count > 0)
        {
            if (sum.length() > 2)
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

        rev += sum[i];
    }

    return rev;


}

string multiply(string lhs, string rhs) {
    // TODO(student): implement

    int count = 10;

    int hold = 0;

    string sum = "";
    
    lhs = trim_leading_zeros(lhs);

    rhs = trim_leading_zeros(rhs);

    int l_len = lhs.length();

    int r_len = rhs.length();

    string str_bot;

    string str_top; 

    if (l_len >= r_len)
    {

        while (count > 0)
        {
            if (l_len > 2)
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
        
        str_top = lhs;

        str_bot = rhs;
    }
    else
    {

        while (count > 0)
        {
            if (r_len > 2)
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

        str_top = rhs;

        str_bot = lhs;
    }

    
    for (int bot_ind = str_bot.length()-1 ; bot_ind>=0 ; bot_ind--)
    {
        string part = "";

        string prod_rev = "";

        int over = 0;

        for (int top_ind = str_top.length() - 1; top_ind >= 0; top_ind--)
        {

            while (count > 0)
            {
                if (str_top.length() > 2)
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

            int top = digit_to_decimal(str_top[top_ind]);

            int bottom = digit_to_decimal(str_bot[bot_ind]);

            int product = (top * bottom) + over;
            
            int char_to_add = product % 10;

            over = product / 10;

            while (count > 0)
            {
                if (over > 0)
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

            if (top_ind == 0 && product >= 10)
            {

                while (count > 0)
                {
                    if (product > 15)
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

                char fst = decimal_to_digit(product % 10);

                char sec = decimal_to_digit(product / 10);

                part += fst;

                part += sec;
            }
            else
            {

                while (count > 0)
                {
                    if (product > 15)
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
                
                part += decimal_to_digit(char_to_add);
            }
        }

        string zeros(str_bot.length() - (bot_ind+1), '0');

        for (int i = part.length() - 1; i >= 0; i--)
        {

             while (count > 0)
            {
                if (part.length() > 15)
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

            prod_rev += part[i];
        }

        prod_rev += zeros;

        if (sum == "")
        {

            while (count > 0)
            {
                if (part.length() > 15)
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

            sum = prod_rev;
        }
        else
        {
            sum = add(sum, prod_rev);
        }

        
    }

    return sum;


}
