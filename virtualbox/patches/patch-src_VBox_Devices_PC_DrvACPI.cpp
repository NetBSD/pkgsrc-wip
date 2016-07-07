$NetBSD$

--- src/VBox/Devices/PC/DrvACPI.cpp.orig	2016-03-04 19:28:01.000000000 +0000
+++ src/VBox/Devices/PC/DrvACPI.cpp
@@ -45,7 +45,7 @@
 # include <IOKit/ps/IOPSKeys.h>
 #endif
 
-#ifdef RT_OS_FREEBSD
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <sys/ioctl.h>
 # include <dev/acpica/acpiio.h>
 # include <sys/types.h>
@@ -221,6 +221,10 @@ static DECLCALLBACK(int) drvACPIQueryPow
         AssertMsg(errno == ENOENT, ("rc=%d (%s)\n", rc, strerror(errno)));
         *pPowerSource = PDM_ACPI_POWER_SOURCE_OUTLET;
     }
+
+#elif defined(RT_OS_NETBSD)
+    // TODO
+    *pPowerSource = PDM_ACPI_POWER_SOURCE_OUTLET;
 #else /* !RT_OS_FREEBSD either - what could this be? */
     *pPowerSource = PDM_ACPI_POWER_SOURCE_OUTLET;
 
