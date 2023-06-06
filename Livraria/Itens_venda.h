#pragma once

#include <string>
#include <iostream>
#include "Conexao.h"
#include "Vendas.h"

using namespace Conexao;
using namespace Vendas;

class Itens_venda : Venda
{
private:
	std::string id;
	std::string vendaId;
	std::string produtoId;
	std::string valorUnitario;
	std::string quantidade;
	std::string valorTotal;

public:

	void setId(std::string id);
	void setVendaId(std::string vendaId);
	void setProdutoId(std::string produtoId);
	void setValorUnitario(std::string valorUnitario);
	void setQuantidade(std::string quantidade);
	void setValorTotal(std::string valorTotal);

	std::string getId();
	std::string getVendaId();
	std::string getProdutoId();
	std::string getValorUnitario();
	std::string getQuantidade();
	std::string getValorTotal();
};