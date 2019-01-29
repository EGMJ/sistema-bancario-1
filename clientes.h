
struct TPersona
{
	string nombre;
	string apellido;
	string cedula;
	string fecha_nacimiento;
	char estado; 
};

vector<TPersona> lstPersonas;

void crearCliente();
void modificarCliente();
void consultarCliente();
void eliminarCliente();
void consultarTodos();
bool verificarCedula(string cedula);
bool validarNombre(string nombre);

int mostrarOpcionesClientes() 
{
   int opcion;

	do{
    	cout<<endl<<"Opciones de Clientes"<<endl;
		cout<<"----------------------------------"<<endl;
		cout<<"| \t 1 - Nuevo \t \t |"<<endl;
		cout<<"| \t 2 - Modificar \t \t |"<<endl;
		cout<<"| \t 3 - Consultar \t \t |"<<endl;
		cout<<"| \t 4 - Eliminar \t \t |"<<endl;
		cout<<"| \t 5 - Ver todos \t \t |"<<endl;
		cout<<"| \t 6 - Menu Principal \t |"<<endl;
		cout<<"| \t 7 - Salir \t \t |"<<endl;
		cout<<"----------------------------------"<<endl;
		cout<<endl<<"Opcion: ";
		cin>>opcion;
	}while (opcion < 1);
	
   return opcion;
}

void getOpcionCliente(int opcion)
{	
	do{
		switch(opcion)
		{
			case 1:
				crearCliente();	
			break;
			
			case 2:
				modificarCliente();
			break;
		
			case 3:
				consultarCliente();
			break;
		
			case 4:
				eliminarCliente();	
			break;
			
			case 5:
				consultarTodos();	
			break;
			
			case 6:
				system("cls");
				getOpcion(menuPrincipal());
			break;
			
			case 7:
				system("cls");
				cout<<endl<<"Muchas Gracias por utilizar nuestro servicio"<<endl;
				exit(0);	
			break;
			
			default:
				system("cls");
				cout<<"Opcion no disponible"<<endl;	
				getOpcionCliente(mostrarOpcionesClientes());
		}
		
	}while(opcion < 1);
}

void clientes()
{
	getOpcionCliente(mostrarOpcionesClientes());
}

void crearCliente()
{
	system("cls");
	
	TPersona persona;
	
	cout<<endl<<"Registrando Nuevo Cliente"<<endl;
	
	do{
		cout<<endl<<"Cedula:";
		cin.ignore();
		getline(cin, persona.cedula);
		
		if(verificarCedula(persona.cedula))
		{
			cout<<"Ya existe un cliente con esta cedula..."<<endl;
		} 
		
	}while(verificarCedula(persona.cedula) == true);
	
	do
	{
		cout<<endl<<"Nombre:";	
		getline(cin, persona.nombre);
		
		if(validarNombre(persona.nombre) == false)
		{
			cout<<"El nombre debe contener 4 o mas caracteres"<<endl;
		}
		
	}while(validarNombre(persona.nombre) == false);
 
	
	cout<<endl<<"Apellido:";
	getline(cin, persona.apellido); 

	cout<<endl<<"Fecha de Nacimiento:";
	getline(cin, persona.fecha_nacimiento); 
	
	do{
		cout<<endl<<"Estado [A-Activo]:";
		cin>>persona.estado;
	}while(persona.estado != 'A');
	
	lstPersonas.push_back(persona);
	
	system("cls");
	
	cout<<"Cliente registrado correctamente...."<<endl;
	
	getOpcionCliente(mostrarOpcionesClientes());
}

void modificarCliente()
{
	system("cls");
	
	cout<<endl<<"Modificar Cliente"<<endl;
	
	if(lstPersonas.size() > 0)
	{
		string cedula;
	
		cout<<"Introducir cedula persona modificar .:";
		cin.ignore();
		getline(cin, cedula); 
						
		bool existe = false;
	
		for(vector<TPersona>::iterator it = lstPersonas.begin();  !existe && it != lstPersonas.end(); ++it )
		{
			existe = cedula.compare( (*it).cedula ) == 0 ;
			if ( existe )
			{
		  		do{
					cout<<endl<<"Nombre:";	
					getline(cin, (*it).nombre);
					
					if(validarNombre((*it).nombre) == false)
					{
						cout<<"El nombre debe contener 4 o mas caracteres"<<endl;
					}
					
				}while(validarNombre((*it).nombre) == false);
	
          		cout <<endl<< "Apellido:";
				getline(cin, (*it).apellido); 
				
				cout <<endl<< "Fecha de nacimiento:";
				getline(cin, (*it).fecha_nacimiento); 
				
				do{
					cout<<endl<<"Estado [A-Activo | I-Inactivo]:";
					cin>>(*it).estado;
				}while((*it).estado != 'A' && (*it).estado != 'I');
	
				system("cls");
				cout<<"Datos actualizados correctamente...."<<endl;
				getOpcionCliente(mostrarOpcionesClientes());
			}
			else{
				system("cls");
				cout<<endl<<"Cliente no registrado"<<endl;
				getOpcionCliente(mostrarOpcionesClientes());
			}				
		}
	}
	else
	{
		system("cls");
		cout<<endl<<"No tiene datos registrados"<<endl;
		getOpcionCliente(mostrarOpcionesClientes());
	}
	
}

