#pragma once

#include <string>
#include <iostream>
#include "Conexao.h"
#include "itens_venda.h"

using namespace Conexao;

namespace Vendas
{
	class Venda
	{
	private:
		std::string id;
		std::string dataVenda;
		std::string funcionarioId;
		std::string valorTotal;

	public:

		void setId(std::string id);
		std::string getId(void);

		void setDataVenda(std::string dataVenda);
		std::string getDataVenda(void);

		void setValorTotal(std::string valorTotal);
		std::string getValorTotal(void);

		void novaVenda(void);

		void deletarVenda(Venda* venda);

		void listarVenda(Venda* venda, int row);
	};
}