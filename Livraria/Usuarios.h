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
		std::string getNome(void) { return this->Nome; }

		void setLogin(std::string Login) { this->Login = Login; }
		std::string getLogin(void) { return this->Login; }

		void setSenha(std::string Senha) { this->Senha = Senha; }
		std::string getSenha(void) { return this->Senha; }

		// CREATE
		void novoUsuario(Usuario user)
		{
			const char* ParamsValues[3];

			ParamsValues[0] = this->Nome.data();
			ParamsValues[1] = this->Login.data();
			ParamsValues[2] = this->Senha.data();

			conexao conn;

			PGresult* res = PQexecParams(conn.getConexao(), "INSERT INTO funcionarios (nome, login, senha) values($1, $2, $3);", 3, NULL, ParamsValues, NULL, NULL, 0);

			if (PQresultStatus(res) != PGRES_COMMAND_OK) {
				printf("No data sent\n");
				PQclear(res);
			}

			PQclear(res);
		}

		// READ
		std::string getUser(Usuario user, int row)
		{
			char* buffer = (char*)malloc(200);

			conexao conn;
			PGresult* res = PQexec(conn.getConexao(), "SELECT nome, login FROM funcionarios;");

			user.Nome = PQgetvalue(res, row, 0);

			return user.Nome;
		}

		// DELETE
		void deletarUsuario(char* id)
		{
			const char* str[] = { id };
			conexao conn;
			PGresult* res = PQexecParams(conn.getConexao(), "DELETE FROM funcionarios WHERE id=$1;", 1, NULL, str, NULL, NULL, 0);

			if (PQresultStatus(res) != PGRES_COMMAND_OK) {
				printf("No data sent\n");
				PQclear(res);
			}

			PQclear(res);
		}

		// UPDATE
		void atualizarUsuario(std::string id, std::string Nome, std::string Login, std::string Senha)
		{
			conexao conn;

			const char* ParamsValues[4];

			ParamsValues[0] = id.data();
			ParamsValues[1] = Nome.data();
			ParamsValues[2] = Login.data();
			ParamsValues[3] = Senha.data();

			PGresult* res = PQexecParams(conn.getConexao(),"UPDATE funcionarios SET nome=$2, login=$3, senha=$4 WHERE id=$1;", 4, NULL, ParamsValues, NULL, NULL, 0);
			if (PQresultStatus(res) != PGRES_COMMAND_OK) {
				printf("No data sent\n");
				PQclear(res);
			}

			PQclear(res);
		}

		int getId(void) { }

		int getRows(void)
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
