#include "csapp.h"
int main( int argc, char **argv) 
{
	int clientfd, port; 
	char *host, buf[MAXLINE];
	char test[1024];
	//reio struct
	rio_t rio; 
	//get host and port 
	host = argv[1]; port = atoi(argv[2]); 
	clientfd = open_clientfd(host, port); 
	//open client fd and read it to the server
	Rio_readinitb(&rio, clientfd); 
	int len = snprintf(test, sizeof(test)-1, "GET /%s HTTP/1.1\r\nhost: www.google.com\r\n\r\n",argv[3]);
	rio_writen(clientfd, test, strlen(test)); 
	//write back the response 
	while(rio_readnb(&rio, buf, MAXLINE) > 0);
	{
		printf(buf, stdout);
	}	

	close(clientfd); 
	exit(0); 

	



}