void consultarCliente()
{			
	system("cls");				
	cout<<endl<<"Consultar Cliente"<<endl;
	
	string cedula;
	
	if(lstPersonas.size() > 0)
	{
		cout<<endl<<"Introducir cedula para consultar .:";
		cin.ignore();
		getline(cin,cedula); 
								
		bool existe = false;
								
		for( vector<TPersona>::iterator it = lstPersonas.begin();  !existe && it != lstPersonas.end(); ++it )
		{
			existe = cedula.compare( (*it).cedula ) == 0 ;
			
			if(existe)
			{
				string estado;
				estado = ((*it).estado == 'A') ? "A -> Activo" : "I -> Inactivo";
				
				cout<<endl<<"Nombre:" << (*it).nombre << endl 
					<< "Apellido:" << (*it).apellido << endl 
		 	     	<< "Fecha de nacimiento:" << (*it).fecha_nacimiento << endl
					<< "Estado: " << estado;
		 	    cout<<endl;
		 	    getOpcionCliente(mostrarOpcionesClientes());
			}
			else
			{
				system("cls");
				cout<<endl<<"Cliente no registrado"<<endl;
				getOpcionCliente(mostrarOpcionesClientes());
			}
		}
	}
	else
	{
		system("cls");
		cout<<endl<<"No tiene datos registrados"<<endl;
		getOpcionCliente(mostrarOpcionesClientes());
	}
}

void eliminarCliente()
{
	cout<<endl<<"Eliminar Cliente"<<endl;
	
	string cedula;
	
	if(lstPersonas.size() > 0)
	{
		cout <<endl<< "Introducir cedula para eliminar:";
		cin.ignore();
		getline(cin,cedula); 
								
		bool existe = false;
								
		for( vector<TPersona>::iterator it = lstPersonas.begin();  !existe && it != lstPersonas.end(); ++it )
		{
			existe = cedula.compare( (*it).cedula ) == 0 ;
			
			if(existe)
			{
	 			lstPersonas.erase(it);
	 			system("cls");
				cout<<endl<<"Datos Eliminados"<<endl;
				getOpcionCliente(mostrarOpcionesClientes());
			}
		}
	}
	else
	{
		system("cls");
		cout<<endl<<"No tiene datos registrados"<<endl;
		getOpcionCliente(mostrarOpcionesClientes());
	}
}

void consultarTodos()
{
	if(lstPersonas.size() > 0)
	{
		system("cls");
		cout<<endl<<"Consulta todos los datos"<<endl;
		cout<<endl<< "Cedula"<<'\t'<< "Nombre/Apellido"<<'\t'<< "Fecha de Nacimiento"<< '\t' << "Estado"<< endl;
		cout<< "-----------------------------------------------\n";
							
		for( vector<TPersona>::iterator it = lstPersonas.begin();  it != lstPersonas.end(); ++it )
		{
			string estado;
			estado = ((*it).estado == 'A') ? "A -> Activo" : "I -> Inactivo";
			cout<< (*it).cedula << '\t' 
				<< (*it).nombre <<" "<<(*it).apellido << '\t' 
				<< (*it).fecha_nacimiento  << '\t'
				<< estado;
			cout<<endl; 
		}
							
		cout<<endl<< "--------Fin Consulta Datos ---------"<<endl;
		
		getOpcionCliente(mostrarOpcionesClientes());	
	}
	else
	{
		system("cls");
		cout<<endl<<"No tiene datos registrados"<<endl;
		getOpcionCliente(mostrarOpcionesClientes());
	}
}

bool verificarCedula(string cedula)
{
	bool existe = false;
							
	for( vector<TPersona>::iterator it = lstPersonas.begin();  !existe && it != lstPersonas.end(); ++it )
	{
		existe = cedula.compare( (*it).cedula ) == 0 ;
	}
	
	return existe;
}

bool validarNombre(string nombre)
{
	return (nombre.length() >= 4) ? true : false; 
}
