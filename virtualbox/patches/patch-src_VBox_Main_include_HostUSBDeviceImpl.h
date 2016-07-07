$NetBSD$

--- src/VBox/Main/include/HostUSBDeviceImpl.h.orig	2016-03-04 19:29:37.000000000 +0000
+++ src/VBox/Main/include/HostUSBDeviceImpl.h
@@ -323,6 +323,9 @@ private:
 #ifdef RT_OS_FreeBSD
     friend class USBProxyServiceFreeBSD;
 #endif
+#ifdef RT_OS_NETBSD
+    friend class USBProxyServiceNetBSD;
+#endif
 };
 
 #endif // ____H_HOSTUSBDEVICEIMPL
