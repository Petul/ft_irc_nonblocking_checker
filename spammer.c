
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

	dprintf(sockfd,"PASS %s\r\nNICK spammer\r\nUSER spammer * * :spammer\r\nJOIN #testing\r\n", pass);

	puts("Spamming until ctrl-c");
	char *spambuf = "PRIVMSG #testing :Far far away, behind the word mountains, far from the countries Vokalia and Consonantia, there live the blind texts. Separated they live in Bookmarksgrove right at the coast of the Semantics, a large language ocean. A small river named Duden flows by their place and supplies it with the necessary regelialia. It is a paradisematic country, in which roasted parts of sentences fly into your mouth. Even the all-powerful Pointing has no control about the blind texts it is an almost\r\n";

	while (1)
	{
		write(sockfd, spambuf, strlen(spambuf));
	}
}
