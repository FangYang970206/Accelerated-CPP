#include "grammar.h"


using namespace std;


int main()
{
    vector<string> sentence = gen_sentence(read_Grammar());
    vector<string>::const_iterator it = sentence.begin();
    if(!sentence.empty()){
        cout << *it;
        ++it;
    }
    while(it != sentence.end()){
        cout << " " << *it;
        ++it;
    }
    cout << endl;
    system("pause");
    return 0;
}