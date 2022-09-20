#include <iostream>
#include <string>
#include <limits>
#include "func.hpp"
#pragma once

bool IsInt(char chr)
{
    char nums[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    for (int i = 0; i < 10; i++) if (chr == nums[i]) return true;
    return false;
}

class Parser
{
    public:
        void parse(vector< Token > TokensRes)
        {
            for (int i = 0; i < TokensRes.size(); i++)
            {
                Tokens::TokenList tmpToken = TokensRes[i].TokenRes;
                char tmpValue = TokensRes[i].ValRes;

                switch (tmpToken)
                {
                    case Tokens::Function:
                        fun = tmpValue;
                        break;
                    case Tokens::Value:
                        val = tmpValue;
                        break;
                    case Tokens::EndFun:
                        switch (fun)
                        {
                            // ВВОД-ВЫВОД

                            // вывод символа
                            case 'a':
                                cout << val;
                                break;
                            // ввод текста с консоли
                            case 'b':
                                getline(cin, text);
                                break;
                            // вывод текста с консоли
                            case 'c':
                                cout << text;
                                break;
                            // вывод новой строки
                            case 'd':
                                cout << endl;
                                break;
                            
                            // МАТЕМАТИКА

                            // вывод результатов
                            case 'e':                                
                                cout << "Result: " << num << endl;
                                break;
                            // +
                            case 'f':
                                if (IsInt(val)) {
                                    num += val-'0';
                                    break;
                                }
                                num += (int) val;
                                break;
                            // -
                            case 'g':
                                if (IsInt(val)) {
                                    num -= val-'0';
                                    break;
                                }
                                num -= (int) val;
                                break;
                            // /
                            case 'h':
                                if (val=='0') {
                                    num = numeric_limits<double>::infinity()*0;
                                }
                                if (IsInt(val)) {
                                    num /= val-'0';
                                    break;
                                }
                                num /= (int) val;
                                break;
                            // *
                            case 'i':
                                if (IsInt(val)) {
                                    num *= val-'0';
                                    break;
                                }
                                num *= (int) val;
                                break;
                            


                            // вывод символа
                            default:
                                cout << val;
                                break;
                        }
                        break;
                    
                    default:
                        break;
                }
            }
            
        }
    private:
        string text;
        double num = 0.0;
        char val;
        char fun;
};
