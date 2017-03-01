#include "userinterface.h"

using namespace ui::cnsl;

void UserInterface::ExitCommandHandler(utils::cmd::Command& command)
{
	shouldExit = true;
}

void UserInterface::Start()
{
	// Register the global commands.
	RegisterCommand<>("Exit", std::bind(&UserInterface::ExitCommandHandler, this, std::placeholders::_1));

	// Loop through the incoming console commands.
	while (!shouldExit)
	{
		std::error_code errorBuffer;
		auto command = HandleCommand(std::cin, errorBuffer);

		if (errorBuffer == utils::cmd::Error::UNREGISTERED_COMMAND)
		{
			std::cout << "Invalid command: '" << command.command << "'." << std::endl;
		}
		else if (errorBuffer)
		{
			std::cout << "Something went wrong parsing your command. Please try again." << std::endl;
		}
	}
}

void UserInterface::ClearConsole() const noexcept
{
#ifdef UTILS_PLATFORM_WINDOWS
	system("cls");
#else
	for (unsigned int i = 0; i < 100; i++)
	{
		std::cout << std::endl;
	}
#endif // UTILS_PLATFORM_WINDOWS
}
