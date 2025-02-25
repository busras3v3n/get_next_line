# get_next_line

get_next_line() is a function that reads from a file descriptor, one line at a time.<br>

`char *get_next_line(int fd)`<br><br>
Calling get_next_line() once will return the first line of a file descriptor, and the second call will return the second line, and so on and so forth...<br>
It uses [read()](https://man7.org/linux/man-pages/man2/read.2.html) to read from 'fd', using BUFFER_SIZE as the size of the buffer.<br>
Compile with option `-D BUFFER_SIZE=n` to specify the buffer size. If the option is not used, it will use the buffer size defined in [the header](./get_next_line.h).<br>

## Bonus

get_next_line() doesn't work correctly when it's used with multiple different file descriptors in the same main()<br>
