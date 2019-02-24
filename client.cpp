// Write CPP code here 
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <ncurses.h>
#include <iostream>
#include <curses.h>
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

int func(int sockfd) 
{ 
    char buff[MAX]; 
    int n; 
    for (;;) { 
        // bzero(buff, sizeof(buff)); 
        printf("Enter the string : "); 
         n = 0; 
       // buff[0] = getchar();
       // while ((buff[n++] = getchar()) != '\n') 
       //      ; 
        buff[0] = 'h';
       buff[1] = 'i'; 
       // 
        //buff[n] = getchar();
       
        write(sockfd, buff, sizeof(buff)); 
        //bzero(buff, sizeof(buff)); 
        // read(sockfd, buff, sizeof(buff)); 
        // printf("From Server : %s", buff); 
        
    } 
        return (sockfd);
} 
  
int main() 
{ 
    char buff[MAX];
    int sockfd, sockfd2;
    struct sockaddr_in servaddr, cli; 
  
    // socket create and varification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT); 
  
    // connect the client socket to server socket 
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
        printf("connected to the server..\n"); 
  
    // function for chat 
    sockfd2 = func(sockfd);
     if (sockfd2 == -1) { 
        printf("socket2 creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket2 successfully created..\n");  
    read(sockfd2, buff, sizeof(buff)); 
    std::cout << "buff client = " << buff << std::endl;
    // close the socket 
    close(sockfd); 
} 