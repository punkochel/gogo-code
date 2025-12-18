#include <iostream>
#include <mysql.h>

int main()
{
	MYSQL* dbConnect = mysql_init(NULL);

	if (dbConnect == NULL)
	{
		std::cerr << "mysql_init failed: " << mysql_error(dbConnect) << std::endl;
		return 1;
	}

	/* Disable SSL mode */
	uint8_t verify_cert = 0;
	mysql_options(dbConnect, MYSQL_OPT_SSL_VERIFY_SERVER_CERT, &verify_cert);

	if (mysql_real_connect(dbConnect, "localhost", "root", "", "samp", 3306, NULL, 0) == NULL)
	{
		std::cerr << "mysql_real_connect failed: " << mysql_error(dbConnect) << std::endl;
		mysql_close(dbConnect);
		return 2;
	}

	std::cout << "** Successfully connected to the MariaDB server **\n";

	mysql_close(dbConnect);

	std::cout << "** MySQL connection was closed **\n";

	return 0;
}