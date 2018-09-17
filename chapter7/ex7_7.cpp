#include "xref.h"


using namespace std;


int main()
{
    map<string, vector<int> > ret = xref_pro(cin);

    for(map<string, vector<int> >::const_iterator it = ret.begin();
        it != ret.end(); it++){
            cout << it->first << " occurs on ";
            string s = it->second.size()==1? "line: " : "lines: ";
            cout << s;
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