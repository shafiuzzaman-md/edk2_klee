# edk2_klee

## Preprocessing
This updates headerfiles of edk2 source to prepare it for running klee on it. 
```
python3 process_headers.py <path_to_edk2>
```

This comments out assert statements(such as STATIC_ASSERT) to prepare the source for running klee on it. 
```
python3 remove_asserts.py
```

The edk2 source (edk2-master) in this repo has already been updated using the scripts


## Build and Run
```
clang-13 -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone klee_driver.c

klee --external-calls=all -libc=uclibc --posix-runtime --smtlib-human-readable  --write-test-info --write-paths --write-smt2s   --write-cov  --write-cvcs --write-kqueries   --write-sym-paths --only-output-states-covering-new --use-query-log=solver:smt2  --simplify-sym-indices klee_driver.bc

```


