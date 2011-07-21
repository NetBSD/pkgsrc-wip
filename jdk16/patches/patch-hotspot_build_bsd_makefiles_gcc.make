$NetBSD: patch-hotspot_build_bsd_makefiles_gcc.make,v 1.1 2011/07/21 16:05:11 ftigeot Exp $

--- hotspot/build/bsd/makefiles/gcc.make.orig	2011-07-21 15:12:06 +0000
+++ hotspot/build/bsd/makefiles/gcc.make
@@ -90,7 +90,7 @@ else
 endif
 
 # Compiler warnings are treated as errors
-WARNINGS_ARE_ERRORS = -Werror
+WARNINGS_ARE_ERRORS =
 # Except for a few acceptable ones
 ACCEPTABLE_WARNINGS = -Wpointer-arith -Wconversion -Wsign-compare
 CFLAGS_WARN/DEFAULT = $(WARNINGS_ARE_ERRORS) $(ACCEPTABLE_WARNINGS)
@@ -136,7 +136,7 @@ endif
 #
 # BSD Shared Library
 #
-ifneq ($(findstring BSD,$(UNAME.s)),)
+ifeq ($(TRUE_PLATFORM), $(filter $(TRUE_PLATFORM), DragonFly, FreeBSD, NetBSD, OpenBSD))
 
 # Enable linker optimization
 LFLAGS += -Xlinker -O1
