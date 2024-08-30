#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

bool esNumeroRomanoValido(const char* cadena);
bool cumpleRepeticionDeDigitosTres(const char* numeroRomano);
bool cumpleRepeticionDeDigitosDos(const char* numeroRomano);
bool verificarCombinacionesNoValidas(const char* numeroRomano);
int valorRomano(char c);
void convertirRomanoAEnteros(const char* cadena, int* enteros);
int convertirAdecimal(const int* enteros, size_t longitud);

int main(){
	for (int i = 0; i < 10; i++) {
		cout << "Caso de prueba " << i + 1 << "\n";
		char Romano[10] = {};
		do {
			do {
				do {
					do {
						memset(Romano, '\0', sizeof(Romano));
						cout << "Ingrese un numero del 1 al 3000 en romanos (I a MMM): ";
						cin >> setw(10) >> Romano;
					} while (esNumeroRomanoValido(Romano) == false); // verificar digitos correctos
				} while (cumpleRepeticionDeDigitosTres(Romano) == false); // verificar cantidad digitos <=3
			} while (cumpleRepeticionDeDigitosDos(Romano) == false); // verificar ciertos digitos <2
		} while (verificarCombinacionesNoValidas(Romano) == false); // verificar combinaciones no validas
			
		int Decimal[10] = {};
		convertirRomanoAEnteros(Romano, Decimal); // Obtener el arreglo de valores numericos correspondiente 
												  // al numero romano

		int RomantoDecimal = convertirAdecimal(Decimal, strlen(Romano)); // Obtener el valo numerico siguiendo
																		 // las reglas de suma y resta
		cout <<"El numero decimal es: " << RomantoDecimal << "\n\n";
	}
	return 0;
}



bool esNumeroRomanoValido(const char* cadena) {
	const char* validos = "IVXLCDM";
	for (int i = 0; i < std::strlen(cadena); ++i) {
		if (std::strchr(validos, cadena[i]) == nullptr) {
			return false;  // Caracter no válido encontrado
		}
	}
	return true;  // Todos los caracteres son válidos
}

bool cumpleRepeticionDeDigitosTres(const char* numeroRomano) {
	int longitud = static_cast<int>(strlen(numeroRomano));
	int contador = 1;  // Contador de repeticiones consecutivas

	for (int i = 1; i < longitud; ++i) {
		if (numeroRomano[i] == numeroRomano[i - 1]) {
			contador++;
			if (contador > 3) {
				return false;  // Más de 3 repeticiones consecutivas
			}
		}
		else {
			contador = 1;  // Reiniciar contador si el carácter cambia
		}
	}

	return true;
}
bool cumpleRepeticionDeDigitosDos(const char* numeroRomano) {
	int longitud = static_cast<int>(strlen(numeroRomano));
	int contador = 1;  // Contador de repeticiones consecutivas

	for (int i = 1; i < longitud; ++i) {
		if (numeroRomano[i] == numeroRomano[i - 1] && ((numeroRomano[i] == 'V')|| (numeroRomano[i] == 'L')|| (numeroRomano[i] == 'D'))) {
			return false;
		}
		else {
			contador = 1;  // Reiniciar contador si el carácter cambia
		}
	}

	return true;
}

bool verificarCombinacionesNoValidas(const char* numeroRomano) {
	int longitud = static_cast<int>(strlen(numeroRomano));

	for (int i = 0; i < longitud - 1; ++i) {
		// Verificar combinaciones no válidas específicas
		if ((numeroRomano[i] == 'I' && (numeroRomano[i + 1] == 'M' || numeroRomano[i + 1] == 'L' || numeroRomano[i + 1] == 'C' || numeroRomano[i + 1] == 'D')) ||
			(numeroRomano[i] == 'X' && (numeroRomano[i + 1] == 'M' || numeroRomano[i + 1] == 'D' || numeroRomano[i + 1] == 'C'))) {
			return false; // Combinación no válida detectada
		}
	}

	return true; // Ninguna combinación no válida encontrada
}

int valorRomano(char c) {
	switch (c) {
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	default: return 0;  // Caso de carácter no válido
	}
}

void convertirRomanoAEnteros(const char* cadena, int* enteros) {
	size_t longitud = std::strlen(cadena);
	for (int i = 0; i < longitud; ++i) {
		enteros[i] = valorRomano(cadena[i]);
	}
}

// Función para convertir el arreglo de enteros en un número decimal
int convertirAdecimal(const int* enteros, size_t longitud) {
	int resultado = 0;

	for (int i = static_cast<int>(longitud)- 1; i >= 0; --i) {
		if (i < longitud - 1 && enteros[i] < enteros[i + 1]) {
			resultado -= enteros[i];
		}
		else {
			resultado += enteros[i];
		}
	}

	return resultado;
}