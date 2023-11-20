## 2023.11.09

### Changes

* Rename `main.cpp` to `linked_list.cpp`

* Rename binary file `linked_list` to `kv_linked_list` to avoid name duplication with directory

* Changes in `linked_list.cpp`
** `kv_linked_list` supports new arguments: `-r`, `-d`
** `-r`: Randomize the order of key-value pairs
** `-d`: Print debugging logs

```bash

$ ./kv_linked_list
put key_0
put key_1
put key_2
put key_3
...

get key_0
get key_1
get key_2
...

remove key_0
remove key_1
remove key_2
...

....

$ ./kv_linked_list -r
put key_4
put key_1
put key_8
....

get key_23
get key_1
get key_8
...

remove key_100
remove key_8
remove key_77
...
```

* Changes in `kv_list.cpp`
** `get()` returns `""` if the key is not exist (`string` function should return `string`)

-----------------------------------------------------

### Assignment(?)

* Change `put()` function to put key-value pairs in sorted order
** Use `strcmp` or comparison operators: `=`, `>=`, `<=`, and etc
** Add new argument `-s` which makes `SingleLinkedList` to put key-value pairs in sorted order

* Create new key-value storage that using `vector`
** Make `vector.cpp` that including `main()` function for `kv_vector`
** Make `kv_vector.h` and `kv_vector.cpp` 
** Modify `Makefile` generating both `linked_list` and `vector` binary files

