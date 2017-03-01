#ifndef MACHIAVELLI_UI_BASE_HEADER_INCLUDED
#define MACHIAVELLI_UI_BASE_HEADER_INCLUDED

#include "context.h"

namespace ui
{
	class Base
	{
	protected:
		Context& context;

	public:
		Base(Context& context) noexcept;
		virtual ~Base() noexcept = 0;

		virtual void Start() = 0;
	}; // class Base
} // namespace ui

#endif // #ifndef MACHIAVELLI_UI_BASE_HEADER_INCLUDED
