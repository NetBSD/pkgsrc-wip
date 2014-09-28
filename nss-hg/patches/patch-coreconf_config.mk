$NetBSD: patch-coreconf_config.mk,v 1.1 2014/09/28 14:20:09 thomasklausner Exp $

--- coreconf/config.mk.orig	2014-09-28 13:54:02.000000000 +0000
+++ coreconf/config.mk
@@ -31,7 +31,7 @@ endif
 #######################################################################
 
 TARGET_OSES = FreeBSD BSD_OS NetBSD OpenUNIX OS2 QNX Darwin BeOS OpenBSD \
-              AIX RISCOS WINNT WIN95 Linux Android
+              AIX RISCOS WINNT WIN95 Linux Android DragonFly
 
 ifeq (,$(filter-out $(TARGET_OSES),$(OS_TARGET)))
 include $(CORE_DEPTH)/coreconf/$(OS_TARGET).mk
@@ -183,6 +183,7 @@ endif
 DEFINES += -DUSE_UTIL_DIRECTLY
 USE_UTIL_DIRECTLY = 1
 
+EXTRA_SHARED_LIBS +=    -Wl,-R${PREFIX}/lib/${MOZILLA_PKG_NAME}
 # Build with NO_NSPR_10_SUPPORT to avoid using obsolete NSPR features
 DEFINES += -DNO_NSPR_10_SUPPORT
 
