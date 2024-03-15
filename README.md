# Guided Symbolic Execution on edk2 using STASE technique 

## Install KLEE Symbolic Execution Engine
The following steps are tested on Ubuntu.
### 1. Install dependencies:
```
sudo apt-get install build-essential cmake curl file g++-multilib gcc-multilib git libcap-dev libgoogle-perftools-dev libncurses5-dev libsqlite3-dev libtcmalloc-minimal4 python3-pip unzip graphviz doxygen
```
You should also install lit to enable testing, tabulate to support additional features in klee-stats and wllvm to make it easier to compile programs to LLVM bitcode:
```
sudo apt-get install python3-tabulate
sudo pip3 install lit wllvm --break-system-packages
```
### 2. Install LLVM 13:
```
sudo apt-get install clang-13 llvm-13 llvm-13-dev llvm-13-tools
```
### 3. Install constraint solver Z3:
```
git clone https://github.com/Z3Prover/z3.git
cd z3
python3 scripts/mk_make.py
cd build
make
sudo make install
cd ..
```
### 4. Build uClibc and the POSIX environment model: 
By default, KLEE works on closed programs (programs without external code, such as C library functions). However, if you want to use KLEE to run real programs, you will want to enable the KLEE POSIX runtime, which is built on top of the uClibc C library.
```
git clone https://github.com/klee/klee-uclibc.git
cd klee-uclibc
./configure --make-llvm-lib --with-cc clang-13 --with-llvm-config llvm-config-13
make -j2
cd ..
```

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


