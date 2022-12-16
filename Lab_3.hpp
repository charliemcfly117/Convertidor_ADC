/*------------------------------------------------------||
|| FileName:        lab_3.hpp							||
|| Program version: Dev-C++ 5.11						||
|| School:         TECNM - Campus Chihuahua 			||
|| Description:     Encabezado de Declaración de		|| 
||					Clase y Creación Objetos ADC		||
|| Authors:         Carlos Alberto González Vázquez		||
|| # de Control:	19060770							||
|| Updated:         15/12/2022							||
||------------------------------------------------------*/

#pragma once
#include <iostream>

using namespace std;

class ADC
{
	private:
		static unsigned int rs;	  //Resolución 8,10 o 12v
		static  float hz;         //Frecuencia de muestreo
		float v;                  //Voltaje a convertir 0-3.3v
		unsigned int o;           //Salida en bits según resolución
		short name;               //Nombre
	
	public:
		void Canal(){};  //Constructor por defecto
		//Setters
		static void resolucion (int);
		static void frecuencia(float);
		void captura (float);
		void setname(short);
		//Getters
		static float getf();
		unsigned int conversion();
		short getname();
};
