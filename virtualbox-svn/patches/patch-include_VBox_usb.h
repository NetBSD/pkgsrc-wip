$NetBSD$

--- include/VBox/usb.h.orig	2016-03-04 19:22:58.000000000 +0000
+++ include/VBox/usb.h
@@ -124,7 +124,7 @@ typedef struct USBDEVICE
     uint8_t         bBus;
     /** The port number. */
     uint8_t         bPort;
-#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     /** Device number. */
     uint8_t         bDevNum;
 #endif
@@ -260,4 +260,3 @@ typedef USBCONFIGDESC *PUSBCONFIGDESC;
 RT_C_DECLS_END
 
 #endif
-
