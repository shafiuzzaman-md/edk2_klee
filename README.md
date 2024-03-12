# edk2_klee

## Clone edk2 source code

```
cd edk2_klee

git clone https://github.com/tianocore/edk2.git

```

## Preprocessing
Process header files for local communication
```
python3 process_headers.py <physical_path_of_edk2>
```

Remove macros (e.g., STATIC_ASSERT) that are incompatible with symbolic execution.
```
python3 remove_macros.py
```

## Build and Run
```
clang-13 -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone klee_driver.c

klee --external-calls=all -libc=uclibc --posix-runtime --smtlib-human-readable  --write-test-info --write-paths --write-smt2s   --write-cov  --write-cvcs --write-kqueries   --write-sym-paths --only-output-states-covering-new --use-query-log=solver:smt2  --simplify-sym-indices klee_driver.bc

```


