#pragma once


// USUARIOS //

// Create
const char* criarUser = "INSERT INTO funcionarios (nome, login, senha) VALUES ($1, $2, $3);";
const char* userInsert[3];

// Read
const char* listarUser = "SELECT nome, login, senha FROM funcionarios";

// Update
const char* editarUser = "UPDATE funcionarios SET $2=$3 WHERE id=$1;";
const char* userUpdate[3];

// Delete
const char* deletarUser = "DELETE FROM funcionarios WHERE id=$1;";
const char* userDrop[1];

char column[] = "SELECT COUNT(*) FROM funcionarios.columns;";

// PRODUTOS //

// Create

const char* inserirProduto = "INSERT INTO produto (codigo, descricao, precoCusto, precoVenda, estoqueMin, estoqueMax) values ($1, $2, $3, $4, $5, $6);";
const char* produtoInsert[6];

// Read

const char* listarProduto = "SELECT codigo, descricao, precoCusto, precoVenda, estoqueMin, estoqueMax FROM  produtos;";


// Update
const char* editarProduto = "UPDATE produtos SET $2=$3 ";

// Delete

// ESTOQUE //

// Create
const char* inserirItem = "INSERT INTO estoque (produtoId);";

// Read
const char* listarEstoque = "SELECT * FROM estoque;";

// Update

// Delete


