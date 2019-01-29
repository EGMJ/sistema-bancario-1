
struct TCuenta
{
	string numeroCuenta;
	string nombreOficialBancario;
	double totalDebito;
	double totalCredito;
	struct TPersona clientes;
	char estado; 
};

vector<TCuenta> lstCuentas;

void crearCuenta();
void consultarCuenta();
void modificarCuenta();
void consultarCuentaCliente();
bool verificarNumeroCuenta(string numeroCuenta);
bool validarNombreOficial(string nombreOficialBancario);
bool validarClientesRegistrados();
bool validarTamanoCuenta(string numeroCuenta);

int mostrarOpcionesCuentas() 
{
   int opcion;

	do{
    	cout<<endl<<"Opciones de Cuentas"<<endl;
		cout<<"--------------------------------------------------"<<endl;
		cout<<"| \t 1 - Nueva Cuenta \t \t \t |"<<endl;
		cout<<"| \t 2 - Consultar Cuenta\t \t \t |"<<endl;
		cout<<"| \t 3 - Modificar Cuentas \t \t \t |"<<endl;
		cout<<"| \t 4 - Consulta cuentas por clientes \t |"<<endl;
		cout<<"| \t 5 - Menu Principal \t \t \t |"<<endl;
		cout<<"| \t 6 - Salir \t \t \t \t |"<<endl;
		cout<<"--------------------------------------------------"<<endl;
		cout<<endl<<"Opcion: ";
		cin>>opcion;
	}while (opcion < 1);
	
   return opcion;
}

void getOpcionCuenta(int opcion)
{	
	do{
		switch(opcion)
		{
			case 1:
				crearCuenta();	
			break;
			
			case 2:
				consultarCuenta();
			break;
		
			case 3:
				modificarCuenta();
			break;
		
			case 4:
				consultarCuentaCliente();	
			break;
			
			case 5:
				system("cls");
				getOpcion(menuPrincipal());	
			break;
						
			case 6:
				system("cls");
				cout<<endl<<"Muchas Gracias por utilizar nuestro servicio"<<endl;
				exit(0);	
			break;
			
			default:
				system("cls");
				cout<<"Opcion no disponible"<<endl;	
				getOpcionCuenta(mostrarOpcionesCuentas());
		}
		
	}while(opcion < 1);
}

void cuentas()
{
	getOpcionCuenta(mostrarOpcionesCuentas());
}

void crearCuenta()
{
	system("cls");
	
	TCuenta cuenta;
	
	cout<<endl<<"Registrando Nueva Cuenta"<<endl;
	
	if(validarClientesRegistrados() == true)
	{
		do{
			cout<<endl<<"Numero de Cuenta:";
			cin.ignore();
			getline(cin, cuenta.numeroCuenta);
			
			if(verificarNumeroCuenta(cuenta.numeroCuenta))
			{
				cout<<endl<<"Ya existe una cuenta con este numero..."<<endl
					<<"Ingrese otro numero"<<endl;
			} 
			
			if(validarTamanoCuenta(cuenta.numeroCuenta) == false)
			{
				cout<<endl<<"El numero de la cuenta debe ser mayor o igual a 6 digitos"<<endl;
			}
		
		}while((verificarNumeroCuenta(cuenta.numeroCuenta) == true) || (validarTamanoCuenta(cuenta.numeroCuenta) == false));
		
		do{
			cout<<endl<<"Nombre del Oficial Bancario:";	
			getline(cin, cuenta.nombreOficialBancario);
			
			if(validarNombreOficial(cuenta.nombreOficialBancario) == false)
			{
				cout<<endl<<"El nombre debe contener 4 o mas caracteres"<<endl;
			}
			
		}while(validarNombreOficial(cuenta.nombreOficialBancario) == false);
	 	
		cout<<endl<< "Cedula"<<'\t'<< "Nombre"<<'\t'<< "Apellido"<<'\t'<<endl;
		cout<< "-----------------------------------------------\n";
								
		for( vector<TPersona>::iterator it = lstPersonas.begin();  it != lstPersonas.end(); ++it )
		{
			cout<< (*it).cedula << '\t' 
				<< (*it).nombre << '\t' 
				<< (*it).apellido;
			cout<<endl; 
		}
			
		int count = 0;
		string selectCedula;
			
		do
		{
			cout<<endl<<"Para seleccionar un cliente, escriba su # de cedula...."<<endl;
			getline(cin, selectCedula);
				
			bool existe = false;
									
			for( vector<TPersona>::iterator it = lstPersonas.begin();  !existe && it != lstPersonas.end(); ++it )
			{
				existe = selectCedula.compare( (*it).cedula ) == 0 ;
					
				if(existe)
				{
			 		cuenta.clientes.nombre 		= (*it).nombre;
			 		cuenta.clientes.apellido 	= (*it).apellido;
			 		cuenta.clientes.cedula 		= (*it).cedula;
			 		cuenta.clientes.estado 		= (*it).estado;
			 		count++;
				}
				else
				{
					cout<<endl<<"Cliente no registrado"<<endl;
				}
			}
		}while(count == 0);
				 	
		do{
			cout<<endl<<"Estado [A-Activo]:";
			cin>>cuenta.estado;
		}while(cuenta.estado != 'A');
		
		cuenta.totalCredito = 0.00;
		cuenta.totalDebito  = 0.00;
		
		lstCuentas.push_back(cuenta);
		
		system("cls");
		cout<<"Cuenta creada correctamente...."<<endl;
		
		getOpcionCuenta(mostrarOpcionesCuentas());
	}
	else
	{
		system("cls");
		cout<<endl<<"No tienes clientes registrados...."<<endl;
		cout<<"Registre los clientes para poder registrar ctas bancarias..."<<endl;
		getOpcionCuenta(mostrarOpcionesCuentas());
	}
}

