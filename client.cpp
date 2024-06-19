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
#include <boost/endian/buffers.hpp>

#define PORT     8080
#define MAXLINE 1024
float getPercent(__s16 value);
float DEADZONE = 0.5;


// Driver code
//Currently has a back and forth communication for axis commands.
int main() {
    int js0 = open("/dev/input/js0", O_RDONLY | O_NONBLOCK);
    if(js0 == -1)
        perror("Couldn't open /dev/input/js0. Make sure controller is plugged in ");
    int status, valread, client_fd, server_fd;
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

    struct js_event event{};
    struct message{
        boost::endian::little_int32_buf_t left_x;
        boost::endian::little_int32_buf_t left_y;
        boost::endian::little_int32_buf_t right_x;
        boost::endian::little_int32_buf_t right_y;

        bool x = false;
        bool y = false;
        bool a = false;
        bool b = false;
        bool start = false;
        bool lb = false;
        bool rb = false;
    }controller;
    controller.left_x = 0;
    controller.left_y = 0;
    controller.right_x = 0;
    controller.right_y = 0;
    controller.a = false;
    while(1) {
        controller.x = false;
        controller.y = false;
//        controller.a = false;
        controller.b = false;
        controller.start = false;
        controller.lb = false;
        controller.rb = false;
        std::string reply;
        while (read(js0, &event, sizeof(event)) > 0) {
            switch (event.type) {
                case JS_EVENT_BUTTON:
                    switch (event.number) {
                        case 0:
                            if (event.value) {
                                controller.a = true;
                            }
                            else{
                                controller.a = false;
                            }
                            break;
                        case 1:
                            if (event.value) {
                                controller.b = true;
                            }
                            break;
                        case 2:
                            break;
                        case 4:
                            controller.lb = true;
                            break;
                        case 5:
                            controller.rb = true;
                            break;
                        case 7:
                            //Turn crank when button is held down
                            controller.start = true;
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
                            if (getPercent(event.value) >= DEADZONE || getPercent(event.value) <= -DEADZONE) {
                                controller.left_x = event.value;
                            } else {
                                controller.left_x = 0;
                            }
                            break;
                        case 1:
                            if (getPercent(event.value) >= DEADZONE || getPercent(event.value) <= -DEADZONE) {
                                controller.left_y = event.value;
                            } else {
                                controller.left_y = 0;
                            }
                            break;
                        case 3:
                            if (getPercent(event.value) >= DEADZONE || getPercent(event.value) <= -DEADZONE) {
                                controller.right_x = event.value;
                            } else {
                                controller.right_x = 0;
                            }
                            break;
                        case 4:
                            if (getPercent(event.value) >= DEADZONE || getPercent(event.value) <= -DEADZONE) {
                                controller.right_y = event.value;
                            } else {
                                controller.right_y = 0;
                            }
                            break;
                        default:
                            break;
                    }
                default:
                    std::cout << "no controller" << std::endl;
                    break;
            }
        }

        int n = sendto(client_fd, &controller, sizeof(controller), 0, (const struct sockaddr *)&serv_addr, sizeof(serv_addr));
        std::cout << "Bytes sent: " << n << std::endl;

        n = recvfrom(client_fd, &buffer, sizeof(buffer), 0, (struct sockaddr *)&serv_addr,
                 reinterpret_cast<socklen_t *>(sizeof(serv_addr)));
        buffer[n] = '\0';
        std::cout << buffer << std::endl;
    }
    // closing the connected socket
    close(client_fd);
    return 0;
}


float getPercent(__s16 value) {
    return (value / 32767.0);
}
