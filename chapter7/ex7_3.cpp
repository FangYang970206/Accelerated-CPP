#include "xref.h"


using namespace std;


int main()
{
    //xref_pro add find function
    map<string, vector<int> > ret = xref_pro(cin);

    for(map<string, vector<int> >::const_iterator it = ret.begin();
        it != ret.end(); it++){
            cout << it->first << " occurs on lines: ";
            vector<int>::const_iterator line_it = it->second.begin();
            cout << *line_it;
            ++line_it;
            while(line_it != it->second.end()){
                cout << ", " << *line_it;
                ++line_it;
            }
            cout << endl;
        }
        system("pause");
        return 0;
}