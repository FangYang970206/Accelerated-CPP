#include <iostream>
#include <string>


using std::cin;    using std::endl; 
using std::cout;   using std::string;

int main()
{
    cout<<"please enter you first name:";
    string name;
    cin>>name;
    cout << "please enter the size of pad: ";
    int pad;
    cin >> pad;
    const string greeting = "Hello, " + name + "!";
    // const int pad = 4; 
    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2;
    cout<<endl;

    for(int r = 0; r != rows; r++)
    {   
        string::size_type c = 0;
        while(c != cols)
        {
            if(r==(rows-1)/2&&c==1)
            {
                cout<<string(pad, ' ')<<greeting<<string(pad, ' ');
                c += greeting.size()+2*pad;
            }
            else
            {
                if(c==0||r==0||r==rows-1||c==cols-1){
                    cout<<"*";
                    ++c;
                }
                    
                else if(c==1&&r!=(rows-1)/2){
                    cout<< string(cols-2, ' ');
                    c += cols-2;
                }
                    
                
            }
        }
        cout<<endl;
    }

    system("pause");
    return 0;

}