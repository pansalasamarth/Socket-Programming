#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>    
#include <string.h>   

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    char buffer[256];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3)
    {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        error("Error opening socket.");
    }
    
    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        fprintf(stderr, "Error, no such host\n");
        exit(1);  
    }
    
    memset((char *) &serv_addr, 0, sizeof(serv_addr));  
    serv_addr.sin_family = AF_INET;
    
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr_list[0], server->h_length);
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        error("Connection Failed");
    }
    
    while (1)
    {
        memset(buffer, 0, 256);  
        fgets(buffer, 255, stdin);
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0)
        {
            error("Error on writing");
        }
        
        memset(buffer, 0, 256);  
        n = read(sockfd, buffer, 255);
        if (n < 0)
        {
            error("Error on reading.");
        }
        
        printf("Server: %s", buffer);
        
        if (strncmp("Bye", buffer, 3) == 0)  
        {
            break;
        }
    }
    
    close(sockfd);
    return 0;
}
