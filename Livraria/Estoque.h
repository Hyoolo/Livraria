#pragma once

#include <string>
#include <iostream>
#include "Conexao.h"
#include "Produtos.h"

using namespace conexao;

class Estoque
{
private:

	std::string id;
	std::string produtoId;
	std::string dataEntrada;
	std::string quantidade;

public:

	// GETTERS E SETTERS

	void setId(std::string id) { this->id = id; }
	void setDataEntrada(std::string dataEntrada) { this->dataEntrada = dataEntrada; }
	void setQuantidade(std::string quantidade) { this->quantidade = quantidade; }

	std::string getDataEntrada(void) { return this->dataEntrada; }
	std::string getId(void) { return this->id; }
	std::string getQuantidade(void) { return this->quantidade; }

	// CREATE
	void novoEstoque()
	{
	}

	// READ
	void listarEstoque();

	// UPDATE
	void atualizarEstoque();

	// DELETE
	void deletarEstoque();
};
