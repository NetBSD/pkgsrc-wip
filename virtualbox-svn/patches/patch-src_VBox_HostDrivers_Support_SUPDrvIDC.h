$NetBSD$

--- src/VBox/HostDrivers/Support/SUPDrvIDC.h.orig	2016-08-05 17:22:49.000000000 +0000
+++ src/VBox/HostDrivers/Support/SUPDrvIDC.h
@@ -233,6 +233,9 @@ extern DECLIMPORT(int) VBOXCALL SUPDrvDa
 #elif defined(RT_OS_FREEBSD)
 extern int VBOXCALL SUPDrvFreeBSDIDC(uint32_t iReq, PSUPDRVIDCREQHDR pReq);
 
+#elif defined(RT_OS_NETBSD)
+extern int VBOXCALL SUPDrvNetBSDIDC(uint32_t iReq, PSUPDRVIDCREQHDR pReq);
+
 #elif defined(RT_OS_LINUX)
 extern int VBOXCALL SUPDrvLinuxIDC(uint32_t iReq, PSUPDRVIDCREQHDR pReq);
 
@@ -272,4 +275,3 @@ typedef DECLCALLBACK(int) FNSUPDRVIDCENT
 #pragma pack()                          /* paranoia */
 
 #endif
-
