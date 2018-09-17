//refer https://github.com/bitsai/book-exercises/blob/master/Accelerated%20C%2B%2B/chapter07/
#include <sstream>
#include "xref.h"


using namespace std;

int main()
{
    map<string, vector<int> > ret = xref_pro(cin);
    int max_length = 20;

    for(map<string, vector<int> >::const_iterator it = ret.begin();
       it != ret.end(); ++it) {
    stringstream ss;

    ss << it->first << " occurs on line(s): ";

    vector<int>::const_iterator line_it = it->second.begin();

    ss << *line_it;

    ++line_it;

    while (line_it != it->second.end()) {
        ss << ", " << *line_it;
        ++line_it;
    }

    string output = ss.str();

    for (string::size_type i = 0; i != output.size(); ++i) {

        cout << output[i];
      
        if ((i + 1) % max_length == 0)
	        cout << endl;
    }

    cout << endl;
  }

    system("pause");
    return 0;
}
