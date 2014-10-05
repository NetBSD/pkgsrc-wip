$NetBSD: patch-lib_freebl_config.mk,v 1.2 2014/10/05 20:12:38 thomasklausner Exp $

No idea, probably bogus (delete?)

--- lib/freebl/config.mk.orig	2014-09-28 13:54:02.000000000 +0000
+++ lib/freebl/config.mk
@@ -90,8 +90,4 @@ EXTRA_SHARED_LIBS += \
 endif
 endif
 
-ifeq ($(OS_ARCH), Darwin)
-EXTRA_SHARED_LIBS += -dylib_file @executable_path/libplc4.dylib:$(DIST)/lib/libplc4.dylib -dylib_file @executable_path/libplds4.dylib:$(DIST)/lib/libplds4.dylib
-endif
-
 endif
