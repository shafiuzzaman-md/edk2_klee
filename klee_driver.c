#include "klee/klee.h"
#include "edk2/MdeModulePkg/Universal/Variable/RuntimeDxe/VariableSmm.c"

int main()
{
  MmVariableServiceInitialize();
}