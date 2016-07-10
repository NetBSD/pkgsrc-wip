$NetBSD$

--- src/VBox/Devices/PC/DrvACPI.cpp.orig	2016-07-10 20:05:45.000000000 +0000
+++ src/VBox/Devices/PC/DrvACPI.cpp
@@ -222,6 +222,10 @@ static DECLCALLBACK(int) drvACPIQueryPow
         AssertMsg(errno == ENOENT, ("rc=%d (%s)\n", rc, strerror(errno)));
         *pPowerSource = PDM_ACPI_POWER_SOURCE_OUTLET;
     }
+
+#elif defined(RT_OS_NETBSD)
+    // TODO
+    *pPowerSource = PDM_ACPI_POWER_SOURCE_OUTLET;
 #else /* !RT_OS_FREEBSD either - what could this be? */
     *pPowerSource = PDM_ACPI_POWER_SOURCE_OUTLET;
 
