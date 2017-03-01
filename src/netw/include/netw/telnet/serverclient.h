#ifndef NETW_TELNET_SERVERCLIENT_HEADER_INCLUDED
#define NETW_TELNET_SERVERCLIENT_HEADER_INCLUDED

#include <Socket.h>

#include <utils/noncopyable.h>

namespace netw
{
namespace telnet
{
	class ServerClient :
		utils::Noncopyable
	{
	private:
		Socket socket;

	public:
		ServerClient(Socket& socket);
	}; // class ServerClient
} // namespace telnet
} // namespace netw

#endif // #ifndef NETW_TELNET_SERVERCLIENT_HEADER_INCLUDED
