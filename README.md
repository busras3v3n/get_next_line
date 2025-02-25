# get_next_line

get_next_line() is a function that reads from a file descriptor, one line at a time.<br>

`char *get_next_line(int fd)`<br><br>
Calling get_next_line() once will return the first line of a file descriptor, and the second call will return the second line, and so on and so forth...<br>It returns NULL when EOF (end of file) is reached.<br>
I use this function in many of my other C projects.<br><br>
It uses [read()](https://man7.org/linux/man-pages/man2/read.2.html) to read from 'fd', using BUFFER_SIZE as the size of the buffer.<br>

## Bonus

[get_next_line()](./get_next_line.c) doesn't work correctly when it's used with multiple different file descriptors in the same main().<br>
I've fixed this issue in the [bonus version](./get_next_line_bonus.c) by declaring the static buffer as a two dimensional array.<br>
This approach prevents the shared use of the same buffer by different file descriptors, which in turn prevents incorrect returns.<br>

## Usage

Compile with option `-D BUFFER_SIZE=n` to specify the buffer size for read(). If the option is not used, it will use the default buffer size defined in [the header](./get_next_line.h).<br>
