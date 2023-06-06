#pragma once

#include <string>
#include <iostream>
#include "Conexao.h"

using namespace Conexao;

namespace Funcionarios
{
	class Funcionario
	{
	private:

		std::string id;
		std::string Nome;
		std::string Login;
		std::string Senha;

	public:

		// GETTERS E SETTER
		void setId(std::string id)
		{
			this->id = id;
		}
		std::string getId(void)
		{
			return this->id;
		}

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
		void novoFuncinario(void)
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
		void listaFuncionario(Funcionario* user, int row)
		{
			const char* sql = "SELECT * FROM funcionarios;";
			conexao conn;
			PGresult* res = PQexec(conn.getConexao(), sql);

			if (PQresultStatus(res) != PGRES_TUPLES_OK) {
				printf("No data sent\n");
				PQclear(res);
			}

			user->setId(PQgetvalue(res, row, 0));
			user->setNome(PQgetvalue(res, row, 1));
			user->setLogin(PQgetvalue(res, row, 2));
			user->setSenha(PQgetvalue(res, row, 3));
			PQclear(res);
		}

		// UPDATE TODO: REFAZER
		void atzarFuncionario(std::string id, std::string Nome, std::string Login, std::string Senha)
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

		// DELETE TODO: REFAZER
		void deletarFuncionario(Funcionario* user)
		{
			const char* sql = "DELETE FROM funcionarios WHERE id=$1;";
			const char* ParamsValues[1];

			ParamsValues[0] = user->getId().data();

			conexao conn;
			PGresult* res = PQexecParams(conn.getConexao(), sql, 1, NULL, ParamsValues, NULL, NULL, 0);

			if (PQresultStatus(res) != PGRES_COMMAND_OK) {
				printf("No data sent\n");
				PQclear(res);
			}

			PQclear(res);
		}

		// NUMERO DE ROWS
		int getRows(void)
		{
			const char* sql = "SELECT id FROM funcionarios;";
			conexao conn;
			PGresult* res = PQexec(conn.getConexao(), sql);
			int rows = PQntuples(res);

			PQclear(res);
			PQfinish(conn.getConexao());

			return rows;
		}
	};
}
