$NetBSD$

--- src/VBox/Main/include/ConsoleImpl.h.orig	2016-08-12 18:06:16.000000000 +0000
+++ src/VBox/Main/include/ConsoleImpl.h
@@ -581,7 +581,7 @@ private:
     HRESULT i_powerDown(IProgress *aProgress = NULL);
 
 /* Note: FreeBSD needs this whether netflt is used or not. */
-#if ((defined(RT_OS_LINUX) && !defined(VBOX_WITH_NETFLT)) || defined(RT_OS_FREEBSD))
+#if (defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)) && !defined(VBOX_WITH_NETFLT)
     HRESULT i_attachToTapInterface(INetworkAdapter *networkAdapter);
     HRESULT i_detachFromTapInterface(INetworkAdapter *networkAdapter);
 #endif
@@ -948,7 +948,7 @@ private:
     } *mpIfSecKeyHlp;
 
 /* Note: FreeBSD needs this whether netflt is used or not. */
-#if ((defined(RT_OS_LINUX) && !defined(VBOX_WITH_NETFLT)) || defined(RT_OS_FREEBSD))
+#if ((defined(RT_OS_LINUX) && !defined(VBOX_WITH_NETFLT)) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD))
     Utf8Str      maTAPDeviceName[8];
     RTFILE       maTapFD[8];
 #endif
