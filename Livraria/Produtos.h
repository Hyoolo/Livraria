#pragma once

#include <string>
#include <iostream>
#include "Conexao.h"

using namespace conexao;

class Produto
{
private:

	std::string id;
	std::string codigo;
	std::string descricao;
	std::string precoCusto;
	std::string precoVenda;
	std::string estoqueMin;
	std::string estoqueMax;

public:

	// GETTERS E SETTERS
	void setId(int id) { this->id = id; }
	void setCodigo(std::string codigo) { this->codigo = codigo; }
	void setDescricao(std::string descricao) { this->descricao = descricao; }
	void setPrecoCusto(std::string precoCusto) { this->precoCusto = precoCusto; }
	void setPrecoVenda(std::string precoVenda) { this->precoVenda = precoVenda; }
	void setEstoqueMin(std::string estoqueMin) { this->estoqueMin = estoqueMin; }
	void setEstoqueMax(std::string estoqueMax) { this->estoqueMax = estoqueMax; }

	std::string getId(void) { return this->id; }
	std::string getCodigo(void) { return this->codigo; }
	std::string getDescricao(void) { return this->descricao; }
	std::string getPrecoCusto(void) { return this->precoCusto; }
	std::string getPrecoVenda(void) { return this->precoVenda; }
	std::string getEstoqueMin(void) { return this->estoqueMin; }
	std::string getEstoqueMax(void) { return this->estoqueMax; }

	// CREATE
	void novoProduto(void)
	{
		const char* sql = "INSERT INTO produtos (codigo, descricao, precoCusto, precoVenda, estoqueMin, estoqueMax) values($1, $2, $3, $4, $5, $6);";
		const char* ParamsValues[6];

		ParamsValues[0] = this->getCodigo().data();
		ParamsValues[1] = this->getDescricao().data();
		ParamsValues[2] = this->getPrecoCusto().data();
		ParamsValues[3] = this->getPrecoVenda().data();
		ParamsValues[4] = this->getEstoqueMin().data();
		ParamsValues[5] = this->getEstoqueMax().data();

		Conexao conn;
		PGresult* res = PQexecParams(conn.getConexao(), sql, 6, NULL, ParamsValues, NULL, NULL, 0);

		if (PQresultStatus(res) != PGRES_COMMAND_OK) {
			printf("Nenhum dado enviado!\n");
			PQclear(res);
		}
		PQclear(res);
	}

	// READ
	void listaProduto(int rows)
	{
		const char* sql = "SELECT codigo, descricao, precoCusto, precoVenda, estoqueMin, estoqueMax FROM produtos;";
		Conexao conn;
		PGresult* res = PQexec(conn.getConexao(), sql);

		if (PQresultStatus(res) != PGRES_TUPLES_OK) {
			printf("Nenhuma informação recebida!\n");
			PQclear(res);
		}

		this->setCodigo(PQgetvalue(res, rows, 0));
		this->setDescricao(PQgetvalue(res, rows, 1));
		this->setPrecoCusto(PQgetvalue(res, rows, 2));
		this->setPrecoVenda(PQgetvalue(res, rows, 3));
		this->setEstoqueMin(PQgetvalue(res, rows, 4));
		this->setEstoqueMax(PQgetvalue(res, rows, 5));

		PQclear(res);
	}

	// UPDATE TODO: REFAZER
	void atualizarProduto(void)
	{
		const char* sql = "UPDATE produtos SET descricao = $2, precoCusto = $3, precoVenda = $4, estoqueMin = $5, estoqueMax = $6 WHERE id = $1;";
		const char* ParamValues[6]{};

		ParamValues[0] = this->getId().data();
		ParamValues[1] = this->getDescricao().data();
		ParamValues[2] = this->getPrecoCusto().data();
		ParamValues[3] = this->getPrecoVenda().data();
		ParamValues[4] = this->getEstoqueMin().data();
		ParamValues[5] = this->getEstoqueMax().data();

		Conexao conn;
		PGresult* res = PQexecParams(conn.getConexao(), sql, 6, NULL, ParamValues, NULL, NULL, 0);

		if (PQresultStatus(res) != PGRES_COMMAND_OK) {
			printf("Nenhum dado enviado!\n");
			PQclear(res);
		}
		PQclear(res);
	}

	// DELETE TODO: REFAZER
	void deletarProduto(void)
	{
		const char* sql = "DELETE FROM produtos WHERE id=$1;";
		const char* ParamValues[1]{};

		ParamValues[0] = this->getId().data();

		Conexao conn;
		PGresult* res = PQexec(conn.getConexao(), sql);

	}

	// NUMERO DE ROWS
	int getRows(void)
	{
		Conexao conn;

		PGresult* res = PQexec(conn.getConexao(), "SELECT id FROM produtos;");
		int rows = PQntuples(res);

		PQclear(res);
		PQfinish(conn.getConexao());

		return rows;
	}
};
