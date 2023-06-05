#pragma once

#include <string>
#include <iostream>
#include "Conexao.h"
#include "Produtos.h"

using namespace Conexao;
using namespace Produtos;

namespace Estoques
{
	class Estoque
	{
	private:
		std::string id;
		std::string dataEntrada;
		std::string quantidade;
	
	public:

		// GETTERS E SETTERS

		void setId(std::string id)
		{
			this->id = id;
		}

		std::string getId(void)
		{
			return this->id;
		}

		void setDataEntrada(std::string dataEntrada)
		{
			this->dataEntrada = dataEntrada;
		}

		std::string getDataEntrada(void)
		{
			return this->dataEntrada;
		}

		void setQuantidade(std::string quantidade)
		{
			this->quantidade = quantidade;
		}

		std::string getQuantidade(void)
		{
			return this->quantidade;
		}

		// CREATE 

		// READ

		// UPDATE

		// DELETE
	};
}