# edk2_klee
```
python3 process_headers.py <path_to_edk2>

python3 generate_stubs.py

clang-13 -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone klee_driver.c

klee --external-calls=all -libc=uclibc --posix-runtime --smtlib-human-readable  --write-test-info --write-paths --write-smt2s   --write-cov  --write-cvcs --write-kqueries   --write-sym-paths --only-output-states-covering-new --use-query-log=solver:smt2  --simplify-sym-indices klee_driver.bc

```


