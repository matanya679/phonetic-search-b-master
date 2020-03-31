#include <iostream>
#include <string>

#ifndef PHONETIC_FINDER_24032020_2216_H
#define PHONETIC_FINDER_24032020_2216_H
namespace phonetic
{
    bool rule_i_with_y(char a, char b);
    bool rule_o_with_u(char a, char b);
    bool rule_d_with_t(char a, char b);
    bool rule_s_with_z(char a, char b);
    bool rule_c_with_k_and_q(char a, char b);
    bool rule_j_with_g(char a, char b);
    bool rule_b_with_f_and_p(char a, char b);
    bool rule_v_with_w(char a, char b);
    bool matchWithRules(char a, char b);
    bool compareWordWithRules(std::string wordFromText, std::string word);
    std::string matchingWordInText(std::string text, std::string word);
    bool moreThanOneWord(std::string word);
    bool spacesOnlyWord(std::string word);
    bool validWord(std::string text,std::string word);
    std::string removeUnessarySpaces(std::string word);
    std::string find(std::string text, std::string word);

}
#endif