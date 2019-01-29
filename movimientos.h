
struct TMovimiento
{
	int codigoMovimiento;
	string descripcion;
	int origen;
	char estado; 
};

vector<TMovimiento> lstMovimiento;

void crearMovimiento();
void modificarMovimiento();
void consultarMovimiento();
void consultarTodoMovimiento();
bool validarTamanoCodigo(int codigo);
bool validarCodigo(int codigo);
bool validarDescripcion(string descripcion);

int mostrarOpcionesMovimientos() 
{
   int opcion;

	do{
    	cout<<endl<<"Opciones de Tipos de Movimientos"<<endl;
		cout<<"-----------------------------------------"<<endl;
		cout<<"| \t 1 - Nuevo Movimiento \t \t|"<<endl;
		cout<<"| \t 2 - Modificar Movimiento\t|"<<endl;
		cout<<"| \t 3 - Consultar Movimiento \t|"<<endl;
		cout<<"| \t 4 - Consultar Todos \t \t|"<<endl;
		cout<<"| \t 5 - Menu Principal \t \t|"<<endl;
		cout<<"| \t 6 - Salir \t \t \t|"<<endl;
		cout<<"-----------------------------------------"<<endl;
		cout<<endl<<"Opcion: ";
		cin>>opcion;
	}while (opcion < 1);
	
   return opcion;
}

void getOpcionMovimiento(int opcion)
{	
	do{
		switch(opcion)
		{
			case 1:
				crearMovimiento();	
			break;
			
			case 2:
				modificarMovimiento();
			break;
		
			case 3:
				consultarMovimiento();
			break;
		
			case 4:
				consultarTodoMovimiento();
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
				getOpcionMovimiento(mostrarOpcionesMovimientos());
		}
		
	}while(opcion < 1);
}

void movimientos()
{
	getOpcionMovimiento(mostrarOpcionesMovimientos());
}

void crearMovimiento()
{
	system("cls");
	
	TMovimiento movimiento;
	
	cout<<endl<<"Registrando Nuevo Tipo de movimiento"<<endl;
	
	do{
		do{
			cout<<endl<<"Codigo:";
			cin>> movimiento.codigoMovimiento;
		
			if(validarTamanoCodigo(movimiento.codigoMovimiento) == false)
			{
				cout<<"El codigo debe ser mayor o igual a que 1 y menor o igual a 99..."<<endl;
			} 
		}while(validarTamanoCodigo(movimiento.codigoMovimiento) == false);
			
	}while(validarCodigo(movimiento.codigoMovimiento) == true);
	
	do{
		cout<<endl<<"Descripcion:";	
		cin.ignore();
		getline(cin, movimiento.descripcion);
		
		if(validarDescripcion(movimiento.descripcion) == false)
		{
			cout<<"La descripcion debe tener 3 o mas caracteres"<<endl;
		}
		
	}while(validarDescripcion(movimiento.descripcion) == false);
	
	do{
		cout<<endl<<"Origen:";
		cin>>movimiento.origen;
	}while(movimiento.origen != 1 && movimiento.origen != 2);

	do{
		cout<<endl<<"Estado [A-Activo]:";
		cin>>movimiento.estado;
	}while(movimiento.estado != 'A');
	
	lstMovimiento.push_back(movimiento);
	
	system("cls");
	cout<<"Datos creados correctamente...."<<endl;
	
	getOpcionMovimiento(mostrarOpcionesMovimientos());
}

