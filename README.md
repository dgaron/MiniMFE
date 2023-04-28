# MiniMFE

### v1
* This is the original version of the program

### readable
* This is semantically the same as the original version
* Replaces the computation macros with their corresponding definitions
* Uses a decrementing loop counter for the outer loop which improves readability

### verbose
* This version will print the reads and writes to the H and T structures to aid in observing the memory access pattern

### Nmem
* This version allocates only N+1 memory for H by overwriting values that are no longer needed
* Now updated so that the writes are schedule independent

### Tile
* Tiles the inner loops
* Rectangular tiles, width > height
