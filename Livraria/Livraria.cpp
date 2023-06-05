#include <iostream>
#include "Usuarios.h"

using namespace Usuarios;

int main(int argc, char** argv)
{
	Usuario func;

	for (int i = 0; i < func.getRows(); i++)
	{
	    func.listaUsuario(&func, i);
		std::cout << func.getNome() << "\t";
		std::cout << func.getLogin() << std::endl;
	}

	//char* id = (char*)malloc(1);
	//std::cin >> id;

	//func.deletarUsuario(id);

	return 0;
}