#include <iostream>
#include "Usuarios.h"

using namespace Usuarios;

int main(int argc, char** argv)
{
	Usuario func = func.listaUsuario();

	for (int i = 0; i < 1; i++)
	{
		Usuario func = func.listaUsuario(i);
		std::cout << func;
	}

	//char* id = (char*)malloc(1);
	//std::cin >> id;

	//func.deletarUsuario(id);

	return 0;
}