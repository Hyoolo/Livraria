#pragma once

#include <string>
#include <iostream>
#include "Conexao.h"
#include "Vendas.h"

using namespace conexao;

class Itens_venda
{
private:

	std::string id;
	std::string vendaId;
	std::string produtoId;
	std::string valorUnitario;
	std::string quantidade;
	std::string valorTotal;

public:

	void setId(std::string id) { this->id = id; }
	void setVendaId(std::string vendaId) { this->vendaId = vendaId; }
	void setProdutoId(std::string produtoId) { this->produtoId = produtoId; }
	void setValorUnitario(std::string valorUnitario) { this->valorUnitario = valorUnitario; }
	void setQuantidade(std::string quantidade) { this->quantidade = quantidade; }
	void setValorTotal(std::string valorTotal) { this->valorTotal = valorTotal; }

	std::string getId() { return this->id; }
	std::string getVendaId() { return this->vendaId; }
	std::string getProdutoId() { return this->produtoId; }
	std::string getValorUnitario() { return this->valorUnitario; }
	std::string getQuantidade() { return this->quantidade; }
	std::string getValorTotal() { return this->valorTotal; }

	// CREATE
	void novoItem_venda(void)
	{
		const char* sql = "INSERT INTO itens_venda ()";
		const char* ParamValues[6]{};

		Conexao conn;
		PGresult* res = PQexecParams(conn.getConexao(), sql, 6, NULL, ParamValues, NULL, NULL, 0);

		if (PQresultStatus(res) != PGRES_COMMAND_OK) {
			printf("No data sent\n");
			PQclear(res);
		}
		PQclear(res);
	}

	// READ
	void listarItens_venda(int rows)
	{
		const char* sql = "SELECT * FROM itens_venda;";
		Conexao conn;
		PGresult* res = PQexec(conn.getConexao(), sql);

		if (PQresultStatus(res) != PGRES_TUPLES_OK) {
			printf("Nenhuma informação recebida!\n");
			PQclear(res);
		}

		this->setId(PQgetvalue(res, rows, 0));
		this->setVendaId(PQgetvalue(res, rows, 1));
		this->setProdutoId(PQgetvalue(res, rows, 2));
		this->setValorUnitario(PQgetvalue(res, rows, 3));
		this->setQuantidade(PQgetvalue(res, rows, 4));
		this->setValorTotal(PQgetvalue(res, rows, 5));

		PQclear(res);
	}

	// UPDATE
	void atualizarItens_venda(void)
	{
		const char* sql = "UPDATE itens_venda SET ProdutoId = $2, valorUnitario = $3, quantidade = $4, valorTotal = $5 WHERE id = $1;";
		const char* paramValues[4]{};

		paramValues[0] = this->getProdutoId().data();
		paramValues[1] = this->getValorUnitario().data();
		paramValues[2] = this->getQuantidade().data();
		paramValues[3] = this->getValorTotal().data();

		Conexao conn;
		PGresult* res = PQexecParams(conn.getConexao(), sql, 6, NULL, paramValues, NULL, NULL, 0);
		
		if (PQresultStatus(res) != PGRES_COMMAND_OK) {
			printf("Nenhum dado enviado!\n");
			PQclear(res);
		}
		PQclear(res);
	}

	// DELETE
	void deletarItens_venda(void)
	{
		const char* sql = "DELETE FROM itens_venda WHERE id=$1;";
		const char* ParamValues[1]{};

		ParamValues[0] = this->getId().data();

		Conexao conn;
		PGresult* res = PQexec(conn.getConexao(), sql);

	}

	int getRows(void)
	{
		Conexao conn;

		PGresult* res = PQexec(conn.getConexao(), "SELECT id FROM itens_venda;");
		int rows = PQntuples(res);

		PQclear(res);
		PQfinish(conn.getConexao());

		return rows;
	}
};