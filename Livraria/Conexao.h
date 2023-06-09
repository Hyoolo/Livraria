#pragma once

#include <iostream>
#include <string>
#include <postgres/libpq-fe.h>

namespace conexao
{
	class Conexao
	{
	private:

		const char* connInfo = "user=postgres dbname=livraria2 host=192.168.33.20 password=123456";

	public:

		PGconn* getConexao(void)
		{
			PGconn* conn = PQconnectdb(connInfo);
			if (PQstatus(conn) == CONNECTION_BAD)
			{
				fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
				PQfinish(conn);
			}
			else {
				return conn;
			}
		}
	};
}