#include <cstdlib>
#include <iostream>
#include <iterator>
#include <list>
#include <time.h>

#include "grammar.h"
#include "xref.h"

using namespace std;

int main() 
{
    srand(time(NULL));
    cout << "gen_sentence" << endl;
    cout << "OutputIterator: "; 
    ostream_iterator<string> out_it(cout, " ");
    gen_sentence(read_Grammar(), out_it);
    cout << endl;
    cout << "back_inserter(sentence): "; 
    list<string> sentence;
    gen_sentence(read_Grammar(), back_inserter(sentence));
    for(list<string>::const_iterator it = sentence.begin(); it != sentence.end(); it++){
        cout << *it << " ";
    }
    cout << endl << "xref" << endl;
    cout << "please enter string lines(exit, use ctrl+z): ";
    my_ostream_iterator<pair<string, vector<int> > > out_it1(cout, " ");
    xref(cin, split, out_it1);
    system("pause");
    return 0;
}