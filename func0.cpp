#include "middle_str.h"
#include <iostream>
#include <string>


bool itc_isDigit(unsigned char c){
    return (48 <= c && c <= 57);
}

unsigned char itc_toUpper(unsigned char c){
    if(97 <= c && c <= 122){
        return c - 32;
    }
    return c;
}

unsigned char itc_changeCase(unsigned char c){
    if(97 <= c && c <= 122){
        return c - 32;
    }
    if(65 <= c && c <= 90){
        return c + 32;
    } 
    return c;
}

bool itc_compare(std::string s1, std::string s2){
    return s1 == s2;
}

int itc_countWords(std::string str){
    int w = 0;
    bool f = false;
    for(long long i = 0; str[i] != '\0'; i++){
        if((str[i] < 65 || str[i] > 122 || (str[i] >= 91 && 96 >= str[i])) && str[i] != ' '){
            f = true;
        }
        if(str[i] == ' ' && f == false){
            w += 1;
        }
        if(str[i] == ' ' && f == true){
            f = false;
        }
    }
    return f ? w : w + 1;
}
