#include <iostream>
#include "ex6_2.h"


using std::cout;    using std::endl;
using std::vector;  using std::string;


int main(){
    string str3 = "dan{http://baidu.com}sdjjsadhbhaskj{https://youtube.com}drg"; 
    cout << "test url: ";
    if(find_urls(str3).size() == 2){
        cout << "success" << endl;
    }else{
        cout << "fail" << endl;
    }
    system("pause");
    return 0;
}