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

### tile
* Tiles the inner loops
* Rectangular tiles, width > height

### transpose
* Keeps a copy of T matrix transpose for locality improvement in the k loop

### transpose 1x
* Stores the transpose of upper triangular matrix T in the unused lower triangle of the allocated memory space

### swapJK
* Inlines the 'k' loop that was buried in the function call to reduce_MiniMFE_T_1()
* Swaps the 'j' and 'k' loops:
  * Initializes each entry in the row
  * Iterates over rows, updating each entry, taking advantage of the associativity of the min operation
  * Allows for auto-vectorization by the compiler
