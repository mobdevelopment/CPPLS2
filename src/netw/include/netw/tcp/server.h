#ifndef NETW_TCP_SERVER_HEADER_INCLUDED
#define NETW_TCP_SERVER_HEADER_INCLUDED

#include <stdint.h>

namespace netw
{
namespace tcp
{
	class Server
	{
    public:
        void Listen(const uint16_t port);
        void StopListening();
        void Accept();
	}; // class Server
} // namespace tcp
} // namespace netw

#endif // #ifndef NETW_TCP_SERVER_HEADER_INCLUDED
