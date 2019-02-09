cmake_minimum_required(VERSION 3.13)
project(push_swap C)

set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

file(GLOB libft
        "ft_printf/libft/*.h"
        "ft_printf/libft/*.c"
        )
file(GLOB ft_printf
        "ft_printf/*.h"
        "ft_printf/*.c"
        "ft_printf/utils/*.c"
        "ft_printf/check_fmt/*.c"
        "ft_printf/get_types/*.c"
        "ft_printf/print/*.c"
        "ft_printf/va_functions/*.c"
        "ft_printf/get_types/*.c"
        )
file(GLOB checker
        "checker/*.h"
        "checker/*.c"
        )

#file(GLOB push_swap_lib
#        "push_swap_lib/*.c"
#        "push_swap_lib/*.h"
#        )

#file(GLOB get_next_line
#        "get_next_line/*.c"
#        "get_next_line/*.h"
#        )

add_executable(checker ${libft} ${checker} ${ft_printf} check_args.c init_stack.c stack.c)
add_executable(push_swap ${libft} ${checker})
#${libft} ${stack} ${push_swap_lib} push_swap.c)
