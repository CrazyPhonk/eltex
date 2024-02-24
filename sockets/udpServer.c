#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define MAX_MSG_SIZE 1024

void *handle_client(void* arg) {
    int server_socket = *(int*)arg;
    char buffer[MAX_MSG_SIZE];

    while (1) {
        int recv_len = read(server_socket, buffer, MAX_MSG_SIZE);
        if (recv_len < 0) {
            perror("recvfrom");
            exit(1);
        }

        //buffer[recv_len] = '0';
        printf("Received message %s\n", buffer);
    }
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(1);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(51000);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }
    pthread_t tid;
    while (1) {
        pthread_create(&tid, NULL, &handle_client, &server_socket);
    }

    close(server_socket);
    return 0;
}
