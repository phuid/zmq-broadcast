//  Clone server Model One

#include "zmq.hpp"
#include "zmq_addon.hpp"
#include <chrono>
#include <thread>
#include <iostream>
#include <string>

int main (void)
{
    //  Prepare our context and publisher socket
    zmq::context_t ctx(1);
    zmq::socket_t publisher(ctx, zmq::socket_type::pub);
    zmq::socket_t command_receiver(ctx, zmq::socket_type::sub);
    publisher.bind("tcp://*:5556");

    std::cout << "start done" << std::endl;

    uint64_t wahoo = 0;

    while (true) {
        zmq::multipart_t received;
        zmq::recv_multipart(command_receiver, received, zmq::recv_flags::none);

        std::cout << "received parts:";
        for (auto &&msg : received)
        {
            std::cout << msg.str() << ", ";
        }
        std::cout << std::endl;
        

        zmq::multipart_t mp; //will it destruct?
        mp.addstr("SUCCESS");
        mp.addstr("received command \"" + received_cmd_str + "\"");

        publisher.send(mp, zmq::send_flags::none);
        // mp.clear();

        wahoo++;
    }
    return 0;
}