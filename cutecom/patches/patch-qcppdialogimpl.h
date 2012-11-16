$NetBSD: patch-qcppdialogimpl.h,v 1.1 2012/11/16 22:25:07 helgoman Exp $

#Add devices for several systems
--- qcppdialogimpl.h.orig	2009-06-23 20:35:06.000000000 +0000
+++ qcppdialogimpl.h
@@ -105,4 +105,27 @@ class QCPPDialogImpl:public QWidget, pub
 
 };
 
+#if defined(__FreeBSD__)
+
+#define DEVLIST "/dev/cuaU0"<<"/dev/cuaU1"<<"/dev/cuad0"<<"/dev/cuad1";
+#define DEFAULT_DEV "/dev/cuaU0"
+
+#elif defined(__APPLE__)
+
+#define DEVLIST "/dev/cu.usbserial"<<"/dev/cu.KeySerial1";
+#define DEFAULT_DEV "/dev/cu.usbserial"
+
+#elif defined(__Linux__)
+
+#define DEVLIST "/dev/ttyS0"<<"/dev/ttyS1"<<"/dev/ttyS2"<<"/dev/ttyS3";
+#define DEFAULT_DEV "/dev/ttyS0"
+
+#else // Default to NetBSD devices.
+
+#define DEVLIST "/dev/tty00" << "/dev/tty01" << "/dev/ttyU0" << "/dev/ttyU1";
+#define DEFAULT_DEV "/dev/ttyU0"
+
+#endif
+
+
 #endif
