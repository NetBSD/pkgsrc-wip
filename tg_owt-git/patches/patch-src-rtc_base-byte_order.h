$NetBSD$

Add NetBSD to the BSD endian.h include path (same as FreeBSD/OpenBSD).

--- src/rtc_base/byte_order.h.orig
+++ src/rtc_base/byte_order.h
@@ -92,7 +92,7 @@
 
 #elif defined(WEBRTC_LINUX)
 #include <endian.h>
-#elif defined(WEBRTC_FREEBSD) || defined(WEBRTC_OPENBSD)
+#elif defined(WEBRTC_FREEBSD) || defined(WEBRTC_OPENBSD) || defined(WEBRTC_NETBSD)
 #include <sys/endian.h>
 #else
 #error "Missing byte order functions for this arch."
