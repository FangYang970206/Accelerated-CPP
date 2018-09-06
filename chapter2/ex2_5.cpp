#include <iostream>
#include <string>


using std::cin;    using std::endl; 
using std::cout;   using std::string;

int main()
{
    // Square
    cout << "please enter the length of square(int):  ";
    int squ_length;
    cin >> squ_length;
    for(int r=0, c=0; r!=squ_length; r++)
    {
        while(c!=squ_length)
        {
            if (c==0||r==0||c==(squ_length-1)||r==(squ_length-1))
                cout<<"*";
            else
                cout<<" ";
            ++c;
        }
        cout << endl;
        c = 0;
    }
    cout<<endl;
    //rectangle
    cout << "please enter the height of rectangle(int):  ";
    int rec_height;
    cin >> rec_height;
    cout << "please enter the width of rectangle(int):  ";
    int rec_width;
    cin >> rec_width;
    for(int r=0, c=0; r!=rec_height; r++)
    {
        while(c!=rec_width)
        {
            if (c==0||r==0||c==(rec_width-1)||r==(rec_height-1))
                cout<<"*";
            else
                cout<<" ";
            ++c;
        }
        cout << endl;
        c = 0;
    }
    cout<<endl;
    //triangle
    cout << "please enter the length of triangle(int): ";
    int tri_length;
    cin >> tri_length;
    for(int r = 0, c = 0; r!=(tri_length+1)/2; r++)
    {
        while(c!=tri_length)
        {
            if(r==(tri_length-1)/2)
                cout << "*";
            else if (c == (tri_length-1)/2+r || c == (tri_length-1)/2-r)
                    cout << "*";
            else
                cout << " ";
            ++c;
        }
        cout << endl;
        c = 0;
    }
    system("pause");
    return 0;
}