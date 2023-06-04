#pragma once

#include <string>
#include <iostream>
#include "Conexao.h"

using namespace Conexao;

namespace Produtos
{
	class Produto
	{
	public:
		std::string codigo;
		std::string descricao;
		std::string precoCusto;
		std::string precoVenda;
		std::string precoMin;
		std::string precoMax;
	private:

		// METODO CONSTRUTOR
		Produto(std::string codigo, std::string descricao, std::string precoCusto, std::string precoVenda, std::string precoMin, std::string precoMax)
		{
			this->codigo = codigo;
			this->descricao = descricao;
			this->precoCusto = precoCusto;
			this->precoVenda = precoVenda;
			this->precoMin = precoMin;
			this->precoMax = precoMax;
		}

		// CREATE
		void novoProduto(Produto prod)
		{
			const char* sql = "INSERT INTO produtos (codigo, descricao, precoCusto, precoVenda, estoqueMin, estoqueMax) values($1, $2, $3, $4, $5, $6);";
			const char* ParamsValues[6];

			ParamsValues[0] = this->codigo.data();
			ParamsValues[1] = this->descricao.data();
			ParamsValues[2] = this->precoCusto.data();
			ParamsValues[3] = this->precoVenda.data();
			ParamsValues[4] = this->precoMin.data();
			ParamsValues[5] = this->precoMax.data();

			conexao conn;

			PGresult* res = PQexecParams(conn.getConexao(), sql, 6, NULL, ParamsValues, NULL, NULL, 0);

			if (PQresultStatus(res) != PGRES_COMMAND_OK) {
				printf("No data sent\n");
				PQclear(res);
			}
			PQclear(res);
		}
		
		// READ

		// UPDATE

		// DELETE

		// NUMERO DE ROWS
		int getRows(void)
		{
			conexao conn;

			PGresult* res = PQexec(conn.getConexao(), "SELECT id FROM produtos;");
			int rows = PQntuples(res);

			PQclear(res);
			PQfinish(conn.getConexao());

			return rows;
		}

		// ID
	};
}