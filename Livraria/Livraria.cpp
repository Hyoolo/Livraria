#include <iostream>
#include "Usuarios.h"

using namespace Usuarios;

int main(int argc, char** argv)
{
	std::string Nome, Login, Senha;

	std::cin >> Nome;
	std::cin >> Login;
	std::cin >> Senha;

	Usuario func;

	func.setNome(Nome);
	func.setLogin(Login);
	func.setSenha(Senha);

	func.novoUsuario(func);

	//std::cout << eu.getLogin();

	//std::cout << eu.ListarUsuario();

	for (int i = 0; i < func.getRows(); i++)
	{
		std::cout << func.getUser(func, i) << std::endl;
	}
	

	return 0;
}

