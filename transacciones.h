
struct TTransaccion
{
	string numeroTransaccion;
	string cedulaCliente;
	string numeroCuenta;
	int codigoMovimiento;
	string fecha;
	double importe;
};

vector<TTransaccion> lstTransaccion;

void crearTransaccion();
void consultarTransaccion();
bool validarCedula(string cedula);
bool validarNumeroTransaccion(string numeroTransaccion);
bool validarNumeroCuenta(string numeroCuenta);
bool validarCuentaCliente(string cedula, string numeroCuenta);
bool validarMovimientos(int codigoMovimiento);

int mostrarOpcionesTransacciones() 
{
   int opcion;

	do{
    	cout<<endl<<"Opciones de Transacciones"<<endl;
		cout<<"------------------------------------------"<<endl;
		cout<<"|\t 1 - Registrar Transaccion \t |"<<endl;
		cout<<"|\t 2 - Consultar Transaccion\t |"<<endl;
		cout<<"|\t 3 - Menu Principal \t \t |"<<endl;
		cout<<"|\t 4 - Salir \t \t \t |"<<endl;
		cout<<"------------------------------------------"<<endl;
		cout<<endl<<"Opcion: ";
		cin>>opcion;
	}while (opcion < 1);
	
   return opcion;
}

void getOpcionTransaccion(int opcion)
{	
	do{
		switch(opcion)
		{
			case 1:
				crearTransaccion();	
			break;
			
			case 2:
				consultarTransaccion();
			break;
			
			case 3:
				system("cls");
				getOpcion(menuPrincipal());	
			break;
						
			case 4:
				system("cls");
				cout<<endl<<"Muchas Gracias por utilizar nuestro servicio"<<endl;
				exit(0);	
			break;
			
			default:
				system("cls");
				cout<<"Opcion no disponible"<<endl;	
				getOpcionTransaccion(mostrarOpcionesTransacciones());
		}
		
	}while(opcion < 1);
}

void transacciones()
{
	getOpcionTransaccion(mostrarOpcionesTransacciones());
}

void crearTransaccion()
{
	system("cls");
	
	TTransaccion transaccion;
	
	cout<<endl<<"Registrando Nueva transaccion"<<endl;
	int origenMovimiento;
	double total_credito;
	double total_debito;
	double resultado;
	
	do{
		cout<<endl<<"Numero de Transaccion:";
		cin.ignore();
		getline(cin, transaccion.numeroTransaccion);
			
		if(validarNumeroTransaccion(transaccion.numeroTransaccion))
		{
			cout<<"Ya existe una transaccion con este numero..."<<endl
				<<"Ingrese otro numero"<<endl;
		} 
		
	}while(validarNumeroTransaccion(transaccion.numeroTransaccion) == true);
		
	do{
		cout<<endl<<"Cedula del cliente:";
		getline(cin, transaccion.cedulaCliente);
			
		if(validarCedula(transaccion.cedulaCliente) == false)
		{
			cout<<"Cliente no registrado ..."<<endl;
		} 
		
	}while(validarCedula(transaccion.cedulaCliente) == false);
		
	do{
		cout<<endl<<"Numero de Cuenta:";
		getline(cin, transaccion.numeroCuenta);
			
		if(validarNumeroCuenta(transaccion.numeroCuenta) == false)
		{
			cout<<"Cuenta no registrado ..."<<endl;
		} 
		
		if(validarCuentaCliente(transaccion.cedulaCliente,transaccion.numeroCuenta) == false)
		{
			cout<<"Esta cuenta no pertenece al cliente"<<endl;
		}
		
	}while((validarNumeroCuenta(transaccion.numeroCuenta) == false) && validarCuentaCliente(transaccion.cedulaCliente,transaccion.numeroCuenta) == false);
	
	do{
		cout<<endl<<"Codigo de tipo movimiento:";
		cin >> transaccion.codigoMovimiento;
			
		if(validarMovimientos(transaccion.codigoMovimiento) == false)
		{
			cout<<"Transacción no existe.."<<endl;
		} 
		
	}while(validarMovimientos(transaccion.codigoMovimiento) == false);
		
	do{
		cout<<endl<<"Ingrese el monto:";
		cin>>transaccion.importe;
	}while(transaccion.importe < 1);
	
	bool existeMovimiento = false;

	for(vector<TMovimiento>::iterator it = lstMovimiento.begin();  !existeMovimiento && it != lstMovimiento.end(); ++it )
	{
		existeMovimiento = (transaccion.codigoMovimiento == (*it).codigoMovimiento) ? true : false;
			
		if(existeMovimiento)
		{
			origenMovimiento = (*it).origen;
		}					
	}
	
	bool existeCuenta = false;
	
	for(vector<TCuenta>::iterator it = lstCuentas.begin();  !existeCuenta && it != lstCuentas.end(); ++it )
	{
		existeCuenta = transaccion.numeroCuenta.compare( (*it).numeroCuenta ) == 0 ;
			
		if(existeCuenta)
		{
			if(origenMovimiento == 1)
			{
				double resultadoSum;
				resultadoSum = ((*it).totalCredito - (*it).totalDebito);
				
				if(resultadoSum >= transaccion.importe)
				{
					(*it).totalDebito += transaccion.importe;
				}
				else
				{
					cout<<endl<<"Saldo Insuficientes... no se puede procesar la transaccion....";
					(*it).totalDebito += 0;	
				}	
			}
			else
			{
				(*it).totalCredito += transaccion.importe;
			}
		}
	}
	
	lstTransaccion.push_back(transaccion);
	
	system("cls");
	cout<<"Datos creados correctamente...."<<endl;
	
	getOpcionTransaccion(mostrarOpcionesTransacciones());
}

