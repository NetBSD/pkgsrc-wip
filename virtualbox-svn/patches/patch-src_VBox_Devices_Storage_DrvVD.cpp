$NetBSD$

--- src/VBox/Devices/Storage/DrvVD.cpp.orig	2016-08-05 16:42:58.000000000 +0000
+++ src/VBox/Devices/Storage/DrvVD.cpp
@@ -65,6 +65,7 @@ RT_C_DECLS_END
 extern bool DevINIPConfigured(void);
 #endif /* VBOX_WITH_INIP */
 
+#include <sys/time.h>
 
 /** @def VBOX_PERIODIC_FLUSH
  * Enable support for periodically flushing the VDI to disk. This may prove
@@ -1099,10 +1100,10 @@ static DECLCALLBACK(int) drvvdINIPSelect
         rc = lwip_select(pSocketInt->hSock + 1, &fdsetR, NULL, &fdsetE, NULL);
     else
     {
-        struct timeval timeout;
-        timeout.tv_sec = cMillies / 1000;
-        timeout.tv_usec = (cMillies % 1000) * 1000;
-        rc = lwip_select(pSocketInt->hSock + 1, &fdsetR, NULL, &fdsetE, &timeout);
+        struct timeval vb_timeout;
+        vb_timeout.tv_sec = cMillies / 1000;
+        vb_timeout.tv_usec = (cMillies % 1000) * 1000;
+        rc = lwip_select(pSocketInt->hSock + 1, &fdsetR, NULL, &fdsetE, &vb_timeout);
     }
     if (rc > 0)
         return VINF_SUCCESS;
@@ -5214,4 +5215,3 @@ const PDMDRVREG g_DrvVD =
     /* u32EndVersion */
     PDM_DRVREG_VERSION
 };
-
