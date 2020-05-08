#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <cstdlib>
using namespace std;


struct Datos
{
    string nombre;
    int edad;
    char sexo;
    char arte;
    char deporte;
    char musica;
    char libros;
};


bool leerPersona(Datos &persona)
{

    cout<<"introduce nombre de la persona"<<endl;
    getline(cin,persona.nombre);
    if ((persona.nombre).size()==0)
    {
        return false;
    }
    else
    {
        cout<<"introduce edad"<<endl;
        cin>>persona.edad;
        cout<<"introduce sexo"<<endl;
        cin>>persona.sexo;
        cout<<"introduce arte"<<endl;
        cin>>persona.arte;
        cout<<"introduce deporte"<<endl;
        cin>>persona.deporte;
        cout<<"introduce musica"<<endl;
        cin>>persona.musica;
        cout<<"introduce libros"<<endl;
        cin>>persona.libros;
        cin.ignore();
        return true;
    }
}

void meterPersona(ofstream & fichero,Datos persona)
{
    fichero<<persona.nombre<< endl;
    fichero<< persona.edad << endl;
    fichero<< persona.sexo << endl;
    fichero<< persona.arte << endl;
    fichero<< persona.deporte << endl;
    fichero<< persona.musica << endl;
    fichero<< persona.libros << endl;
}

void guardarPersonas(ofstream &fichero)
{
    Datos persona;
    bool ok = leerPersona(persona);
    while (ok)
    {
      meterPersona(fichero,persona);
      ok=leerPersona(persona);
    }
}

bool obtenerPersona(ifstream & fichero,Datos &persona)
{
    getline(fichero,persona.nombre);
    if (fichero.fail())
        return false;
    else
    {
        fichero >> persona.edad;
        fichero >> persona.sexo;
        fichero >> persona.arte;
        fichero >> persona.deporte;
        fichero >> persona.musica;
        fichero >> persona.libros;
        fichero.ignore();
        return true;
    }
}

bool compatibles(Datos persona1,Datos persona2)
{
    int contador=0;
    bool ok=persona1.sexo != persona2.sexo;
    if (persona1.arte==persona2.arte) contador++;
    if (persona1.deporte==persona2.deporte) contador++;
    if (persona1.musica==persona2.musica) contador++;
    if (persona1.libros==persona2.libros) contador++;
    return (ok && (contador>=3));
}

void generarAceptados(ifstream &ficheroEntrada, ofstream &ficheroSalida, Datos aspirante)
{

    Datos candidato;
    bool ok=obtenerPersona(ficheroEntrada,candidato);

    while (ok)
    {
        if (compatibles(candidato,aspirante))
        {   cout << candidato.nombre << " es aceptado" << endl;
            meterPersona(ficheroSalida,candidato);
        }
        ok=obtenerPersona(ficheroEntrada,candidato);
    }
}

int main()
{
    Datos persona,aspirante,prueba;
    ifstream ficheroEntrada;
    ofstream ficheroSalida;                        //declaro manejador
    const string nombreFicheroPersonas="PERSONAS.DAT";
    const string nombreFicheroAceptados="ACEPTADOS.DAT";

    ficheroSalida.open(nombreFicheroPersonas.c_str());
    if (ficheroSalida.fail())
        cout << " Error" << endl;
    else
    {
        guardarPersonas(ficheroSalida);
        ficheroSalida.close();
        ficheroEntrada.open(nombreFicheroPersonas.c_str());

        if (ficheroEntrada.fail())
            cout << " Error" << endl;
        else
        {
            ficheroSalida.open(nombreFicheroAceptados.c_str());
            if (ficheroSalida.fail())
                cout << " Error" << endl;
            else
            {
                cout<<"introducir aspirante"<<endl;
                leerPersona(aspirante);
                generarAceptados(ficheroEntrada,ficheroSalida,aspirante);
                ficheroSalida.close();
            }
            ficheroEntrada.close();
        }
    }
return 0;
}
