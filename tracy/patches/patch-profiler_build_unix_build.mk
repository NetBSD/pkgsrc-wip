$NetBSD$

Prevents pkgsrc glfw's headers from being picked up during the build.

--- profiler/build/unix/build.mk.orig	2019-03-26 14:55:22.000000000 +0000
+++ profiler/build/unix/build.mk
@@ -1,7 +1,7 @@
 CFLAGS += 
 CXXFLAGS := $(CFLAGS) -std=c++17
 DEFINES += -DTRACY_FILESELECTOR -DTRACY_EXTENDED_FONT -DTRACY_ROOT_WINDOW
-INCLUDES := $(shell pkg-config --cflags glfw3 freetype2) -I../../../imgui -I../../libs/gl3w
+INCLUDES := -I../../../imgui -I../../libs/gl3w $(shell pkg-config --cflags glfw3 freetype2)
 LIBS := $(shell pkg-config --libs glfw3 freetype2) -lpthread -ldl
 PROJECT := Tracy
 IMAGE := $(PROJECT)-$(BUILD)
