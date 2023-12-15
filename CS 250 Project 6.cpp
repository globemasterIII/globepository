/*
 Name: Michael B
 Date: 14 Dec 23
 Project: #6
 Description:
 Create a recursion C++ program that will determine if our string is a palidome or not
 */

#include <iostream>

using namespace std;

bool Palindrome(const string& wrd) 
{
    for (size_t i = 0; i < wrd.length() / 2; ++i)
    {

        char char1 = wrd[i];
        char char2 = wrd[wrd.length() - 1 - i];

        if (char1 >= 'a' && char1 <= 'z')
        {
            char1 -= ('a' - 'A');
        }

        if (char2 >= 'a' && char2 <= 'z')
        {
            char2 -= ('a' - 'A');
        }

        if (char1 != char2)
        {
            return false;
        }
    }
    return true;
}








int main()
{
    try
    {
        cout << "Enter a string with letters only. Do not add spaces, numbers, or special characters: ";
        string response;
        cout << endl;
        cin >> response;
        
        for (char r : response)
            
        {

            if (!((r >= 'A' & r <= 'Z') || (r >= 'a' & r <= 'z')))
                
            {
                throw invalid_argument("Do not add spaces, numbers, or special characters.");
            }
                
        }
        
        if (Palindrome(response))
        {
            cout << "Your string is a palindrome." << endl;
        }
        
        else
            
        {
            cout << "Your string is not a palindrome." << endl;
        }
        
    } 
        
catch (const invalid_argument& err)
        
    {
        cout << "Error: " << err.what() << endl;
    }
    return 0;
}

