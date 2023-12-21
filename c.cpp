//  Clone client Model One

#include "zmq.hpp"
#include "zmq_addon.hpp"
#include <iostream>

int main(void)
{
    //  Prepare our context and updates socket
    zmq::context_t ctx(1);
    zmq::socket_t subscriber(ctx, zmq::socket_type::sub);
    subscriber.connect("tcp://localhost:5556");
    subscriber.set(zmq::sockopt::subscribe, "");

    std::cout << "start done" << std::endl;

    while (true)
    {
        // while rcv(zmq::rec_flags::no wait) receive server output

        std::vector<zmq::message_t> recv_msgs;
        zmq::recv_result_t result =
            zmq::recv_multipart(subscriber, std::back_inserter(recv_msgs));
        assert(result && "recv failed");
        assert(*result == 2);

        std::cout << recv_msgs[0].to_string() << std::endl;
    }
    return 0;
}