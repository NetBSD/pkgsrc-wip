$NetBSD: patch-mono_metadata_mono-perfcounters.c,v 1.2 2015/05/22 06:55:40 kefren Exp $

Correct mibs initialization for NetBSD

--- mono/metadata/mono-perfcounters.c.orig	2014-09-04 07:25:40.000000000 +0000
+++ mono/metadata/mono-perfcounters.c
@@ -28,6 +28,9 @@
 #if defined (__NetBSD__) || defined (__APPLE__)
 #include <sys/sysctl.h>
 #endif
+#if defined(__NetBSD__)
+#include <sys/vmmeter.h>
+#endif
 #include "metadata/mono-perfcounters.h"
 #include "metadata/appdomain.h"
 #include "metadata/object-internals.h"