void modificarMovimiento()
{
	system("cls");
	cout<<endl<<"Modificar Movimiento"<<endl;
	
	if(lstMovimiento.size() > 0)
	{
		int codigo;
	
		cout<<endl<<"Introducir codigo de movimiento para modificar .:";
		cin>>codigo;
						
		bool existe = false;
	
		for(vector<TMovimiento>::iterator it = lstMovimiento.begin();  !existe && it != lstMovimiento.end(); ++it )
		{
			existe = (codigo == (*it).codigoMovimiento) ? true : false;
			
			if ( existe )
			{
         		cout<<endl<<"Descripcion:";	
				cin.ignore();
				getline(cin, (*it).descripcion);
				
				do{
					cout<<endl<<"Origen:";
					cin>>(*it).origen;
				}while((*it).origen != 1 && (*it).origen != 2);
			
				do{
					cout<<endl<<"Estado [A-Activo | I-Inactivo]:";
					cin>>(*it).estado;
				}while((*it).estado != 'A' && (*it).estado != 'I');
	
				system("cls");
				cout<<"Datos actualizados correctamente...."<<endl;
				getOpcionMovimiento(mostrarOpcionesMovimientos());
			}
			else{
				system("cls");
				cout<<endl<<"Cliente no registrado"<<endl;
				getOpcionMovimiento(mostrarOpcionesMovimientos());
			}				
		}
	}
	else
	{
		system("cls");
		cout<<endl<<"No tiene datos registrados"<<endl;
		getOpcionMovimiento(mostrarOpcionesMovimientos());
	}
	
}

void consultarMovimiento()
{
	system("cls");
	cout<<endl<<"Consultar Movimiento"<<endl;
	
	if(lstMovimiento.size() > 0)
	{
		int codigo;
	
		cout<<"Introducir codigo de movimiento para consultar:";
		cin>>codigo;
						
		bool existe = false;
	
		for(vector<TMovimiento>::iterator it = lstMovimiento.begin();  !existe && it != lstMovimiento.end(); ++it )
		{
			existe = (codigo == (*it).codigoMovimiento) ? true : false;
			
			if( existe )
			{
				cout<<endl<< "Codigo"<<'\t'<<"Descripcion"<<'\t'<< "Origen"<<'\t'<< "Estado"<< endl;
				cout<< "-----------------------------------------------\n";
				
				string estado;
				estado = ((*it).estado == 'A') ? "A -> Activo" : "I -> Inactivo";
				string origen;
				origen = ((*it).origen == 1) ? "Debito" : "Credito";
			
				cout<< (*it).codigoMovimiento << '\t' 
					<< (*it).descripcion<<'\t'
					<< origen<< '\t'
					<< estado;
				cout<<endl; 
			
				getOpcionMovimiento(mostrarOpcionesMovimientos());
			}
			else
			{
				system("cls");
				cout<<endl<<"Cliente no registrado"<<endl;
				getOpcionMovimiento(mostrarOpcionesMovimientos());
			}				
		}
	}
	else
	{
		system("cls");
		cout<<endl<<"No tiene datos registrados"<<endl;
		getOpcionMovimiento(mostrarOpcionesMovimientos());
	}
	
}

void consultarTodoMovimiento()
{
	if(lstMovimiento.size() > 0)
	{
		system("cls");
		cout<<endl<<"Consulta todos los datos"<<endl;
		cout<<endl<< "Codigo"<<'\t'<<"Descripcion"<<'\t'<< "Origen"<<'\t'<< "Estado"<< endl;
		cout<< "-----------------------------------------------\n";
							
		for( vector<TMovimiento>::iterator it = lstMovimiento.begin();  it != lstMovimiento.end(); ++it )
		{
			string estado;
			estado = ((*it).estado == 'A') ? "A -> Activo" : "I -> Inactivo";
			string origen;
			origen = ((*it).origen == 1) ? "Debito" : "Credito";
			
			cout<< (*it).codigoMovimiento << '\t' 
				<< (*it).descripcion << '\t'
				<< origen<< '\t'
				<< estado;
			cout<<endl; 
		}
							
		cout<<endl<< "--------Fin Consulta Datos ---------"<<endl;
		
		getOpcionMovimiento(mostrarOpcionesMovimientos());
	}
	else
	{
		system("cls");
		cout<<endl<<"No tiene datos registrados"<<endl;
		getOpcionCliente(mostrarOpcionesClientes());
	}
}

bool validarTamanoCodigo(int codigo)
{
	return (codigo >= 1 && codigo <= 99 ) ? true : false;
}

bool validarCodigo(int codigo)
{
	bool existe = false;
							
	for( vector<TMovimiento>::iterator it = lstMovimiento.begin();  !existe && it != lstMovimiento.end(); ++it )
	{
		existe = (codigo == (*it).codigoMovimiento) ? true : false;
	}
	
	return existe;
}

bool validarDescripcion(string descripcion)
{
	return (descripcion.size() >= 3) ? true : false;
}
