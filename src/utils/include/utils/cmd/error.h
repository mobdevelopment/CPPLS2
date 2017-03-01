#ifndef UTILS_CMD_ERROR_HEADER_INCLUDED
#define UTILS_CMD_ERROR_HEADER_INCLUDED

namespace utils
{
namespace cmd
{
  enum class Error
  {
    SUCCESS,
    UNREGISTERED_COMMAND,
    STREAM_ERROR,
    INVALID_ARGUMENT_VALUE
  }; // enum class Error
} // namespace utils
} // namespace utils

#endif // #ifndef UTILS_CMD_ERROR_HEADER_INCLUDED
