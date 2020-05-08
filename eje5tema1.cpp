#include <iostream>
#include <string>
#include <fstream>
#include <array>
using namespace std;


struct datos
{
    string nombre;
    int edad;
    char sexo;
    char arte;
    char deporte;
    char musica;
    char libros;
};

void leer(datos &a,ofstream &o)
{
        cout<<"introducir nombre "<<endl;
        getline(cin,a.nombre);
        o<<a.nombre;
        o<<'\n';
    while(a.nombre!="")
    {
        cout<<"introducir edad"<<endl;
        cin>>a.edad;
        cin.ignore();
        o<<a.edad;
        o<<'\n';
        cout<<"introducir sexo (M/F)"<<endl;
        cin>>a.sexo;
        cin.ignore();
        o.put(a.sexo);
        o<<'\n';
        cout<<"introducir gusto por arte(S/N)"<<endl;
        cin>>a.arte;
        cin.ignore();
        o.put(a.arte);
        o<<'\n';
        cout<<"introducir gusto por deporte(S/N)"<<endl;
        cin>>a.deporte;
        cin.ignore();
        o.put(a.deporte);
        o<<'\n';
        cout<<"introducir gusto por musica(S/N)"<<endl;
        cin>>a.musica;
        cin.ignore();
        o.put(a.musica);
        o<<'\n';
        cout<<"introducir gusto por libros(S/N)"<<endl;
        cin>>a.libros;
        cin.ignore();
        o.put(a.libros);
        o<<'\n';
        cout<<"introducir nombre "<<endl;
        getline(cin,a.nombre);
        o<<a.nombre;
    }
}
int main()
{
    datos persona;
    ofstream fo;                        //declaro manejador
    const string b="PERSONAS.txt";
    fo.open(b.c_str());
    leer(persona,fo);
    fo.close();
return 0;
}