void consultarCuenta()
{			
	system("cls");				
	cout<<endl<<"Consultar Cuenta"<<endl;
	
	string numeroCuenta;
	
	if(lstCuentas.size() > 0)
	{
		cout<<endl<<"Introducir el numero de cuenta para consultar:";
		cin.ignore();
		getline(cin,numeroCuenta); 
								
		bool existe = false;
								
		for(vector<TCuenta>::iterator it = lstCuentas.begin();  !existe && it != lstCuentas.end(); ++it )
		{
			existe = numeroCuenta.compare( (*it).numeroCuenta ) == 0 ;
			
			if(existe)
			{
				string estado;
				estado = ((*it).estado == 'A') ? "A -> Activo" : "I -> Inactivo";
				
				cout<<endl<<"Numero de Cuenta:" << (*it).numeroCuenta << endl 
					<< "Cliente:" << (*it).clientes.nombre<<" "<<(*it).clientes.apellido<<endl
					<< "Nombre Oficial Bancario:" << (*it).nombreOficialBancario << endl 
					<< "Total Debito:" << " $"<<(double)(*it).totalDebito<<endl
					<< "Total Credito:" << " $"<<(double)(*it).totalCredito<<endl
					<< "Estado: " << estado<<endl;
		 	     	
		 	    getOpcionCuenta(mostrarOpcionesCuentas());
			}
			else
			{
				system("cls");
				cout<<endl<<"Cta Bancaria no registrada"<<endl;
				getOpcionCuenta(mostrarOpcionesCuentas());
			}
		}
	}
	else
	{
		system("cls");
		cout<<endl<<"No tiene datos registrados"<<endl;
		getOpcionCuenta(mostrarOpcionesCuentas());
	}
}

void modificarCuenta()
{
	cout<<endl<<"Modificar Cta Bancaria"<<endl;
	string numeroCuenta;
		
	if(lstCuentas.size() > 0)
	{
		cout<<endl<<"Introducir numero de cuenta a modificar .:";
		cin.ignore();
		getline(cin, numeroCuenta); 
						
		bool existe = false;
		
		for(vector<TCuenta>::iterator it = lstCuentas.begin();  !existe && it != lstCuentas.end(); ++it )
		{
			existe = numeroCuenta.compare( (*it).numeroCuenta ) == 0 ;
			
			if (existe)
			{
         		do
				{
					cout<<endl<<"Nombre del Oficial Bancario:";	
					getline(cin, (*it).nombreOficialBancario);
					
					if(validarNombreOficial((*it).nombreOficialBancario) == false)
					{
						cout<<"El nombre debe contener 4 o mas caracteres"<<endl;
					}
					
				}while(validarNombreOficial((*it).nombreOficialBancario) == false);
				
				string selectCedula;
				cout<<endl<< "Cedula"<<'\t'<< "Nombre"<<'\t'<< "Apellido"<<'\t'<<endl;
				cout<< "-----------------------------------------------\n";
										
				for( vector<TPersona>::iterator ot = lstPersonas.begin();  ot != lstPersonas.end(); ++ot )
				{
					cout<< (*ot).cedula << '\t' 
						<< (*ot).nombre << '\t' 
						<< (*ot).apellido;
					cout<<endl; 
				}
				
				int count = 0;
					
				do
				{
					cout<<endl<<"Para seleccionar un cliente, escriba su # de cedula...."<<endl;
					getline(cin, selectCedula);
						
					bool existe = false;
											
					for( vector<TPersona>::iterator ot = lstPersonas.begin();  !existe && ot != lstPersonas.end(); ++ot )
					{
						existe = selectCedula.compare( (*ot).cedula ) == 0 ;
							
						if(existe)
						{
					 		(*it).clientes.nombre 		= (*ot).nombre;
					 		(*it).clientes.apellido 	= (*ot).apellido;
					 		(*it).clientes.cedula 		= (*ot).cedula;
					 		(*it).clientes.estado 		= (*ot).estado;
					 		count++;
						}
						else
						{
							cout<<"Cliente no registrado"<<endl;
						}
					}
				}while(count == 0);
		
				do{
					cout<<endl<<"Estado [A-Activo | I-Inactivo]:";
					cin>>(*it).estado;
				}while((*it).estado != 'A' && (*it).estado != 'I');
	
				system("cls");
				cout<<"Datos actualizados correctamente...."<<endl;
				getOpcionCuenta(mostrarOpcionesCuentas());
			}
			else{
				system("cls");
				cout<<endl<<"Cuenta bancaria no registrada"<<endl;
				getOpcionCuenta(mostrarOpcionesCuentas());
			}				
		}
	}
	else
	{
		system("cls");
		cout<<endl<<"No tiene datos registrados"<<endl;
		getOpcionCuenta(mostrarOpcionesCuentas());
	}
	
}

