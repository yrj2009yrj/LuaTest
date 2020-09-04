#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

using floatVector = vector<float>;

int main(int argc, char* argv[])
{
    //char * in_file = argv[1];
    //ifstream in(in_file);
    ifstream in("inputData.txt");
    
    floatVector in_vector;
    floatVector out_vector;

    string s;
    while (in >> s)
    {
        in_vector.push_back(stof(s));
    }

    ///////////////////////////////////////////////////////////////////
    floatVector::iterator it = in_vector.begin();
    for (; it != in_vector.end(); ++it)
    {
        out_vector.push_back(*it);
    }

    /// ///////////////////////////////////////////////////////////////
    ofstream out("outputData.txt");
    it = out_vector.begin();
    for (; it != out_vector.end(); ++it)
    {
        out << *it << " "; //Ð´ÈëÊý¾Ý
    }

    return 0;
}