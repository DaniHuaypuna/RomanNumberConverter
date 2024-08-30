
#include <iostream>
#include <cstring>
using namespace std;


int main() {
	const char* CENTENAS[10] = {" ", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
	const char* DECENAS[10] = {" ", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	const char* UNIDADES[10] = {" ", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

	for (int i = 0; i < 10; i++) { // diez (10) casos de pruebas
		cout << "Caso de prueba " << i + 1 << "\n";
		int Decimal = 0;
		do {
			cout << "Ingrese un numero del 1 al 100: ";
			cin >> Decimal;
		} while (Decimal>100 || Decimal<1); // verificar combinaciones no validas
		int centena = Decimal / 100;
		int decena = (Decimal / 10) % 10;
		int unidad = Decimal % 10;
		char Romano[13] = {};
		strcat_s(Romano, CENTENAS[centena]);
		strcat_s(Romano, DECENAS[decena]);
		strcat_s(Romano, UNIDADES[unidad]);
		cout << "El numero romano es: " << Romano << "\n\n";
	}
	return 0;
}