void consultarTransaccion()
{			
	system("cls");				
	cout<<endl<<"Consultar Transaccion"<<endl;
	
	string numeroTransaccion;
	
	if(lstPersonas.size() > 0)
	{
		cout<<endl<<"Introducir numero de transaccion a consultar .:";
		cin.ignore();
		getline(cin,numeroTransaccion); 
								
		bool existe = false;
								
		for(vector<TTransaccion>::iterator it = lstTransaccion.begin();  !existe && it != lstTransaccion.end(); ++it )
		{
			existe = numeroTransaccion.compare( (*it).numeroTransaccion ) == 0 ;
			
			if(existe)
			{
				cout<<endl<<"Numero:" << (*it).numeroTransaccion << endl 
					<< "Cedula Cliente:" << (*it).cedulaCliente << endl 
		 	     	<< "Numero de Cuenta:" << (*it).numeroCuenta << endl
					<< "Codigo de tipo de movimiento: " << (*it).codigoMovimiento<<endl
					<< "Fecha:"<< (*it).fecha<<endl
					<< "Importe:"<< (*it).importe<<endl;
		 	     	
		 	    getOpcionTransaccion(mostrarOpcionesTransacciones());
			}
			else
			{
				system("cls");
				cout<<endl<<"Transaccion no encontrada"<<endl;
				getOpcionTransaccion(mostrarOpcionesTransacciones());
			}
		}
	}
	else
	{
		system("cls");
		cout<<endl<<"No tiene datos registrados"<<endl;
		getOpcionTransaccion(mostrarOpcionesTransacciones());
	}
}

bool validarNumeroTransaccion(string numeroTransaccion)
{
	bool existe = false;
							
	for( vector<TTransaccion>::iterator it = lstTransaccion.begin();  !existe && it != lstTransaccion.end(); ++it )
	{
		existe = numeroTransaccion.compare( (*it).numeroTransaccion ) == 0 ;
	}
	
	return existe;
}


bool validarCedula(string cedula)
{
	bool existe = false;
							
	for( vector<TPersona>::iterator it = lstPersonas.begin();  !existe && it != lstPersonas.end(); ++it )
	{
		existe = cedula.compare( (*it).cedula ) == 0 ;
	}
	
	return existe;
}

bool validarNumeroCuenta(string numeroCuenta)
{
	bool existe = false;
							
	for( vector<TCuenta>::iterator it = lstCuentas.begin();  !existe && it != lstCuentas.end(); ++it )
	{
		existe = numeroCuenta.compare( (*it).numeroCuenta ) == 0 ;
	}
	
	return existe;
}

bool validarCuentaCliente(string cedula, string numeroCuenta)
{
	bool existe = false;
							
	for( vector<TCuenta>::iterator it = lstCuentas.begin();  !existe && it != lstCuentas.end(); ++it )
	{
		if((cedula.compare( (*it).clientes.cedula ) == 0) && (numeroCuenta.compare( (*it).numeroCuenta ) == 0))
		{
			existe = true;
		}
	}
	
	return existe;
}

bool validarMovimientos(int codigo)
{
	bool existe = false;
							
	for(vector<TMovimiento>::iterator it = lstMovimiento.begin();  !existe && it != lstMovimiento.end(); ++it )
	{
		existe = (codigo == (*it).codigoMovimiento ) ? true : false;
	}
	
	return existe;
}
