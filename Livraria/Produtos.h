#pragma once

#include <string>
#include <iostream>
#include "Conexao.h"

using namespace Conexao;

namespace Produtos
{
	class Produto
	{
	private:
		std::string codigo;
		std::string descricao;
		std::string precoCusto;
		std::string precoVenda;
		std::string estoqueMin;
		std::string estoqueMax;
	public:

		// GETTERS E SETTERS
		void setCodigo(std::string codigo)
		{
			this->codigo = codigo;
		}

		std::string getCodigo(void)
		{
			return this->codigo;
		}

		void setDescricao(std::string descricao)
		{
			this->descricao = descricao;
		}

		std::string getDescricao(void)
		{
			return this->descricao;
		}

		void setPrecoCusto(std::string precoCusto)
		{
			this->precoCusto = precoCusto;
		}

		std::string getPrecoCusto(void)
		{
			return this->precoCusto;
		}

		void setPrecoVenda(std::string precoVenda)
		{
			this->precoVenda = precoVenda;
		}

		std::string getPrecoVenda(void)
		{
			return this->precoVenda;
		}

		void setEstoqueMin(std::string estoqueMin)
		{
			this->estoqueMin = estoqueMin;
		}

		std::string getEstoqueMin(void)
		{
			return this->estoqueMin;
		}

		void setEstoqueMax(std::string estoqueMax)
		{
			this->estoqueMax = estoqueMax;
		}

		std::string getEstoqueMax(void)
		{
			return this->estoqueMax;
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
			ParamsValues[4] = this->estoqueMin.data();
			ParamsValues[5] = this->estoqueMax.data();

			conexao conn;

			PGresult* res = PQexecParams(conn.getConexao(), sql, 6, NULL, ParamsValues, NULL, NULL, 0);

			if (PQresultStatus(res) != PGRES_COMMAND_OK) {
				printf("Nenhum dado enviado!\n");
				PQclear(res);
			}
			PQclear(res);
		}
		
		// READ

		void listaProduto(Produto *prod, int rows)
		{
			const char* sql = "SELECT codigo, descricao, precoCusto, precoVenda, estoqueMin, estoqueMax FROM produtos;";
			conexao conn;
			PGresult* res = PQexec(conn.getConexao(), sql);

			if (PQresultStatus(res) != PGRES_TUPLES_OK) {
				printf("Nenhuma informação recebida!\n");
				PQclear(res);
			}

			prod->setCodigo(PQgetvalue(res, rows, 0));
			prod->setDescricao(PQgetvalue(res, rows, 1));
			prod->setPrecoCusto(PQgetvalue(res, rows, 2));
			prod->setPrecoVenda(PQgetvalue(res, rows, 3));
			prod->setEstoqueMin(PQgetvalue(res, rows, 4));
			prod->setEstoqueMax(PQgetvalue(res, rows, 5));

			PQclear(res);
		}

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
		int idProduto(void);
	};
}