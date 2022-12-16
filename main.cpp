/*------------------------------------------------------||
|| FileName:        main.cpp							||
|| Program version: Dev-C++ 5.11						||
|| School:         TECNM - Campus Chihuahua 			||
|| Description:     Lab_3 - Simulación de Configuración	||
||					de un Convertidor ADC				||
|| Authors:         Carlos Alberto González Vázquez	    ||
|| # de Control:	19060770							||
|| Updated:         15/12/2022							||
||------------------------------------------------------*/

#include <iostream>
#include <stdlib.h>
#include "Lab_3.hpp"

using namespace std;

short i,bits,cant,num;
float frequence,voltage;

int main()
{
	cout<<"Introduce el Numero de Canales a Utilizar: "<<endl;
	cin>>cant;
	
	do  //Validacion de datos
	{
		cout<<"Introduce la Resolucion [8, 10, 12 (Bits)]:  "<<endl;
		cin>>bits;
		fflush(stdin);
		
		if(!(bits == 8||bits == 10||bits == 12))
			cout<<"Resolución no permitida"<<endl;	
		
	}while(!(bits == 8||bits == 10||bits == 12));

	ADC::resolucion(bits);
	cout<<"Introduce la Frecuencia de Muestreo [Hz]:  "<<endl;
	cin>>frequence;
	ADC::resolucion(bits);
	ADC::frecuencia(frequence);
	ADC canales [cant];  //Creacion de objetos segun los canales a usar
	

	for(i=0;i<cant;i++)
	{
		do 
		{
			cout<<"Introduce que canal deseas usar (1-32)"<<endl;
			cin>>num;
			canales[i].setname(num);
			
			if(num>32||num == 0)
				cout<<"No existe canal"<<endl;
				
		}while(num>32||num == 0);
	}

	for(i=0;i<cant;i++)
	{
		cout<<"Introduce el valor a medir del canal: "<<i+1<<endl;
		fflush(stdin);
		
		do  //Validacion de datos
		{
			cin>>voltage;  //Lectura del voltaje de cada canal
			
			if(voltage>3.3)
				cout<<"Voltaje mayor a 3.3"<<endl;
			
		}while(voltage>3.3);
		
		canales[i].captura(voltage);
	}
	
	for(i=0;i<cant;i++)  //Ciclo for para la impresion de datos
	{
		cout<<"El valor digital del canal AN"<<canales[i].getname();
		cout<<",con frecuencia de muestreo de "<<ADC::getf();
		cout<<" MHz";
		cout<<": "<<canales[i].conversion()<<endl;
	}
	return 0;
}
