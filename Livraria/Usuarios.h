#pragma once

#include <string>
#include <iostream>

#include "Conexao.h"

using namespace Conexao;

namespace Usuarios
{
	class Usuario
	{
	private:
		int Id;
		std::string Nome;
		std::string Login;
		std::string Senha;

		std::string connInfo = "user=postgres dbname=livraria2 host=192.168.33.20 password=123456";

	public:
		// GETTERS e SETTERS para a classe Usuarios

		void setNome(std::string Nome) { this->Nome = Nome; }
		std::string getNome() { return this->Nome; }

		void setLogin(std::string Login) { this->Login = Login; }
		std::string getLogin() { return this->Login; }

		void setSenha(std::string Senha) { this->Senha = Senha; }
		std::string getSenha() { return this->Senha; }
		
		int getId(void) { }

		void novoUsuario(Usuario user)
		{
			const char* ParamsValues[3];

			ParamsValues[0] = user.getNome().data();
			ParamsValues[1] = user.getLogin().data();
			ParamsValues[2] = user.getSenha().data();

			conexao conn;

			PGresult* res = PQexecParams(conn.getConexao(), "INSERT INTO funcionarios (nome, login, senha) values($1, $2, $3);", 3, NULL, ParamsValues, NULL, NULL, 0);

			if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		
				printf("No data sent\n");
				PQclear(res);
			}
			else 
			{
				std::cout << "Usuario Cadastrado\n";
			}

			PQclear(res);
		}

		std::string getUser(Usuario user, int row)
		{
			char* buffer = (char*)malloc(200);

			conexao conn;
			PGresult *res = PQexec(conn.getConexao(), "SELECT nome, login FROM funcionarios;");

			user.Nome = PQgetvalue(res, row, 0);

			return user.Nome;

		}

		int getRows()
		{
			conexao conn;

			PGresult* res = PQexec(conn.getConexao(), "SELECT id FROM funcionarios;");
			int rows = PQntuples(res);

			PQclear(res);
			PQfinish(conn.getConexao());

			return rows;
		}

	};
}
