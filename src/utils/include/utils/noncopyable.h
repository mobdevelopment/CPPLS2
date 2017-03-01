#ifndef UTILS_NONCOPYABLE_HEADER_INCLUDED
#define UTILS_NONCOPYABLE_HEADER_INCLUDED

namespace utils
{
  class Noncopyable
  {
  private:
	  Noncopyable(const Noncopyable&) = delete;
	  Noncopyable& operator=(const Noncopyable&) = delete;

  protected:
    Noncopyable() = default;
    ~Noncopyable() = default;
  }; // class Noncopyable
} // namespace utils

#endif // #ifndef UTILS_NONCOPYABLE_HEADER_INCLUDED
