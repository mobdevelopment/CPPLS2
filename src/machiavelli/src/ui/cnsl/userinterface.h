#ifndef MACHIAVELLI_UI_CNSL_USERINTERFACE_HEADER_INCLUDED
#define MACHIAVELLI_UI_CNSL_USERINTERFACE_HEADER_INCLUDED

#include <iostream>
#include <vector>
#include <functional>

#ifdef UTILS_PLATFORM_WINDOWS
#include <stdlib.h>
#endif // UTILS_PLATFORM_WINDOWS

#include <utils/noncopyable.h>
#include <utils/cmd/commandhandler.hpp>
#include <utils/cmd/command.hpp>

#include "../base.h"

namespace ui
{
namespace cnsl
{
	class UserInterface :
		public utils::Noncopyable,
		public utils::cmd::CommandHandler,
		public Base
	{
	private:
		bool				shouldExit = false;

		void ExitCommandHandler(utils::cmd::Command& command);

	public:
		using Base::Base;

		void Start() override;

		void ClearConsole() const noexcept;
	}; // class UserInterface
} // namespace cnsl
} // namespace ui

#endif // #ifndef MACHIAVELLI_UI_CNSL_USERINTERFACE_HEADER_INCLUDED
