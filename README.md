# Guided Symbolic Execution

## Clone edk2 source code

```
cd stase-edk2
git clone https://github.com/tianocore/edk2.git
cd edk2
git checkout tags/edk2-stable202311
cd ..
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


