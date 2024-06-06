// Client side implementation of UDP client-server model 
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include "linux/joystick.h"
#include "js_event.pb.h"


#define PORT     8080
#define MAXLINE 1024

void serialize(js_event* event, char* data);
void deserialize(char* data, js_event* event);
void printEvent(js_event event);
void send(int sock, const std::string& msg);
void read(int new_socket, std::string &msg);
float getPercent(__s16 value);
float DEADZONE = 0.5;
// Driver code
//Currently has a back and forth communication for axis commands.
int main() {
//    sleep(8);
//    controller::jsEvent eventMSG;
    int js0 = open("/dev/input/js0", O_RDONLY | O_NONBLOCK);
    if(js0 == -1)
        perror("Couldn't open /dev/input/js0. Make sure controller is plugged in ");
    int status, valread, client_fd;
    struct sockaddr_in serv_addr;
    char buffer[1024] = { 0 };
    if ((client_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    // form
//    "192.168.2.1"
//    "127.0.0.1",
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

//    if ((status = connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0) {
//        printf("\nConnection Failed \n");
//        return -1;
//    }

//    valread = read(client_fd, buffer,
//                   1024 - 1); // subtract 1 for the null
    // terminator at the end
//    printf("%s\n", buffer);
    struct js_event event{};
    controller::Xbox controller;
    controller::Axes axes;
    controller::Buttons buttons;
    controller.set_allocated_axes(&axes);
    controller.set_allocated_buttons(&buttons);
    axes.set_l_x(0);
    axes.set_l_y(0);
    axes.set_r_x(0);
    axes.set_r_y(0);
    buttons.set_a(false);
    buttons.set_b(false);
    buttons.set_x(false);
    buttons.set_y(false);
    buttons.set_start(false);
    buttons.set_lb(false);
    buttons.set_rb(false);
    while(1) {
        buttons.set_b(false);
        buttons.set_x(false);
        buttons.set_y(false);
        buttons.set_start(false);
        buttons.set_lb(false);
        buttons.set_rb(false);

        std::string data;
        std::string reply;
        while (read(js0, &event, sizeof(event)) > 0) {
            switch (event.type) {
                case JS_EVENT_BUTTON:
                    switch (event.number) {
                        case 0:
                            if (event.value) {
                                buttons.set_a(true);
                            }
                            else{
                                buttons.set_a(false);
                            }
                            break;
                        case 1:
                            if (event.value) {
                                buttons.set_b(true);
                            }
                            break;
                        case 2:
                            break;
                        case 4:
                            buttons.set_lb(true);
                            break;
                        case 5:
                            buttons.set_rb(true);
                            break;
                        case 7:
                            //Turn crank when button is held down
                            buttons.set_start(true);
                            break;
                        default:
                            std::cout << "Button " << (int) event.number << " "
                                      << (event.value ? "pressed" : "released")
                                      << std::endl;
                            break;
                    }
                case JS_EVENT_AXIS:
                    switch (event.number) {
                        case 0:
                            if (getPercent(event.value) >= DEADZONE || getPercent(event.value) <= -DEADZONE){
                                axes.set_l_x(event.value);
                            }
                            else{
                                axes.set_l_x(0);
                            }
                            break;
                        case 1:
                            if (getPercent(event.value) >= DEADZONE || getPercent(event.value) <= -DEADZONE){
                                axes.set_l_y(event.value);
                            }
                            else{
                                axes.set_l_y(0);
                            }
                            break;
                        case 3:
                            if (getPercent(event.value) >= DEADZONE || getPercent(event.value) <= -DEADZONE){
                                axes.set_r_x(event.value);
                            }
                            else{
                                axes.set_r_x(0);
                            }
                            break;
                        case 4:
                            if (getPercent(event.value) >= DEADZONE || getPercent(event.value) <= -DEADZONE){
                                axes.set_r_y(event.value);
                            }
                            else{
                                axes.set_r_y(0);
                            }
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
        controller.SerializeToString(&data);
//        std::cout << data.length() << std::endl;
        const char* msg = "Hello";
        std::cout << strlen(msg) << std::endl;
        sendto(client_fd, (const char *)msg, strlen(msg), 0, (const struct sockaddr *)&serv_addr, sizeof(serv_addr));
//        sendto(client_fd, &data, data.length(), 0, (const struct sockaddr *)&serv_addr, sizeof(serv_addr)); //udp send
//        send(client_fd, data);
//
//        read(client_fd, reply);
//        std::cout << reply << std::endl;
    }
    // closing the connected socket
    close(client_fd);
    return 0;
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

float getPercent(__s16 value) {
    return (value / 32767.0);
}

//basic serialzation works, now send a joystick command to a server and have it print out that command.
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