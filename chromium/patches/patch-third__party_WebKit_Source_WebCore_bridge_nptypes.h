$NetBSD: patch-third__party_WebKit_Source_WebCore_bridge_nptypes.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebCore/bridge/nptypes.h.orig	2011-04-13 08:12:44.000000000 +0000
+++ third_party/WebKit/Source/WebCore/bridge/nptypes.h
@@ -60,7 +60,7 @@
   #ifndef __cplusplus
     typedef int bool;
   #endif
-#elif defined(bsdi) || defined(FREEBSD) || defined(OPENBSD)
+#elif defined(bsdi) || defined(BSD)
   /*
    * BSD/OS, FreeBSD, and OpenBSD ship sys/types.h that define int32_t and 
    * u_int32_t.
@@ -167,7 +167,7 @@
   #ifndef __cplusplus
     typedef int bool;
   #endif
-#elif defined(bsdi) || defined(FREEBSD) || defined(OPENBSD)
+#elif defined(bsdi) || defined(BSD)
   /*
    * BSD/OS, FreeBSD, and OpenBSD ship sys/types.h that define int32_t and 
    * u_int32_t.
