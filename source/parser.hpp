#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include "func.hpp"
#pragma once

// checking if a character is a number
bool IsInt(char chr)
{
    char nums[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    for (int i = 0; i < 10; i++) if (chr == nums[i]) return true;
    return false;
}


class SuperType
{
    public:
        char* type_;
        string val_;

        SuperType(char* typev, string val)
        {
            type_ = typev;
            val_  = val;
        }
};

class Parser
{
    public:
        void parse(vector< Token > TokensRes)
        {
            // walk through the tokens
            for (int i = 0; i < TokensRes.size(); i++)
            {
                // get this token
                Tokens::TokenList tmpToken = TokensRes[i].TokenRes;
                // get value of token
                char tmpValue = TokensRes[i].ValRes;

                // checking token
                switch (tmpToken)
                {
                    case Tokens::Function:
                        // set function name
                        fun = tmpValue;
                        break;
                    case Tokens::Value:
                        // set value of function
                        val = tmpValue;
                        break;
                    case Tokens::EndFun:
                        // cheking function
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
                                vals.push_back(SuperType("string", text));
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
                                cout << "\nresult of mathematical calculations: " << num << endl;
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
                            // clear
                            case 'j':
                                num = 0.0;
                                break;

                            // ПЕРЕМЕННЫЕ
                            // math to var
                            case 'k':
                                vals.push_back(SuperType("num", to_string(num)));
                                break;
                            case 'l':
                                vals.clear();
                                break;
                            // sel
                            case 'm':
                            {
                                int tmp_int_VarName;

                                if (IsInt(val)) tmp_int_VarName = val-'0';
                                else tmp_int_VarName = (int) val;
                                if (vals.size()<tmp_int_VarName) tmp_int_VarName = ceil(vals.size()/tmp_int_VarName)-1;

                                if (vals.size()>0) {
                                    cout << 124 << tmp_int_VarName << endl;
                                    SuperType tmp_var = vals[tmp_int_VarName];
                                    cout << tmp_var.val_;
                                    sel_var_name = tmp_int_VarName;
                                };
                                
                                
                                break;
                            }


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
        int sel_var_name;
        vector<SuperType> vals;
};
