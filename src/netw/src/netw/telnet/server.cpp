#include "netw/telnet/server.h"

using namespace netw::telnet;

Server::Server(const int port) :
    socket(port)
{
}
