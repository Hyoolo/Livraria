#include <iostream>
#include "Usuarios.h"

using namespace Usuarios;

int main(int argc, char** argv)
{
	Usuario func;

	for (int i = 0; i < func.getRows(); i++)
	{
		std::cout << func.getUser(func, i) << std::endl;
	}

	return 0;
}