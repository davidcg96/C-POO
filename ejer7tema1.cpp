#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <cstdlib>
using namespace std;

const int MAX=50;
struct Empresa
{
    unsigned codigo;
    string nombre;
    int exist_actual;
    float precio;
};
typedef array <Empresa,MAX>Indices;

void inicializar(Indices &indice)
{
    for(int i=0;i<MAX;i++)
    {
        indice[i].codigo=0;
        indice[i].nombre="";
        indice[i].exist_actual=0;
        indice[i].precio=0;
    }
}
void mostrar(Indices &indice,unsigned tam)
{
    for(int i=0;i<tam;i++)
    {
        cout<<"codigo "<<indice[i].codigo<<endl;
        cout<<"nombre"<<indice[i].nombre<<endl;
        cout<<"existencias"<<indice[i].exist_actual<<endl;
        cout<<"precio"<<indice[i].precio<<endl;
    }
}
unsigned nuevo_producto(Empresa &producto)
{
    cout<<"introducir codigo producto:"<<endl;
    cin>>producto.codigo;
    cin.ignore();
    if(producto.codigo!=0)
    {
        cout<<"introducir nombre:"<<endl;
        getline(cin,producto.nombre);
        cout<<"introducir codigo existencias actuales:"<<endl;
        cin>>producto.exist_actual;
        cin.ignore();
        cout<<"introducir precio producto:"<<endl;
        cin>>producto.precio;
        cin.ignore();
    }
    return producto.codigo;
}
void meterPersona(ofstream & fichero,Empresa persona)
{
    fichero<<persona.codigo<<endl;
    fichero<<persona.nombre<< endl;
    fichero<< persona.exist_actual << endl;
    fichero<< persona.precio << endl;
}
void generarfichero(ofstream &fich_sal)
{
    Empresa producto;
    unsigned cod=nuevo_producto(producto);
    while(cod!=0)
    {
        meterPersona(fich_sal,producto);
        cod=nuevo_producto(producto);
    }
}
bool obtenerproducto(ifstream &fich,Indices &temporal,unsigned i)
{       unsigned codigo;
        fich>> codigo;

       // fich.clear();
        if(!fich.fail())

        {   temporal[i].codigo=codigo;
            fich.ignore();
            getline(fich,temporal[i].nombre);
            fich >>temporal[i].exist_actual;
            //fich.ignore();
            fich>>temporal[i].precio;
            //fich.ignore();
            return true;
        }
        else return false;
}

unsigned recorrer(ifstream &fich_ent,Indices &a)
{

    unsigned cont=0;
    bool ok=obtenerproducto(fich_ent,a,cont);
    while(ok)
    {

        cont++;
        ok=obtenerproducto(fich_ent,a,cont);
    }
    return cont;
}
void ordenar(Indices &indice, unsigned tam)
{
    Empresa auxiliar;
    int contador,pos,i;
    pos=i=contador=0;
    unsigned codigo;
    while(i<tam-1)
    {
        auxiliar=indice[i];
        codigo=indice[i].codigo;
        while(contador<tam-1)
        {
            if(codigo>indice[contador+1].codigo)
            {
                codigo=indice[contador+1].codigo;
                pos=contador+1;
            }
            contador++;
        }
        if(pos!=0)
        {
            indice[i]=indice[pos];
            indice[pos]=auxiliar;
        }
        i++;
        contador=i;
        pos=0;
    }
}
void meterordenado(ofstream &fichero,Indices &indice,unsigned tam)
{
    for(unsigned i=0;i<tam;i++)
    {
        meterPersona(fichero,indice[i]);
    }
}
void genera(ifstream &fich_ent,ofstream &fich_sal,Indices &indice,string &nombrefichero,int &numero_productos)
{
     inicializar(indice);
    cout<<"introduce nombre del fichero: "<<endl;
    getline(cin,nombrefichero);
    fich_sal.open(nombrefichero.c_str());
    if(fich_sal.fail())
    {
        cout<<"error al abrir fichero"<<endl;
    }
    else
    {
        generarfichero(fich_sal);
        fich_sal.close();
    }

    fich_ent.open(nombrefichero.c_str());
    if(fich_ent.fail())
    {
        cout<<"error al abrir fichero"<<endl;
    }
    else
    {
        numero_productos=recorrer(fich_ent,indice);
        cout<<"contador"<<numero_productos<<endl;
        ordenar(indice,numero_productos);
        mostrar(indice,numero_productos);
        fich_ent.close();
    }
    fich_sal.open(nombrefichero.c_str());
    if(fich_sal.fail())
    {
        cout<<"error al abrir fichero"<<endl;
    }
    else
    {
        meterordenado(fich_sal,indice,numero_productos);
        fich_sal.close();
    }
}
int main()
{
    Indices indice;
    int numero_productos;
    string nombrefichero;
    ifstream fich_ent;
    ofstream fich_sal;

    genera(fich_ent,fich_sal,indice,nombrefichero,numero_productos);
    return 0;
}
