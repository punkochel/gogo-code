#include <iostream>
#include <mysql.h>

class Database
{
	MYSQL* conn;

public:
	Database()
	{
		conn = mysql_init(nullptr);

		if (conn)
		{
			unsigned verify_cert = 0;
			mysql_options(conn, MYSQL_OPT_SSL_VERIFY_SERVER_CERT, &verify_cert);
		}
	}

	Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

	~Database()
	{
		if (conn)
		{
			mysql_close(conn);
			std::cout << "** MySQL connection was closed **\n";
		}
	}

	bool connect(const char *host, const char *user, const char *passwd, const char *db)
	{
		return mysql_real_connect(conn, host, user, passwd, db, 3306, nullptr, 0);
	}

	bool query(const std::string& q)
	{
		return mysql_query(conn, q.c_str()) == 0;
	}

	const char* getLastError()
	{
		return conn ? mysql_error(conn) : "mysql_init failed.";
	}

	MYSQL* getRaw()
	{
		return conn;
	}
};

void printInfo(Database& db)
{
	db.query("SELECT * FROM accounts");
	MYSQL_RES* result = mysql_store_result(db.getRaw());
	int fields = mysql_field_count(db.getRaw());
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(result)))
	{
		for (int i = 0; i < fields; ++i)
		{
			std::cout << (row[i] ? row[i] : "NULL") << " | ";
		}
		std::cout << "\n";
	}
	mysql_free_result(result);
}

int main()
{
	Database db;
	if (db.getRaw() == nullptr)
	{
		std::cerr << db.getLastError() << std::endl;
		return 1;
	}

	if (!db.connect("localhost", "root", "", "samp"))
	{
		std::cerr << "mysql_real_connect failed: " << db.getLastError() << std::endl;
		return 1;
	}

	db.query("INSERT INTO accounts (pName, pLevel, pCash) VALUES ('Donald_Trump', 3, 5000)");
	printInfo(db);

	std::cout << "** Successfully connected to the MariaDB server **\n";
	return 0;
}