$NetBSD$

--- src/3rdparty/chromium/base/third_party/libevent/event-config.h.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/third_party/libevent/event-config.h
@@ -15,6 +15,8 @@
 #include "base/third_party/libevent/linux/event-config.h"
 #elif defined(__FreeBSD__)
 #include "base/third_party/libevent/freebsd/event-config.h"
+#elif defined(__NetBSD__)
+#include "base/third_party/libevent/netbsd/event-config.h"
 #elif defined(__sun)
 #include "base/third_party/libevent/solaris/event-config.h"
 #elif defined(_AIX)
