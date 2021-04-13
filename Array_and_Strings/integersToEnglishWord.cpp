/*
Integer to English Words

Solution
Convert a non-negative integer num to its English words representation.

 

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Example 4:

Input: num = 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
 

Constraints:

0 <= num <= 231 - 1
*/

class Solution {
    string m_ones_map[21];
    string m_tens_map[10];
    string m_thousand_map[10];
public:
    void init()
    {
        m_ones_map[0] = "";
        m_ones_map[1] = "One";
        m_ones_map[2] = "Two";
        m_ones_map[3] = "Three";
        m_ones_map[4] = "Four";
        m_ones_map[5] = "Five";
        m_ones_map[6] = "Six";
        m_ones_map[7] = "Seven";
        m_ones_map[8] = "Eight";
        m_ones_map[9] = "Nine";
        m_ones_map[10] = "Ten";
        m_ones_map[11] = "Eleven";
        m_ones_map[12] = "Twelve";
        m_ones_map[13] = "Thirteen";
        m_ones_map[14] = "Fourteen";
        m_ones_map[15] = "Fifteen";
        m_ones_map[16] = "Sixteen";
        m_ones_map[17] = "Seventeen";
        m_ones_map[18] = "Eighteen";
        m_ones_map[19] = "Nineteen";
        m_ones_map[20] = "Twenty";
    
        m_tens_map[0] = "";
        m_tens_map[1] = "";
        m_tens_map[2] = "Twenty";
        m_tens_map[3] = "Thirty";
        m_tens_map[4] = "Forty";
        m_tens_map[5] = "Fifty";
        m_tens_map[6] = "Sixty";
        m_tens_map[7] = "Seventy";
        m_tens_map[8] = "Eighty";
        m_tens_map[9] = "Ninety";
        
        m_thousand_map[0] = "";
        m_thousand_map[1] = "Thousand";
        m_thousand_map[2] = "Million";
        m_thousand_map[3] = "Billion";
        m_thousand_map[4] = "Trillion";
        
        
    }
    string convertTens(int num)
    {
        if(num <=20)
            return m_ones_map[num];
        
        string tens_str;
        int digit_tens = num/10;
        int digit_ones = num%10;
        
        tens_str = m_tens_map[digit_tens];
        if( digit_ones > 0 )
            tens_str = tens_str + " " + m_ones_map[digit_ones];
        
        return tens_str;
        
    }
    string convertThousand(int num)
    {
        string sz;
        int digit_hundred = num /100;
        int tens_number = num - digit_hundred*100;
        if(digit_hundred > 0)
            sz = m_ones_map[digit_hundred] + " Hundred";
        
        if(tens_number  && digit_hundred)
            sz += " ";
      
        sz += convertTens(tens_number);
        
        return sz;
        
    }
    string numberToWords(int num) {
        init();
        int level = 0;
        string sz = "" ;
        bool space = false;
        
        int no = num/1000;
        int divisor = 1;
        if(num == 0)
            return "Zero";
        
        while(no > 0)
        {
            no = no/1000;
            divisor*=1000;
            
            level++;
        }
        while(level >  0)
        {
            no = num / divisor;
            
            if(no > 0)
            {
                if(space)
                    sz+=" ";
                
                 sz += convertThousand(no) + " " + m_thousand_map[level];
            }
            
            num = num % divisor;
            divisor /= 1000;
            level --;
            space = true;
            
        }
        if(space && num > 0)
            sz += " ";
        
        sz += convertThousand(num);
        
        return sz;
        
    }
};