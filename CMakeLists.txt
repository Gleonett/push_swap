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

file(GLOB push_swap
        "push_swap/push_swap.c"
        "push_swap/*.c"
        "push_swap/*.h"
        )
file(GLOB common
        *.c
        to_do/*.c
        )

#file(GLOB get_next_line
#        "get_next_line/*.c"
#        "get_next_line/*.h"
#        )

add_executable(checker ${checker} ${libft} ${ft_printf} ${common} print_stack.c)
add_executable(push_swap ${push_swap} ${libft} ${ft_printf} ${common} push_swap/pre_sort.c push_swap/sort_stack.c push_swap/mini_sort.c push_swap/mini_sort_2.c push_swap/push_b.c push_swap/push_a.c push_swap/r_or_rr.c push_swap/cpy_stacks.c push_swap/sort_ten.c "push_swap/Insertion_sort.c" push_swap/insertion_sort.c)
#${libft} ${stack} ${push_swap_lib} push_swap.c)
