#ifndef UTILS_CMD_COMMAND_HEADER_INCLUDED
#define UTILS_CMD_COMMAND_HEADER_INCLUDED

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <system_error>
#include <memory>

#include "errorcategory.h"

namespace utils
{
namespace cmd
{
	class Command;

	namespace detail
	{
		template<typename... Parameters>
		struct ParseCommandParametersImpl;

		template<typename Parameter, typename... Parameters>
		struct ParseCommandParametersImpl<Parameter, Parameters...>
		{
			static void Parse(std::istream& stream, Command& command)
			{
				Parameter parameter;

				// Parse the parameter.
				stream >> parameter;

				// Check if parsing went ok.
				if (stream.fail())
					throw std::system_error(utils::cmd::Error::INVALID_ARGUMENT_VALUE);
				else if (!stream)
					throw std::system_error(utils::cmd::Error::STREAM_ERROR);

				command.AddParameter(parameter);

				ParseCommandParametersImpl<Parameters...>::Parse(stream, command);
			}
		}; // struct ParseCommandParametersImpl<Parameter, Parameters...>

		template<>
		struct ParseCommandParametersImpl<>
		{
			static void Parse(std::istream& stream, Command& command)
			{
			}
		}; // struct ParseCommandParametersImpl<>

		template<typename ...Parameters>
		void ParseCommandParameters(std::istream& stream, Command& command)
		{
			ParseCommandParametersImpl<Parameters...>::Parse(stream, command);
		}
	} // namespace detail

	class Command
	{
		class Parameter
		{
		public:
			const std::shared_ptr<void> p;

			Parameter(const std::shared_ptr<void> p) noexcept :
				p(p)
			{
			}
		}; // class Parameter

	private:
		std::vector<Parameter> parameters;

	public:
		std::string command;

		unsigned int GetAmountOfParameters() const noexcept
		{
			return parameters.size();
		}

		template<typename ParameterType>
		void AddParameter(ParameterType parameter)
		{
			parameters.emplace_back(std::make_shared<ParameterType>(std::move(parameter)));
		}

		template<typename T>
		std::shared_ptr<T> GetParameter(const unsigned int index) const
		{
			return static_pointer_cast<T>(parameters.at(index).p);
		}
	}; // class Command

	template<typename ...Parameters>
	Command ParseCommand(std::istream& stream)
	{
		Command command;

		// Get the command.
		std::getline(stream, command.command, ' ');
		if (stream.fail())
			throw std::system_error(utils::cmd::Error::INVALID_ARGUMENT_VALUE);
		else if (!stream)
			throw std::system_error(utils::cmd::Error::STREAM_ERROR);

		// Recursively get the parameters.
		detail::ParseCommandParameters<Parameters...>(stream, command);

		return command;
	}

	template<typename ...Parameters>
	Command ParseCommand(std::istream& stream, std::error_code& errorBuffer)
	{
		try
		{
			return ParseCommand<Parameters...>(stream);
		}
		catch (std::system_error exception)
		{
			errorBuffer = exception.code();
		}
	}
} // namespace cmd
} // namespace utils

#endif // #ifndef UTILS_CMD_COMMAND_HEADER_INCLUDED
