# Emscripten

|Funtions|Desciption|
|-|-|
|emscripten_stack_get_base()|This method returns the base address of the stack memory. It provides the lowest address of the stack memory region used by the Wasm module.|
|emscripten_stack_get_current()|This method returns the current position of the stack pointer. It provides the current address of the stack pointer within the stack memory region.|
|emscripten_stack_get_end()|This method returns the end address of the stack memory region. It indicates the highest address available within the stack memory.|
|emscripten_stack_get_free()|This method returns the amount of free space available on the stack. It calculates the difference between the current stack pointer and the end address of the stack memory region.|
|emscripten_stack_init()|This method initializes the stack memory region for the Wasm module. It sets up the necessary data structures and prepares the stack memory for use.|
