# Guided Symbolic Execution on edk2 using STASE technique 

## Step-1: Install KLEE Symbolic Execution Engine
The following steps are tested on Ubuntu.
### Install dependencies:
```
sudo apt-get install build-essential cmake curl file g++-multilib gcc-multilib git libcap-dev libgoogle-perftools-dev libncurses5-dev libsqlite3-dev libtcmalloc-minimal4 python3-pip unzip graphviz doxygen
```
You should also install lit to enable testing, tabulate to support additional features in klee-stats and wllvm to make it easier to compile programs to LLVM bitcode:
```
sudo apt-get install python3-tabulate
sudo pip3 install lit wllvm --break-system-packages
```
### Install LLVM 13:
```
sudo apt-get install clang-13 llvm-13 llvm-13-dev llvm-13-tools
```
### Install constraint solver Z3:
```
git clone https://github.com/Z3Prover/z3.git
cd z3
python3 scripts/mk_make.py
cd build
make
sudo make install
cd ../..
```
### Build uClibc and the POSIX environment model: 
By default, KLEE works on closed programs (programs without external code, such as C library functions). However, if you want to use KLEE to run real programs, you will want to enable the KLEE POSIX runtime, which is built on top of the uClibc C library.
```
git clone https://github.com/klee/klee-uclibc.git
cd klee-uclibc
./configure --make-llvm-lib --with-cc clang-13 --with-llvm-config llvm-config-13
make -j2
cd ..
```
### Build KLEE
Get KLEE source:
```
git clone https://github.com/klee/klee.git
```
KLEE must be built “out of source”:
```
mkdir klee_build
cd klee_build
cmake -DENABLE_SOLVER_Z3=ON -DENABLE_POSIX_RUNTIME=ON -DKLEE_UCLIBC_PATH=../klee-uclibc -DLLVM_CONFIG_BINARY=/usr/bin/llvm-config-13 ../klee
make
```
### Link the executables [Optional]
If you have to execute the generated programs repeatedly, it is helpful to have shortcuts for them.
```
nano ~/.bashrc
```
Put these lines at the end of your ~/.bashrc. Replace the paths corresponding to your directory structure.
```
alias       klee="~/klee_build/bin/klee"
alias       ktest-tool="~/klee_build/bin/ktest-tool"
```

## Step-2: Clone edk2 source code

```
cd stase-edk2
git clone https://github.com/tianocore/edk2.git
cd edk2
git checkout tags/edk2-stable202311
cd ..
```

## Step-3: Generate harness for symbolic execution environment
Process header files for local communication
```
cd edk2
python3 ../process_headers.py $(pwd)
cd ..
```

Remove macros (e.g., STATIC_ASSERT) that are incompatible with symbolic execution.
```
python3 remove_macros.py
```
## Step-4: Generate harness for execution control (Guided symbolic execution)

This steps depend on guidance from static analysis:
- Allocate symbolic values to the variables detected as taint source and sink 
- Allocate symbolic values to global variables
- Substitute non-critical functions with stubs: 
    Example script to generate stubs:
    ```
    python3 generate_stubs.py
    ```
- Add assertions for validation

    Add assertions on the line numbers detected as target locations by static analysis

## Step-5: Build
```
clang-13 -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone klee_driver.c
```
## Step-6: Run Symbolic Execution
```
klee --external-calls=all -libc=uclibc --posix-runtime --smtlib-human-readable  --write-test-info --write-paths --write-smt2s   --write-cov  --write-cvcs --write-kqueries   --write-sym-paths --only-output-states-covering-new --use-query-log=solver:smt2  --simplify-sym-indices klee_driver.bc
```


