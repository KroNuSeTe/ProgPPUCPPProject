#include <iostream>

using namespace std;

int main()
{
    int value = 0;
    string valor;
    cout<<"Inserta un numero del 1 al 3: ";
    cin>>value;
    switch(value){
        case 1:
            valor = "uno";
            break;
        case 2:
            valor = "dos";
            break;
        case 3:
            valor = "tres";
            break;    
    }
    cout<<"El valor literal es: "<<valor;

    // ------------------- Error ---------------------
    /* switch (valor) {
        case "uno":
            cout<<"El valor introducido es "<<valor;
            break;
        case "dos":
            cout<<"El valor introducido es "<<valor;
            break;
        case "tres":
            cout<<"El valor introducido es "<<valor;
            break;
    }*/
    //------------------------------------------------
    
    // the switch parameter cant be an string
    
}