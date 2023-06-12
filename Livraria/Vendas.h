#pragma once

#include <string>
#include <iostream>
#include "Funcionarios.h"
#include "Conexao.h"
#include "itens_venda.h"

using namespace conexao;

class Venda : Funcionario
{
private:

	std::string id;
	std::string dataVenda;
	std::string funcionarioId;
	std::string valorTotal;

public:

	void setId(std::string id) { this->id = id; }
	void setDataVenda(std::string dataVenda) { this->dataVenda = dataVenda; }
	void setFuncionarioId(std::string funcionarioId) { this->funcionarioId = funcionarioId; }
	void setValorTotal(std::string valorTotal) { this->valorTotal = valorTotal; }

	std::string getId(void) { return this->id; }
	std::string getDataVenda(void) { return this->dataVenda; }
	std::string getFuncionarioId(void) { return this->funcionarioId; }
	std::string getValorTotal(void) { return this->valorTotal; }

	// CREATE
	void novaVenda(void)
	{
		const char* sql = "INSERT INTO vendas (dataVenda, funcionarioId, valorTotal) values($1, $2, $3);";
		const char* paramValues[3]{};

		paramValues[0] = this->getDataVenda().data();
		paramValues[1] = this->getFuncionarioId().data();
		paramValues[2] = this->getValorTotal().data();

		Conexao conn;
		PGresult* res = PQexecParams(conn.getConexao(), sql, 3, NULL, paramValues, NULL, NULL, 0);

		if (PQresultStatus(res) != PGRES_COMMAND_OK) {
			printf("Nenhum dado enviado!\n");
			PQclear(res);
		}
		PQclear(res);
	}

	// READ
	void listarVenda(int rows)
	{
		const char* sql = "SELECT * FROM vendas;";
		Conexao conn;
		PGresult* res = PQexec(conn.getConexao(), sql);

		if (PQresultStatus(res) != PGRES_TUPLES_OK) {
			printf("Nenhuma informação recebida!\n");
			PQclear(res);
		}

		this->setId(PQgetvalue(res, rows, 0));
		this->setDataVenda(PQgetvalue(res, rows, 1));
		this->setFuncionarioId(PQgetvalue(res, rows, 2));
		this->setValorTotal(PQgetvalue(res, rows, 3));
	}

	// UPDATE TODO: REFAZER
	void atualizarVenda(void)
	{
	}

	//DELETE TODO: REFAZER
	void deletarVenda(void)
	{
		const char* sql = "DELETE FROM vendas WHERE id=$1;";
		const char* paramValues[1]{};

		Conexao conn;
		PGresult* res = PQexec(conn.getConexao(), sql);

		paramValues[0] = this->getId().data();
	}

	int getRows(void)
	{
		Conexao conn;

		PGresult* res = PQexec(conn.getConexao(), "SELECT id FROM vendas;");
		int rows = PQntuples(res);

		PQclear(res);
		PQfinish(conn.getConexao());

		return rows;
	}
};
