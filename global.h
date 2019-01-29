#include <iostream>
#include <string>
#include <vector>

using namespace std;

int menuPrincipal()
{
	int opcion;
   
	do{
    	cout<<endl<<"Menu Principal"<<endl;
		cout<<"----------------------------------"<<endl;
		cout<<"|\t 1 - Clientes \t \t |"<<endl;
		cout<<"|\t 2 - Cuentas Bancarias \t |"<<endl;
		cout<<"|\t 3 - Movimientos \t |"<<endl;
		cout<<"|\t 4 - Transacciones \t |"<<endl;
		cout<<"|\t 5 - Salir \t \t |"<<endl;
		cout<<"----------------------------------"<<endl;
		cout<<endl<<"Opcion: ";
		cin>>opcion;
	}while (opcion < 1);
	
   return opcion;
}

void getOpcion(int opcion);
