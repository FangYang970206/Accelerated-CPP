#include "grammar.h"


using namespace std;


int main()
{

    list<string> sentence = l_gen_sentence(read_Grammar());
    list<string>::const_iterator it = sentence.begin();
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