#include "middle_str.h"
#include <iostream>
#include <string>


long long itc_len(std::string str){
    long long out = 0;
    for(int i = 0; str[i] != '\0'; i++)
        out++;
  
    return out;
}

std::string itc_maxCharWord(std::string str){
    int cs = 0;
    for(long long i = 0; str[i] != '\0'; i++){
        if(str[i] == ' ')cs++;
    }
    if(cs == 0){
        return "error";
    }
    long long max = 0;
    std::string t, out;
    for(long long i = 0; str[i] != '\0'; i++){
        if((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)){
            t += str[i];
        }
        else if(str[i] == ' '){
            long long len = itc_len(t);
            if(len > max){
                max = len;
            }
            out = t;
            t = "";
        }
    }
    return itc_len(t) > max ? t : out;
}

char itc_sameChar(std::string str){
    for(long long i = 0; str[i] != '\0'; i++){
        if((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)){
            for(long long j = i+1; str[j] != '\0'; j++){
                if(str[i] == str[j]){
                    return str[i];
                }
            }
        }
    }
    return '-';
}

bool itc_isFirstInSecond(std::string s1, std::string s2){
    bool out = 1;
    for(long long i = 0; i < itc_len(s2); i++){
        if(s2[i] == s1[0]){
            for(long long j = 0; j < itc_len(s1); j++){
                if(s2[i+j] != s1[j]){
                    out = 0;
                    break;
                }
            }
            if(out){
                return out;
            }
            out = 1;
        }
    }
    return 0;
} 

std::string itc_Cezar(std::string str, int k){
    std::string out;
    for(long long i = 0; i < itc_len(str); i++){
        if(str[i] >= 65 && str[i] <= 90){
            out += (65 + (str[i] - 13 + k) % 26);
        }
        else if(str[i] >= 97 && str[i] <= 122){
            out += (97 + (str[i] - 19 + k) % 26); 
        }
        else{
            return "error";
        }
    }
    return out;
}

std::string itc_rmFreeSpace(std::string str){
    long long i = 0;
    std::string out;
    bool first = 1;
    int c = 0;
    for(i; i < itc_len(str); i++){
        if(str[i] == ' '){
            c++;
        }
        else{
            if(c >= 1){
                if(first){
                    first = 0;
                }
                else{
                    out += ' ';
                }
                c = 0;
            }
            out += str[i];
        }
    }
    return out;
}
