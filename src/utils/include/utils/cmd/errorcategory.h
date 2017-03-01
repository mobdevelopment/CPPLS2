#ifndef UTILS_CMD_ERRORCATEGORY_HEADER_INCLUDED
#define UTILS_CMD_ERRORCATEGORY_HEADER_INCLUDED

#include <system_error>
#include <string>

#include "error.h"

namespace utils
{
namespace cmd
{
	class ErrorCategory :
		public std::error_category
	{
	public:
		virtual const char* name() const noexcept;
		virtual std::string message(int ev) const;
	}; // class ErrorCategory

	const std::error_category& GetErrorCategory();
} // namespace utils
} // namespace utils

namespace std
{
	template <>
	struct is_error_code_enum<utils::cmd::Error> :
		public true_type
	{
	}; // struct is_error_code_enum<utils::cmd::Error>

	error_code make_error_code(utils::cmd::Error error);
	error_condition make_error_condition(utils::cmd::Error error);
} // namespace std

#endif // #ifndef UTILS_CMD_ERRORCATEGORY_HEADER_INCLUDED
