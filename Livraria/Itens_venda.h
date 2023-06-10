#pragma once

#include <string>
#include <iostream>
#include "Conexao.h"
#include "Vendas.h"

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
	void novoItem_venda()
	{

	}
	
	// READ
	void listarItens_venda()
	{
	
	}

	// UPDATE
	void atualizarItens_venda()
	{

	}

	// DELETE
	void deletarItens_venda()
	{

	}
};