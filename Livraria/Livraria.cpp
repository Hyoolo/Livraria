#include <iostream>
#include "Funcionarios.h"

using namespace Funcionarios;

int main(int argc, char** argv)
{
	std::string Nome, Login, Senha;
	Funcionario func;

	for (int i = 0; i < func.getRows(); i++)
	{
		func.listaUsuario(&func, i);
		std::cout << func.getId() << " " << func.getNome() << " " << func.getLogin() << " " << func.getSenha() << std::endl;
	}



	std::cin >> Nome >> Login >> Senha;

	func.setNome(Nome);
	func.setLogin(Login);
	func.setSenha(Senha);

	func.novoUsuario();

	for (int i = 0; i < func.getRows(); i++)
	{
		func.listaUsuario(&func, i);
		std::cout << func.getId() << " " << func.getNome() << " " << func.getLogin() << " " << func.getSenha() << std::endl;
	}
	return 0;
}