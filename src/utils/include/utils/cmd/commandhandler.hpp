#ifndef UTILS_CMD_COMMANDHANDLER_HEADER_INCLUDED
#define UTILS_CMD_COMMANDHANDLER_HEADER_INCLUDED

#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <memory>

#include "errorcategory.h"
#include "command.hpp"

namespace utils
{
namespace cmd
{
	namespace detail
	{
		class CommandParametersParserBase
		{
		public:
			virtual void Parse(std::istream& stream, Command& command) const = 0;
		}; // class CommandParametersParserBase

		template <typename ...Parameters>
		class CommandParametersParser :
			public CommandParametersParserBase
		{
			void Parse(std::istream& stream, Command& command) const override
			{
				detail::ParseCommandParameters<Parameters...>(stream, command);
			}
		}; // class CommandParametersParser
	}

	class CommandHandler
	{
		typedef std::function<void(Command&)> CommandCallback;
		typedef std::unordered_map<std::string, std::pair<const std::shared_ptr<const detail::CommandParametersParserBase>, const CommandCallback>> CommandHandlersContainer;

	private:
		CommandHandlersContainer commandHandlers;

	public:
		template <typename ...Parameters>
		void RegisterCommand(const std::string commandName, CommandCallback commandCallback)
		{
			commandHandlers.emplace(commandName, std::make_pair(new detail::CommandParametersParser<Parameters...>, commandCallback));
		}

		void UnregisterCommand(const std::string commandName)
		{
			commandHandlers.erase(commandName);
		}

		Command HandleCommand(std::istream& stream) const
		{
			Command command;

			// Parse the incoming command to a string stream buffer.
			std::stringstream streamBuffer;
			std::string line;
			std::getline(stream, line);
			if (!stream)
				throw std::system_error(utils::cmd::Error::STREAM_ERROR);

			streamBuffer << line;

			std::getline(streamBuffer, command.command, ' ');
			if (!stream)
				throw std::system_error(utils::cmd::Error::STREAM_ERROR);

			// Check if the command is registered.
			auto commandHandler = commandHandlers.find(command.command);
			if (commandHandler == commandHandlers.end())
				throw std::system_error(Error::UNREGISTERED_COMMAND);

			// Parse the command parameters.
			commandHandler->second.first->Parse(streamBuffer, command);

			// Call the command handler callback.
			commandHandler->second.second(command);

			return command;
		}

		Command HandleCommand(std::istream& stream, std::error_code& errorBuffer) const
		{
			try
			{
				return HandleCommand(stream);
			}
			catch (std::system_error exception)
			{
				errorBuffer = exception.code();
				return Command();
			}
		}
	}; // class CommandHandler
} // namespace cmd
} // namespace utils

#endif // #ifndef UTILS_CMD_COMMANDHANDLER_HEADER_INCLUDED
