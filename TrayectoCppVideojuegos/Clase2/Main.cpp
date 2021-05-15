// Main.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Archer.h" // Incluyo la clase Archer

int main(){
	Archer archer(50); // Archer archer = Archer(50) - Creo una instancia u objeto de la clase Archer
	archer.Debug(); // Llamo al metodo Debug de Archer
	cin.get(); // Espero hasta recibir character - Si se ejecuta el .exe con esta sentencia vemos el output y no ce cierra la ventana automaticamente.
}