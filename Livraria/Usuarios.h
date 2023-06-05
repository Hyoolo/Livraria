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

		// GETTERS E SETTER

		void setNome(std::string Nome)
		{
			this->Nome = Nome;
		}

		std::string getNome(void)
		{
			return this->Nome;
		}

		void setLogin(std::string Login)
		{
			this->Login = Login;
		}

		std::string getLogin(void)
		{
			return this->Login;
		}

		void setSenha(std::string Senha)
		{
			this->Senha = Senha;
		}

		std::string getSenha(void)
		{
			return this->Senha;
		}

		// CREATE
		void novoUsuario(Usuario user)
		{
			const char* sql = "INSERT INTO funcionarios (nome, login, senha) values($1, $2, $3);";
			const char* ParamsValues[3];

			ParamsValues[0] = this->Nome.data();
			ParamsValues[1] = this->Login.data();
			ParamsValues[2] = this->Senha.data();

			conexao conn;

			PGresult* res = PQexecParams(conn.getConexao(), sql, 3, NULL, ParamsValues, NULL, NULL, 0);

			if (PQresultStatus(res) != PGRES_COMMAND_OK) {
				printf("No data sent\n");
				PQclear(res);
			}

			PQclear(res);
		}

		// READ

		void listaUsuario(Usuario* user, int row)
		{
			const char* sql = "SELECT nome, login FROM funcionarios;";
			conexao conn;
			PGresult* res = PQexec(conn.getConexao(), sql);

			if (PQresultStatus(res) != PGRES_TUPLES_OK) {
				printf("No data sent\n");
				PQclear(res);
			}

			user->setNome(PQgetvalue(res, row, 0));
			user->setLogin(PQgetvalue(res, row, 1));
			PQclear(res);
		}

		// DELETE
		void deletarUsuario(char* id)
		{
			const char* str[1] = { id };
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
			const char* sql = "UPDATE funcionarios SET nome=$2, login=$3, senha=$4 WHERE id=$1;";
			const char* ParamsValues[4];

			ParamsValues[0] = id.data();
			ParamsValues[1] = Nome.data();
			ParamsValues[2] = Login.data();
			ParamsValues[3] = Senha.data();
			
			conexao conn;
			PGresult* res = PQexecParams(conn.getConexao(), sql, 4, NULL, ParamsValues, NULL, NULL, 0);
			if (PQresultStatus(res) != PGRES_COMMAND_OK) {
				printf("No data sent\n");
				PQclear(res);
			}

			PQclear(res);
		}

		// NUMERO DE ROWS
		int getRows(void)
		{
			conexao conn;

			PGresult* res = PQexec(conn.getConexao(), "SELECT id FROM funcionarios;");
			int rows = PQntuples(res);

			PQclear(res);
			PQfinish(conn.getConexao());

			return rows;
		}

		// ID
		int idUsuarios(void) { }
	};
}
