$NetBSD: patch-gpspipe.c,v 1.1 2013/12/10 12:22:52 jperkin Exp $

cfmakeraw compatability for SunOS.

--- gpspipe.c.orig	2018-09-22 23:24:39.000000000 +0000
+++ gpspipe.c
@@ -97,7 +97,15 @@ static void open_serial(char *device)
     memset(&newtio, 0, sizeof(newtio));
 
     /* make it raw */
+#if defined(__sun)
+    newtio.c_iflag &= ~(IMAXBEL|IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
+    newtio.c_oflag &= ~OPOST;
+    newtio.c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
+    newtio.c_cflag &= ~(CSIZE|PARENB);
+    newtio.c_cflag |= CS8;
+#else
     (void)cfmakeraw(&newtio);
+#endif
     /* set speed */
     (void)cfsetospeed(&newtio, BAUDRATE);
 
