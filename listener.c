
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		puts("Usage ./program <ip> <port> <password>");
		exit (0);
	}
	char *ip = argv[1];
	int	 server_port = atoi(argv[2]);
	char *pass = argv[3];

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server_addr;

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(server_port);

	if (inet_pton(AF_INET, ip, &server_addr.sin_addr) < 0)
	{
		printf("Error: bad address %s", ip);
		exit(1);
	}

	if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
	{
		printf("connect failed");
		exit(1);
	}

	dprintf(sockfd,"PASS %s\r\nNICK reader\r\nUSER reader * * :reader\r\nJOIN #testing\r\n", pass);

	puts("Looping until ctrl-c");

	while (1)
	{
	}
}
