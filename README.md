# Get Next Line

## Overview

**Get Next Line** is a 42 project focused on creating a C function that reads one line at a time from a file descriptor. The project emphasizes efficient memory handling and introduces static variables while adhering to strict coding rules.

---

## Files

### Mandatory Part
- `get_next_line.c`: Core implementation.
- `get_next_line.h`: Header file with function prototypes.
- `get_next_line_utils.c`: Utility functions for `get_next_line`.

### Bonus Part
- `get_next_line_bonus.c`: Handles multiple file descriptors.
- `get_next_line_bonus.h`: Header file for the bonus part.
- `get_next_line_utils_bonus.c`: Utility functions for the bonus implementation.

---

## Function Prototype

```c
char *get_next_line(int fd);
```
- Reads and returns the next line from the given file descriptor.
- Returns NULL if an error occurs or EOF is reached.
- The line includes the newline character (\n) if present

## Features
- Mandatory: Reads a single line from a file descriptor.
- Bonus:
  - Handles multiple file descriptors simultaneously.
  - Uses a single static variable for memory management.

## Restrictions
- Only read, malloc, and free are allowed.
- Global variables are forbidden.
- Behavior is undefined for binary files or modified files during execution.

## Testing
To test the function, create your own main.c file. Here’s an example:
```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void) {
    int fd = open("test_file.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
```

## Compilation
Compile the files while defining the BUFFER_SIZE macro. For example:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

For the bonus part:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```
Replace 42 with any desired buffer size to test various scenarios.

## Usage
1. Create a file named test_file.txt containing multiple lines of text.
2. Run the program:
```bash
./gnl
```
Or for the bonus:
```bash
./gnl_bonus
```

## Notes on Testing
- Experiment with different BUFFER_SIZE values (e.g., 1, 999, or even 1000000) to see how your function performs.
- Test with edge cases, like empty files, very large files, and files with no newline characters.




