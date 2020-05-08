#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    const unsigned int cant_nums = 5;
    const string fichero = "datos.txt";
    int num;
    ifstream f_ent;
    f_ent.open(fichero.c_str());
    f_ent >> num;
    for (unsigned i = 0; i < cant_nums; i++)
    {
        cout << num << endl;
        f_ent >> num;
    }
    f_ent.close();
    return 0;
}
