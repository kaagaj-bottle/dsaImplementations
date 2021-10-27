#include <iostream>
#include <vector>
#include <cstring>
#include <string>



int main()
{
    
    std::string s;
    std::cout<<"string: ";
    std::getline(std::cin,s);
    char* str=new char[s.size()+1];
    std::strcpy(str,s.c_str());
    bool isValid=true;
    char curParenthesis,checkParenthesis;
    std::vector<char> pStack;
    for (int i = 0; i < s.size(); i++)
    {
        if(!isValid)
        {
            break;
        }
        curParenthesis=str[i];
        if(curParenthesis=='{'||curParenthesis=='['||curParenthesis=='(')
        {
            pStack.push_back(curParenthesis);
        }
        if(curParenthesis=='}'||curParenthesis==']'||curParenthesis==')')
        {
            if(pStack.size()>0)
            {
                checkParenthesis=pStack.back();
                switch (curParenthesis)
                {
                case '}':
                    if(!(checkParenthesis=='{'))
                    {
                        isValid=false;
                    }
                    else
                    {
                        pStack.pop_back();
                    }
                    break;
                case ']':
                    if(!(checkParenthesis=='['))
                    {
                        isValid=false;
                    }
                    else
                    {
                        pStack.pop_back();
                    }
                    break;
                case ')':
                    if(!(checkParenthesis=='('))
                    {
                        isValid=false;
                    }
                    else
                    {
                        pStack.pop_back();
                    }
                    break;
                
                default:
                    break;
                }

            }
            else
            {
                isValid=false;
            }
        }
    }
    if(pStack.size()>0)
    {
        isValid=false;
    }
    if(isValid)
    {
        std::cout<<"valid string";

    }
    else
    {
        std::cout<<"invalid string";
    }
    std::cin.get();
    return 0;

}






