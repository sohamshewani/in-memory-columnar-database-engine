```c
#include "core.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    CoreEngine* engine = NULL;
    if (!init_core_engine(&engine, 10, 5)) {
        fprintf(stderr, "Error initializing core engine\n");
        return EXIT_FAILURE;
    }
    // Add data and query it
    // free engine
    return EXIT_SUCCESS;
}
```
