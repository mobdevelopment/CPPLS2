#include "main.h"

int Initialize()
{
	// Logging.


	// Enable memory leak detection if we're in a debug build.
	#ifdef UTILS_DEBUG
	utils::EnableMemoryLeakDetection();
	#endif // #ifdef UTILS_DEBUG

	netw::telnet::Server telnetServer(1080);
	telnetServer.AcceptAsync([](netw::telnet::ServerClient& serverClient)
	{
		std::cout << "lmao";
	});

	ui::Context userInterfaceContext;
	ui::cnsl::UserInterface userInterface(userInterfaceContext);
	userInterface.Start();

	// Return 0 for no error.
	return 0;
}

void HandleCriticalError(const std::string& errorMessage)
{
#ifdef UTILS_PLATFORM_WINDOWS
	MessageBox(nullptr, errorMessage.c_str(), "Critical error!", MB_ICONERROR);
#endif // #ifdef UTILS_PLATFORM_WINDOWS
}

int main()
{
	// Top level exception handling but not in debug builds. Makes it harder to
	// debug.
#ifndef UTILS_DEBUG
	try
	{
#endif // #ifndef UTILS_DEBUG
		return Initialize();
#ifndef UTILS_DEBUG
	}
	catch (std::system_error& exception)
	{
		auto errorCode = exception.code();

		HandleCriticalError("The following critical error occurred: '" + 
							std::to_string(errorCode.value()) + ": " +
                        	errorCode.message() + ". " + exception.what() + "'.");

		// Return the error code value.
		return errorCode.value();
	}
	catch (std::exception& exception)
	{
		HandleCriticalError(std::string("The following critical error occurred: '")
                     	   	+ exception.what() + "'.");

		// Return -1 to indicate an unknown or no error code.
		return -1;
	}
	catch (...)
	{
		HandleCriticalError("An unknown critical error occurred. The application
							will now close.");

		// Return -1 to indicate an unknown or no error code.
		return -1;
	}
#endif // #ifndef UTILS_DEBUG
}
