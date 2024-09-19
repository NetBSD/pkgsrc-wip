$NetBSD$

--- src/Makefile.mk.orig	2019-08-13 22:06:36.000000000 +0000
+++ src/Makefile.mk
@@ -15,31 +15,10 @@ ifneq ($(OS),Windows_NT)
   endif
 endif
 
-ifeq ($(OS), OSX)
-  msys_version = 0
-else
-  msys_version := $(if $(findstring Msys, $(shell uname -o)),$(word 1, $(subst ., ,$(shell uname -r))),0)
-endif
-
-ifeq ($(msys_version),0)
-else
-  CROSS=MINGW64
-endif
-ifeq ($(CROSS),MINGW64)
-  CC = x86_64-w64-mingw32-gcc
-  LD = x86_64-w64-mingw32-gcc
-ifeq ($(msys_version),0)
-  AR = x86_64-w64-mingw32-ar
-else
-  AR = ar
-endif
-  EXE = .exe
-else
 #CC = gcc
 #LD = gcc
 CC = clang
 LD = clang
-endif
 
 # for Linux (Ubuntu 12.10 64-bit) or Apple OS/X 10.8
 #CFLAGS  += -g -O0
@@ -107,4 +86,3 @@ $(warning #### Using ../Makefile.local)
 $(warning ####)
 include ../Makefile.local
 endif
-
