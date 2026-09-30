```c
#include <stdio.h>
#include <stdlib.h>

// Error Handling Module
void handle_error(int error_code) {
    switch (error_code) {
        case ENOMEM:
            fprintf(stderr, "Error: Out of memory\n");
            break;
        case ENOTSUP:
            fprintf(stderr, "Error: Not supported\n");
            break;
        case EIO:
            fprintf(stderr, "Error: Input/Output error\n");
            break;
        default:
            fprintf(stderr, "Unknown error: %d\n", error_code);
            break;
    }
    exit(EXIT_FAILURE);
}
```