void consultarCuentaCliente()
{
	if(lstCuentas.size() > 0)
	{
		system("cls");
		string buscarCedula;
		
		cout<<"Introducir la cedula del cliente:";
		cin.ignore();
		getline(cin, buscarCedula); 
						
		bool existe = false;
		int count = 0;
		for(vector<TCuenta>::iterator it = lstCuentas.begin();  !existe && it != lstCuentas.end(); ++it )
		{
			existe = buscarCedula.compare( (*it).clientes.cedula ) == 0 ;
			
			if(existe)
			{
				count++;
			}
		}
		
		if(count > 0)
		{
			for( vector<TPersona>::iterator it = lstPersonas.begin();  !existe && it != lstPersonas.end(); ++it )
			{
				existe = buscarCedula.compare( (*it).cedula ) == 0 ;
					
				if(existe)
				{
			 		cout<<endl<<"Cliente: "<<buscarCedula<<endl;
					cout<<"Nombre: "<< (*it).nombre<<" "<<(*it).apellido<<endl;
					
					cout<<endl<< "Num Cta Bancaria"<<'\t'<< "Balance"<<'\t'<< "Estado"<<'\t'<< "Oficial cuenta"<< endl;
					cout<< "-----------------------------------------------\n";
											
					for(vector<TCuenta>::iterator ot = lstCuentas.begin();  ot != lstCuentas.end(); ++ot )
					{
						string estado;
						estado = ((*ot).estado == 'A') ? "A -> Activo" : "I -> Inactivo";
						double balance;
						balance = (double)((*ot).totalCredito - (*ot).totalDebito);
						
						cout<< (*ot).numeroCuenta << '\t' 
							<< balance << '\t' 
							<< estado << '\t' 
							<< (*ot).nombreOficialBancario;
						cout<<endl; 
					}
											
					cout<<endl<< "--------Fin Consulta Datos ---------"<<endl;
						
					getOpcionCuenta(mostrarOpcionesCuentas());
				}
			}
		}
		else
		{
			system("cls");
			cout<<endl<< "Este cliente no tiene cuentas bancarias"<<endl;
			getOpcionCuenta(mostrarOpcionesCuentas());
		}	
	}
	else
	{
		system("cls");
		cout<<endl<<"No tiene datos registrados"<<endl;
		getOpcionCuenta(mostrarOpcionesCuentas());
	}
}

bool verificarNumeroCuenta(string numeroCuenta)
{
	bool existe = false;
							
	for( vector<TCuenta>::iterator it = lstCuentas.begin();  !existe && it != lstCuentas.end(); ++it )
	{
		existe = numeroCuenta.compare( (*it).numeroCuenta ) == 0 ;
	}
	
	return existe;
}

bool validarNombreOficial(string nombreOficialBancario)
{
	return (nombreOficialBancario.size() >= 4) ? true : false; 
}

bool validarTamanoCuenta(string numeroCuenta)
{
	return (numeroCuenta.size() >= 6) ? true : false;
}

bool validarClientesRegistrados()
{
	if(lstPersonas.size() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
