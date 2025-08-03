@echo off

clang -c calculate_ms.c -o calculate_ms.obj

move calculate_ms.obj obj

llvm-ar rcs calculate_ms.lib obj/calculate_ms.obj

move calculate_ms.lib lib