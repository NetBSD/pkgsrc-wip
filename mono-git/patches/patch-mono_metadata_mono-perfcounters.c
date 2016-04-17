$NetBSD$

--- mono/metadata/mono-perfcounters.c.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/metadata/mono-perfcounters.c
@@ -34,6 +34,9 @@
 #if defined (__NetBSD__) || defined (__APPLE__)
 #include <sys/sysctl.h>
 #endif
+#if defined (__NetBSD__)
+#include <sys/vmmeter.h>
+#endif
 #include "metadata/mono-perfcounters.h"
 #include "metadata/appdomain.h"
 #include "metadata/object-internals.h"
@@ -474,11 +477,10 @@ mono_determine_physical_ram_available_si
 #elif defined (__NetBSD__)
 	struct vmtotal vm_total;
 	guint64 page_size;
-	int mib [2];
 	size_t len;
 
 
-	mib = {
+	int mib[2] = {
 		CTL_VM,
 #if defined (VM_METER)
 		VM_METER
@@ -489,14 +491,12 @@ mono_determine_physical_ram_available_si
 	len = sizeof (vm_total);
 	sysctl (mib, 2, &vm_total, &len, NULL, 0);
 
-	mib = {
-		CTL_HW,
-		HW_PAGESIZE
-	};
+	mib[0] = CTL_HW;
+	mib[1] = HW_PAGESIZE;
 	len = sizeof (page_size);
-	sysctl (mib, 2, &page_size, &len, NULL, 0
+	sysctl (mib, 2, &page_size, &len, NULL, 0);
 
-	return ((guint64) value.t_free * page_size) / 1024;
+	return 0; // ((guint64) value.t_free * page_size) / 1024;
 #elif defined (__APPLE__)
 	mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
 	mach_port_t host = mach_host_self();
