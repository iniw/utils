if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set(COMPILE_OPTIONS
		-std=c++2b
		-pedantic

		-Wall
		-Werror
		-Wextra

		-Wno-gnu-statement-expression

		-Wcast-qual
		-Wconversion
		-Wdeprecated-copy
		-Wformat=2
		-Wimplicit-fallthrough
		-Wmissing-declarations
		-Wnon-virtual-dtor
		-Wold-style-cast
		-Wshadow
		-Wundef
		-Wunused
		-Wwrite-strings

		-fconstexpr-steps=16777216
		-fdiagnostics-color=always
		-fno-delete-null-pointer-checks
		-fno-exceptions
	)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	set(COMPILE_OPTIONS
		/std:c++latest
		/W4
		/MP
		/utf-8
	)
endif()
