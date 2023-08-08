clang sum.c -S -emit-llvm -o sum.ll
clang FuncName.cpp  -fPIC -shared -o libopcode.so -fno-rtti
opt -load ./libopcode.so -CountOpcode -disable-output sum.ll
