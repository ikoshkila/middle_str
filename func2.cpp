#include "middle_str.h"
#include <iostream>
#include <string>



bool itc_isIp(std::string str){
    int cnum = 0;
    int sum = 0;
    int k = 1;
    for(long long i = itc_len(str) - 1; i >= 0; i--){
        if((str[i] < '0' || str[i] > '9') && str[i] != '.'){
            std::cout << "n";
            return 0;
        }
        else{
            if(str[i] == '.'){
                if(sum > 255){
                    return 0;
                }
                cnum++;
                k = 1;
                sum = 0;
            }
            else{
                sum += (str[i] - '0')*k;
                k *= 10;
            }
        }
    }
    return cnum == 3 ? 1 : 0;
}

std::string itc_DecToBin(std::string str){
    std::string out;
    for(long long i = 0; i < itc_len(str); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            int num = 0;
            for(i; str[i] >= '0' && str[i] <= '9'; i++){
                num *= 10;
                num += (str[i]-'0');
            }
            std::string o;
            while(num != 0){
                char a = (num % 2) + '0';
                o = a + o;
                num /= 2;
            }
            i--;
            out += o;
        }
        else{
            out += str[i];
        }
    }
    return out;
}

std::string itc_decToBase(int num, int base){
    std::string out;
    while(num != 0){
        char a = (num % base) + '0';
        if(a > '9'){
            a = a - ':' + 'A';
        }
        out = a + out;
        num /= base;
    }
    return out;
}
