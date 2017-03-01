#ifndef NETW_TELNET_SERVER_HEADER_INCLUDED
#define NETW_TELNET_SERVER_HEADER_INCLUDED

#include <functional>

#include <Socket.h>

#include <utils/noncopyable.h>

#include "serverclient.h"

namespace netw
{
namespace telnet
{
	class Server :
		utils::Noncopyable
	{
	private:
		ServerSocket socket;

		template<typename Callback>
		void AcceptCallback(Socket socket, Callback callback)
		{
			callback(ServerClient(socket));
		}

	public:
		Server(const int port);

		template<typename Callback>
		void AcceptAsync(Callback callback)
		{
			socket.accept(std::bind(&Server::AcceptCallback<Callback>, this, std::placeholders::_1, callback));
		}
	}; // class Server
} // namespace telnet
} // namespace netw

#endif // #ifndef NETW_TELNET_SERVER_HEADER_INCLUDED
