$NetBSD: patch-coreconf_config.mk,v 1.2 2014/10/05 20:12:38 thomasklausner Exp $

Set proper dynamic library runtime search path

--- coreconf/config.mk.orig	2014-09-28 13:54:02.000000000 +0000
+++ coreconf/config.mk
@@ -183,6 +183,7 @@ endif
 DEFINES += -DUSE_UTIL_DIRECTLY
 USE_UTIL_DIRECTLY = 1
 
+EXTRA_SHARED_LIBS +=    -Wl,-R${PREFIX}/lib/${MOZILLA_PKG_NAME}
 # Build with NO_NSPR_10_SUPPORT to avoid using obsolete NSPR features
 DEFINES += -DNO_NSPR_10_SUPPORT
 
