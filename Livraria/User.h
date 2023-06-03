#pragma once

#include <stdlib.h>

#include "SqlScripts.h"

const char* conninfo = "user=postgres dbname=livraria2 host=192.168.33.20 password=123456";

void CreateUser(char nome[200], char login[50], char senha[50])
{
	userInsert[0] = nome;
	userInsert[1] = login;
	userInsert[2] = senha;
}

void UpdateUser(char nome[200], char login[50], char senha[50])
{
}

char* GetUser(int row)
{
	char* buffer = (char*)malloc(200);

	//conn = PQconnectdb(conninfo);
	//result = PQexec(conn, listarUser);

	//int rows = PQntuples(result);
	//int columns = PQnfields(result);

	//char* nome = { PQgetvalue(result, row, 0) };
	//char* login = { PQgetvalue(result, row, 1) };
	//char* senha = { PQgetvalue(result, row, 2) };

	char total[200] = "";

	//sprintf_s(buffer, 200, "%s %s", nome, login);

	//PQclear(result);
	//PQfinish(conn);

	return buffer;
}