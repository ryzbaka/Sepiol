#include <iostream>
#include <fstream>
#include <string>
using std::cerr;
using std::cout;
using std::ifstream;
using std::string;

int main(int argc, char **argv)
{
    ifstream indata;
    indata.open("./hello.sepiol");
    if (!indata)
    {
        //file could not be opened.
        cerr << "Error: File could not be opened.\n";
    }
    // string myText;
    // while (getline(indata, myText))
    // {
    //     cout << myText << "\n";
    // }
    // indata.close();
    char someChar = 0;
    while (indata.get(someChar))
    {
        cout << (int)someChar << "\n";
    }
    return 0;
}