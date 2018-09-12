#include <iostream>
#include "ex6_0.h"


using std::cout;    using std::endl;
using std::vector;  using std::string;


int main(){
    string str1 = "this str is created for testing split function";
    string str2 = "fanggnaf"; //test palindrome function
    string str3 = "dan{http://baidu.com}sdjj"; // test find_urls function
    cout << "test vcat: ";
    vector<string> ret1 = split(str1);
    vector<string> ret2 = frame(ret1);
    if(vcat(ret1, ret2).size() == (ret1.size()*2+2)){
        cout << "success" << endl;
    }else{
        cout << "fail" << endl;
    }
    cout << "test split: ";
    if(split(str1).size() == 8){
        cout << "success" << endl;
    }else{
        cout << "fail" << endl;
    }
    cout << "test palindrome: ";
    if(is_palindrome(str2)){
        cout << "success" << endl;
    }else{
        cout << "fail" << endl;
    }
    cout << "test url: ";
    if(find_urls(str3).size() == 1){
        cout << "success" << endl;
    }else{
        cout << "fail" << endl;
    }

    system("pause");
    return 0;
}