```c
#include "scan_engine.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    ScanEngine* engine = NULL;
    if (!init_scan_engine(&engine)) {
        fprintf(stderr, "Error initializing scan engine\n");
        return EXIT_FAILURE;
    }
    // Add data and query it
    // free engine
    return EXIT_SUCCESS;
}
```
