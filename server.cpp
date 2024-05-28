//
// Created by shawn on 5/7/24.
//
// Server side implementation of UDP client-server model
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <linux/joystick.h>
#include <fcntl.h>
#include "js_event.pb.h"

void serialize(js_event* event, char* data);
void deserialize(char* data, js_event* event);
void printEvent(js_event event);
void send(int sock, const std::string& msg);
void read(int new_socket, std::string &msg);

#define PORT	 8080
#define MAXLINE 1024

// Driver code
int main() {
    controller::Xbox MSG;
    int server_fd, new_socket;
    ssize_t valread;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);
    char buffer[1024] = { 0 };
//    char* hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address,
             sizeof(address))
        < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket
                 = accept(server_fd, (struct sockaddr*)&address,
                          &addrlen))
        < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

//    data[valread] = '\0';
//    RC Client::jsEvent MSG;
//    MSG.set_time(2);
//    MSG.set_value(2);
//    MSG.set_type(2);
//    MSG.set_number(2);
//    std::cout << MSG.ParseFromString(data) << std::endl;
//TODO: implement server side of controller copy
while(1) {
    std::string message;
    std::string reply;
    read(new_socket, message);
    MSG.ParseFromString(message);
    if(MSG.has_axes()){
        std::cout << MSG.axes().l_x() << " " << MSG.axes().l_y() << "  " << MSG.axes().r_x() << " " << MSG.axes().r_y() << std::endl;
        reply = "OK";
        send(new_socket, reply);
    }
    else{
        reply = "BAD";
        send(new_socket, reply);
    }


//    std::cout << std::to_string(MSG.time()) << std::endl;
//    std::cout << std::to_string(MSG.type()) << std::endl;
//    std::cout << std::to_string(MSG.value()) << std::endl;
//    std::cout << std::to_string(MSG.number()) << std::endl;
//    js_event event;
//    event.time = MSG.time();
//    event.value = MSG.value();
//    event.type = MSG.type();
//    event.number = MSG.number();
//    std::cout << event.time << std::endl;
//    std::cout << std::to_string(event.type) << std::endl;
//    std::cout << event.value << std::endl;
//    std::cout << std::to_string(event.number) << std::endl;
}
//    deserialize(buffer,&event);
//    printEvent(event);

    return 0;
}

void read(int new_socket, std::string &msg) {
    int valread;
    char buffer_header[sizeof(size_t)] = {0};
    valread = read( new_socket , buffer_header, sizeof(size_t)); //receive how large the message data will be

    size_t msg_size;
    memcpy(&msg_size, buffer_header, sizeof(size_t));

    char* buffer_msg = (char*)malloc(msg_size*sizeof(char)); //allocate that space in memory
    memset(buffer_msg, '\0', sizeof(char)*msg_size); //fill that space with NULL
    int length = 0;
    for(length = 0; msg_size != 0; length += valread) {
        valread = read( new_socket , buffer_msg+length, msg_size); //fill that space with incoming data until it is full
        msg_size -= valread;
    }

    msg = std::string(buffer_msg, length); //save that data to the desired string
    free(buffer_msg); //free the memory from the buffer.
}
void send(int sock, const std::string& msg) {
    size_t msg_size = msg.length(); //get what the size of the message will be
    char header[sizeof(size_t)]; //make enough space to hold the msg_size
    memset(header, '\0', sizeof(size_t)); //fill that 64 bit space wih NULL
    memcpy(header, (char*) &msg_size, sizeof(size_t)); //copy what the size of the message will be into that space
    send(sock, header, sizeof(size_t), 0); //send how large the message will be
    send(sock, msg.c_str(), msg_size, 0 ); //send the message data
    std::cout << "msg sent to server...\n";
}
//TODO: replace with gRPC
void serialize(js_event *event, char* data){
    int *q = (int *)data;
    *q = event->time; q++;
    *q = event->value; q++;
    *q = event->type; q++;
    *q = event->number; q++;
}
void deserialize(char* data, js_event *event){
    int *q = (int*)data;
    event->time = *q;    q++;
    event->value = *q;   q++;
    event->type = *q;     q++;
    event->number =*q;
}
void printEvent(js_event event){
    std::cout << event.time<< std::endl;
    std::cout << event.value << std::endl;
    std::cout << unsigned(event.type) << std::endl;
    std::cout << unsigned(event.number) << std::endl;
}