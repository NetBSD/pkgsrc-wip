$NetBSD: patch-lowl-vcom.c,v 1.1 2014/01/14 02:55:31 nsloss Exp $

Open serial ports non blocking so to support more usb serial drivers.
 
--- lowl-vcom.c.orig	2013-12-25 00:26:34.000000000 +0000
+++ lowl-vcom.c
@@ -991,7 +991,7 @@ int serial_open(const char *devpath, uns
 
 	return _open_osfhandle((intptr_t)hSerial, 0);
 #else
-	int fdDev = open(devpath, O_RDWR | O_CLOEXEC | O_NOCTTY);
+	int fdDev = open(devpath, O_RDWR | O_CLOEXEC | O_NOCTTY | O_NONBLOCK);
 
 	if (unlikely(fdDev == -1))
 	{
