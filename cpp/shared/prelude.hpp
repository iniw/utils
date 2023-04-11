#pragma once

#include <cstddef>
#include <cstdint>
#include <fmt/core.h>
#include <fmt/xchar.h>
#include <string_view>
#include <utility>

using i8 = ::std::int8_t;
using i16 = ::std::int16_t;
using i32 = ::std::int32_t;
using i64 = ::std::int64_t;

using u8 = ::std::uint8_t;
using u16 = ::std::uint16_t;
using u32 = ::std::uint32_t;
using u64 = ::std::uint64_t;

using usize = ::std::size_t;
using isize = ::std::make_signed_t<usize>;

using f32 = float;
using f64 = double;

using uptr = ::std::uintptr_t;
using ptrdiff = ::std::ptrdiff_t;

using ::std::forward;
using ::std::move;

template<typename... Args>
inline void dbg(fmt::format_string<Args...> fmt, Args&&... args) {
    ::fmt::print(stdout, fmt, forward<Args>(args)...);
}

template<typename... Args>
inline void dbg(fmt::wformat_string<Args...> fmt, Args&&... args) {
    ::fmt::print(stdout, fmt, forward<Args>(args)...);
}

template<typename... Args>
inline void dbgln(fmt::format_string<Args...> fmt, Args&&... args) {
    ::fmt::print(stdout, fmt, forward<Args>(args)...);
    ::fmt::print(stdout, "\n");
}

template<typename... Args>
inline void dbgln(fmt::wformat_string<Args...> fmt, Args&&... args) {
    ::fmt::print(stdout, fmt, forward<Args>(args)...);
    ::fmt::print(stdout, "\n");
}

template<typename... Args>
inline void err(fmt::format_string<Args...> fmt, Args&&... args) {
    ::fmt::print(stderr, "error: ");
    ::fmt::print(stderr, fmt, forward<Args>(args)...);
}

template<typename... Args>
inline void err(fmt::wformat_string<Args...> fmt, Args&&... args) {
    ::fmt::print(stderr, "error: ");
    ::fmt::print(stderr, fmt, forward<Args>(args)...);
}

template<typename... Args>
inline void errln(fmt::format_string<Args...> fmt, Args&&... args) {
    ::fmt::print(stderr, "error: ");
    ::fmt::print(stderr, fmt, forward<Args>(args)...);
    ::fmt::print(stderr, "\n");
}

template<typename... Args>
inline void errln(fmt::wformat_string<Args...> fmt, Args&&... args) {
    ::fmt::print(stderr, "error: ");
    ::fmt::print(stderr, fmt, forward<Args>(args)...);
    ::fmt::print(stderr, "\n");
}

using namespace std::literals::string_view_literals;
