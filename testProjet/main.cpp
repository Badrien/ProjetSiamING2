#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <conio.h>
using namespace std;


int main()
{
    //on déclare une map bidimentionnel en imbriquant deux map
    std::map<char, std::map<char, char> > mymap;

    for(char a = 65; a < 70; a++)
    {
        for(char i = 0; i < 5; i++)
        {
            mymap[a][i] = 254;
            cout << mymap[a][i];
        }
        cout<<endl;
    }


    /*if (mymap.find(9) != mymap.end() && mymap[9].find(2) != mymap[9].end()) {
        std::cout << "My map contains a value for [9][2]" << std::endl;
    } else {
        std::cout << "My map does not contain a value for [9][2]" << std::endl;
    }*/


    return 0;
}
