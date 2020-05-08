#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ofstream manejador1;
    string a;
    manejador1.open("prueba.txt");
    getline(cin,a);
    manejador1<<a;
    manejador1.close();


}
