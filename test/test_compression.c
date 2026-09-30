```c
#include "compression.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    CompressionLayer* layer = NULL;
    if (!init_compression_layer(&layer)) {
        fprintf(stderr, "Error initializing compression layer\n");
        return EXIT_FAILURE;
    }
    // Add data and query it
    // free layer
    return EXIT_SUCCESS;
}
```
