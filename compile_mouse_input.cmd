@echo off

clang -c mouse_input.c -o mouse_input.obj

move mouse_input.obj obj

llvm-ar rcs mouse_input.lib obj/mouse_input.obj

move mouse_input.lib lib