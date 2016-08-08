$NetBSD$

--- mono/metadata/mono-perfcounters.c.orig	2016-08-08 17:23:32.000000000 +0000
+++ mono/metadata/mono-perfcounters.c
@@ -30,9 +30,12 @@
 #include <mach/message.h>
 #include <mach/mach_host.h>
 #include <mach/host_info.h>
+#include <sys/sysctl.h>
 #endif
-#if defined (__NetBSD__) || defined (__APPLE__)
+#if defined (__NetBSD__)
+#include <sys/param.h>
 #include <sys/sysctl.h>
+#include <sys/vmmeter.h>
 #endif
 #include "metadata/mono-perfcounters.h"
 #include "metadata/appdomain.h"
@@ -425,7 +428,7 @@ mono_determine_physical_ram_size (void)
 	int mib[2] = {
 		CTL_HW,
 #ifdef __NetBSD__
-		HW_PHYSMEM
+		HW_PHYSMEM64
 #else
 		HW_MEMSIZE
 #endif
@@ -474,29 +477,22 @@ mono_determine_physical_ram_available_si
 #elif defined (__NetBSD__)
 	struct vmtotal vm_total;
 	guint64 page_size;
-	int mib [2];
+	int mib[2];
 	size_t len;
 
+	mib[0] = CTL_VM;
+	mib[1] = VM_METER;
 
-	mib = {
-		CTL_VM,
-#if defined (VM_METER)
-		VM_METER
-#else
-		VM_TOTAL
-#endif
-	};
 	len = sizeof (vm_total);
 	sysctl (mib, 2, &vm_total, &len, NULL, 0);
 
-	mib = {
-		CTL_HW,
-		HW_PAGESIZE
-	};
+	mib[0] = CTL_HW;
+	mib[1] = HW_PAGESIZE;
+
 	len = sizeof (page_size);
-	sysctl (mib, 2, &page_size, &len, NULL, 0
+	sysctl (mib, 2, &page_size, &len, NULL, 0);
 
-	return ((guint64) value.t_free * page_size) / 1024;
+	return ((guint64) vm_total.t_free * page_size) / 1024;
 #elif defined (__APPLE__)
 	mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
 	mach_port_t host = mach_host_self();
