#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char message[1024] = {0};
    double num1, num2;
    char operator;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket");
    }

serv_addr.sin_family = AF_INET;
serv_addr.sin_port = htons(PORT);

// Convert IPv4 and IPv6 addresses from text to binary form
if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
{
    printf("\nInvalid address/ Address not supported \n");
    return -1;
}

if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
{
    printf("\nConnection Failed \n");
    return -1;
}

// Read user input
printf("Enter first number: ");
scanf("%lf", &num1);
printf("Enter operator (+, -, *, /): ");
scanf(" %c", &operator);
printf("Enter second number: ");
scanf("%lf", &num2);

// Send input to server
sprintf(message, "%.2f,%c,%.2f", num1, operator, num2);
send(sock, message, strlen(message), 0);
printf("Request sent to server...\n");

// Receive response from server
valread = read(sock, buffer, 1024);
printf("Result: %s\n", buffer);
return 0;

