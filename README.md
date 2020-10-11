# Hw077

Demonstrate how stack memory is allocated by dumping the contents of memory beween a pairs of arrays allocated with automatic storage duration.

Example:

```c
char carry[9] = { 'c', 'a', 'f', 'e', 'b', 'a', 'b', 'e', '\0', };
size_t carry_sz = sizeof(carry);
short sarry[2] = { SHRT_MIN, SHRT_MAX, };
size_t sarry_sz = sizeof(sarry);
```
Dump data between start of the __`sarry`__ array and end of the __`carry`__ array (_44 bytes_) shows:

## Output
```
$ # Compiled with clang:
$ clang -Wall -std=gnu18 -o ./hw077 hw077.c ./snap.c && ./hw077 
cap  - 0x7ffedfee344f, 0x7ffedfee3458, 9
sap  - 0x7ffedfee342c, 0x7ffedfee3430, 4
snap - 0x7ffedfee342c, 0x7ffedfee3458, 44
0x7ffedfee342c:
0000: 0080ff7f09000000 000000008834eedf fe7f000000000000 0100000000000000  ........ .....4.. ........ ........ 
0020: 0000006361666562 61626500                                            ...cafeb abe.                       

$ # Compiled with GNU gcc:
$ gcc-10 -Wall -std=gnu18 -o ./hw077 hw077.c ./snap.c && ./hw077 
cap  - 0x7ffee007a40f, 0x7ffee007a418, 9
sap  - 0x7ffee007a40a, 0x7ffee007a40e, 4
snap - 0x7ffee007a40a, 0x7ffee007a418, 14
0x7ffee007a40a:
0000: 0080ff7f00636166 656261626500                                        .....caf ebabe.                     
```
## Gist Sample
See also this [Gist](https://gist.github.com/alansam/1986e27be077209faaa94e375aecc33a)
