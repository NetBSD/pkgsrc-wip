$NetBSD: patch-build_gmake.unix_Premake4.make,v 1.1 2014/01/04 16:23:02 nros Exp $

* use DL_LIBS from dlopen.buildlink3.mk instead of hardcoded -ldl

--- build/gmake.unix/Premake4.make.orig	2014-01-04 15:05:18.000000000 +0000
+++ build/gmake.unix/Premake4.make
@@ -29,7 +29,7 @@ ifeq ($(config),release)
   CFLAGS    += $(CPPFLAGS) $(ARCH) -Wall -Os
   CXXFLAGS  += $(CFLAGS) 
   LDFLAGS   += -s -rdynamic
-  LIBS      += -lm -ldl
+  LIBS      += -lm $(DL_LIBS)
   RESFLAGS  += $(DEFINES) $(INCLUDES) 
   LDDEPS    += 
   LINKCMD    = $(CC) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(ARCH) $(LIBS)
@@ -51,7 +51,7 @@ ifeq ($(config),debug)
   CFLAGS    += $(CPPFLAGS) $(ARCH) -Wall -g
   CXXFLAGS  += $(CFLAGS) 
   LDFLAGS   += -rdynamic
-  LIBS      += -lm -ldl
+  LIBS      += -lm $(DL_LIBS)
   RESFLAGS  += $(DEFINES) $(INCLUDES) 
   LDDEPS    += 
   LINKCMD    = $(CC) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(ARCH) $(LIBS)
