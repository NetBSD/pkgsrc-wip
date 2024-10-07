$NetBSD$

# Portability

--- rules.mak.orig	2020-05-25 20:52:22.000000000 +0000
+++ rules.mak
@@ -12,23 +12,22 @@ ifndef CXX
 CXX      := g++
 endif
 
-ifneq (,$(findstring /,$(shell whereis ccache)))
-CXX      := ccache $(CXX)
-endif
-
 CFLAGS   += --std=c++2a
 CFLAGS   += -fno-strict-aliasing -fexceptions -fPIC
 CFLAGS   += -fdata-sections -ffunction-sections
 CFLAGS   += -funsigned-char
+CFLAGS   += -Wno-deprecated-declarations
 
 LFLAGS   += -Wl,--gc-sections
 LFLAGS   += -rdynamic
 
+ifeq ($(OS),OS_LINUX)
 XLIBS    += -lstdc++fs
+endif
 
 WARNINGS := -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers
 WARNINGS += -Wno-implicit-fallthrough
-WARNINGS += -Wno-maybe-uninitialized
+WARNINGS += -Wno-uninitialized
 WARNINGS += -Wcast-qual
 
 INCLUDES := -I../../include
@@ -41,10 +40,6 @@ ifeq ($(CFG),Debug)
 DEBUG    := 1
 endif
 
-ifdef ARCH
-CFLAGS   += -march=$(ARCH)
-endif
-
 ifdef LTO
 CFLAGS   += -flto
 LFLAGS   += -flto
@@ -80,6 +75,10 @@ ifeq ($(OSTYPE),FreeBSD)
 OS       := OS_LINUX
 endif
 
+ifeq ($(OSTYPE),NetBSD)
+OS       := OS_LINUX
+endif
+
 ifeq ($(OSTYPE),Darwin)
 CXX      := c++
 OS       := OS_MACOSX
