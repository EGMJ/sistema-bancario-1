#include "global.h"
#include "clientes.h"
#include "cuentas.h"
#include "movimientos.h"
#include "transacciones.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void getOpcion(int opcion)
{
	do{
		switch(opcion)
		{
			case 1:
				system("cls");
				clientes();			
			break;
			
			case 2:
				system("cls");
				cuentas();
			break;
		
			case 3:
				system("cls");
				movimientos();
			break;
		
			case 4:
				system("cls");
				transacciones();
			break;
			
			case 5:
				system("cls");
				cout<<endl<<"Muchas Gracias por utilizar nuestro servicio"<<endl;
				exit(0);	
			break;
			default:
				system("cls");
				cout<<"Opcion no disponible"<<endl;	
				getOpcion(menuPrincipal());
		}
	}while(opcion < 1);
}

int main(int argc, char** argv) {
	
	getOpcion(menuPrincipal());
	return 0;
}
