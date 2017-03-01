#include "netw/telnet/serverclient.h"

using namespace netw::telnet;

ServerClient::ServerClient(Socket& socket) :
    socket(std::move(socket))
{
}
