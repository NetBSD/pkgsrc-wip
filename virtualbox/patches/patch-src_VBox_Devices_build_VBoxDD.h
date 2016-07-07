$NetBSD$

--- src/VBox/Devices/build/VBoxDD.h.orig	2016-03-04 19:28:26.000000000 +0000
+++ src/VBox/Devices/build/VBoxDD.h
@@ -97,7 +97,7 @@ extern const PDMDRVREG g_DrvMediaISO;
 extern const PDMDRVREG g_DrvRawImage;
 extern const PDMDRVREG g_DrvISCSI;
 extern const PDMDRVREG g_DrvISCSITransportTcp;
-#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 extern const PDMDRVREG g_DrvHostInterface;
 #endif
 #ifdef VBOX_WITH_UDPTUNNEL
@@ -130,7 +130,7 @@ extern const PDMDRVREG g_DrvHostCoreAudi
 extern const PDMDRVREG g_DrvHostOSSAudio;
 extern const PDMDRVREG g_DrvHostSolAudio;
 #endif
-#if defined(RT_OS_FREEBSD)
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 extern const PDMDRVREG g_DrvHostOSSAudio;
 #endif
 extern const PDMDRVREG g_DrvACPI;
@@ -182,4 +182,3 @@ int acpiCleanupSsdt(PPDMDEVINS pDevIns, 
 RT_C_DECLS_END
 
 #endif
-
