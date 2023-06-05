#include <iostream>
#include "Usuarios.h"

using namespace Usuarios;

int main(int argc, char** argv)
{
	Usuario func;

	for (int i = 0; i < func.getRows(); i++)
	{
		func.listaUsuario(&func, i);
		std::cout << func.getId() << " " << func.getNome() << " " << func.getLogin() << " " << func.getSenha() << std::endl;
	}

	return 0;
}