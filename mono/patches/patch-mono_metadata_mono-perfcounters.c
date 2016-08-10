$NetBSD: patch-mono_metadata_mono-perfcounters.c,v 1.2 2015/05/22 06:55:40 kefren Exp $

Correct mibs initialization for NetBSD

--- mono/metadata/mono-perfcounters.c.orig	2016-08-03 10:33:31.000000000 +0000
+++ mono/metadata/mono-perfcounters.c
@@ -34,6 +34,9 @@
 #if defined (__NetBSD__) || defined (__APPLE__)
 #include <sys/sysctl.h>
 #endif
+#if defined(__NetBSD__)
+#include <sys/vmmeter.h>
+#endif
 #include "metadata/mono-perfcounters.h"
 #include "metadata/appdomain.h"
 #include "metadata/object-internals.h"
@@ -474,11 +477,7 @@ mono_determine_physical_ram_available_si
 #elif defined (__NetBSD__)
 	struct vmtotal vm_total;
 	guint64 page_size;
-	int mib [2];
-	size_t len;
-
-
-	mib = {
+	int mib [2] = {
 		CTL_VM,
 #if defined (VM_METER)
 		VM_METER
