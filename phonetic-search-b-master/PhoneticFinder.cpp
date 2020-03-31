#include "PhoneticFinder.hpp"
#include <iostream>
#include <string>
#include <exception>




namespace phonetic
{
//check letter replacement of i and y and their equavalent capital letters.
    bool rule_i_with_y(char a, char b)
    {
        if ((a == 'i' || a == 'I' || a == 'y' || a == 'Y') && (b == 'i' || b == 'I' || b == 'y' || b == 'Y'))
        {
            return true;
        }
        return false;
    }
//check letter replacement of o and u and their equavalent capital letters.
    bool rule_o_with_u(char a, char b)
    {
        if ((a == 'o' || a == 'O' || a == 'u' || a == 'U') && (b == 'o' || b == 'O' || b == 'u' || b == 'U'))
        {
            return true;
        }
        return false;
    }
//check letter replacement of d and t and their equavalent capital letters.
    bool rule_d_with_t(char a, char b)
    {
        if ((a == 'd' || a == 'D' || a == 't' || a == 'T') && (b == 'd' || b == 'D' || b == 't' || b == 'T'))
        {
            return true;
        }
        return false;
    }
//check letter replacement of s and z and their equavalent capital letters.
    bool rule_s_with_z(char a, char b)
    {
        if ((a == 's' || a == 'S' || a == 'z' || a == 'Z') && (b == 's' || b == 'S' || b == 'z' || b == 'Z'))
        {
            return true;
        }
        return false;
    }
//check letter replacement of c,k,q and their equavalent capital letters.
    bool rule_c_with_k_and_q(char a, char b)
    {
        if ((a == 'c' || a == 'C' || a == 'k' || a == 'K' || a == 'q' || a == 'Q') &&
            (b == 'c' || b == 'C' || b == 'k' || b == 'K' || b == 'q' || b == 'Q'))
        {
            return true;
        }
        return false;
    }
//check letter replacement of j and g and their equavalent capital letters.
    bool rule_j_with_g(char a, char b)
    {
        if ((a == 'j' || a == 'J' || a == 'g' || a == 'G') && (b == 'j' || b == 'J' || b == 'g' || b == 'G'))
        {
            return true;
        }
        return false;
    }
//check letter replacement of b,f,p and their equavalent capital letters.
    bool rule_b_with_f_and_p(char a, char b)
    {
        if ((a == 'b' || a == 'B' || a == 'f' || a == 'F' || a == 'p' || a == 'P') &&
            (b == 'b' || b == 'B' || b == 'f' || b == 'F' || b == 'p' || b == 'P'))
        {
            return true;
        }
        return false;
    }
//check letter replacement of v and f and their equavalent capital letters.
    bool rule_v_with_w(char a, char b)
    {
        if ((a == 'v' || a == 'V' || a == 'w' || a == 'W') && (b == 'v' || b == 'V' || b == 'w' || b == 'W'))
        {
            return true;
        }
        return false;
    }
//check if word from text is match to user word input according to letters rules.
    bool matchWithRules(char a, char b)
    {
		
        if (rule_v_with_w(a, b) || rule_b_with_f_and_p(a, b) || rule_j_with_g(a, b) || rule_c_with_k_and_q(a, b) || rule_s_with_z(a, b) || rule_d_with_t(a, b) || rule_o_with_u(a, b) || rule_i_with_y(a, b))
        {
            return true;
        }
		if(char(std::tolower(a))==char(std::tolower(b)))
		{
			return true;
		}
        return false;
    }
//compare word from text to user text input while considering letters rules. 
    bool compareWordWithRules(std::string wordFromText, std::string word)
    {
        bool match = true;

        for (int i = 0; i < word.length() && match; i++)
        {
            if (wordFromText[i] != word[i])
            {
                if (!matchWithRules(wordFromText[i], word[i]))
                {
                    match = false;
                }
            }
        }
        return match;
    }
 /*
 check if there is a matching word in the text for user word input,if there is the
  program returns it.
*/
    std::string matchingWordInText(std::string text, std::string word)
    {
        try
        {
            std::string tempWord = "";
            for (int i = 0; i < text.length(); i++)
            {
                if (text[i] == ' ')
                {
                    if (tempWord.length() == word.length())
                    {
                        if (compareWordWithRules(tempWord, word))
                        {
                            return tempWord;
                        }
                    }
                    tempWord="";
                }
                else
                {
                    tempWord += text[i];
                }
            }
            throw std::runtime_error("no matching word in text!");
        }
        catch (std::exception &e)
        {
            throw;
        }
    }
}

namespace phonetic
{
 //check word the program recieved from user as input is more than one word.   
    bool moreThanOneWord(std::string word)
    {
        bool oneWord = false;
        bool spaceBetweenWords = false;
        bool atLeastTwoWords = false;
        for (int i = 0; i < word.length() && !atLeastTwoWords; i++)
        {
            if (!oneWord && word[i] != ' ')
            {
                oneWord = true;
            }

            if (oneWord && word[i] == ' ')
            {
                spaceBetweenWords = true;
            }

            if ((oneWord && spaceBetweenWords) && word[i] != ' ')
            {
                atLeastTwoWords = true;
            }
        }

        if (oneWord)
        {
            return atLeastTwoWords;
        }

        return false;
    }
//check if word the program recieved from user as input is only spaces consisted.   
    bool spacesOnlyWord(std::string word)
    {
        bool spaceOnly = true;

        for (int i = 0; i < word.length() && spaceOnly; i++)
        {
            if (word[i] != ' ')
            {
                spaceOnly = false;
            }
        }

        return spaceOnly;
    }
 //check word the program recieved from user as input is valid according to chore instructions.   
    bool validWord(std::string text,std::string word)
    {
        try
        {
            if (word.length() == 0 || phonetic::spacesOnlyWord(word))
            {
                throw std::runtime_error("the input word is empty!");
            }
            else if (phonetic::moreThanOneWord(word))
            {
                throw std::runtime_error("the input consist more than one word!");
            }

            return true;
        }
        catch (std::exception &e)
        {
            throw;
        }
    }
} 

namespace phonetic
{
 //trim word the program recieved from user as input.   
    std::string removeUnessarySpaces(std::string word)
    {
        std::string trimmedWord = "";
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] != ' ')
            {
                trimmedWord += word[i];
            }
        }
        return trimmedWord;
    }
//find if there is a matching word in text with rules
    std::string find(std::string text, std::string word)
    {
        text+=' ';
        try
        {
            if (phonetic::validWord(text,word))
            {
                word = phonetic::removeUnessarySpaces(word);
                return phonetic::matchingWordInText(text,word);
            }
        }
        catch (std::exception &e)
        {
            std::cerr <<"Error Occurred: "<<e.what() << '\n';
            throw e;
        }
        return "";
    }
} // namespace phonetic
