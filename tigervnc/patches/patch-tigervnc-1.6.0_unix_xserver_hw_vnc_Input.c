$NetBSD$

--- tigervnc-1.6.0/unix/xserver/hw/vnc/Input.c.orig	2015-12-24 20:18:02.000000000 +0000
+++ tigervnc-1.6.0/unix/xserver/hw/vnc/Input.c
@@ -300,6 +300,8 @@ static inline void pressKey(DeviceIntPtr
 #if XORG < 111
 	n = GetKeyboardEvents(eventq, dev, action, kc);
 	enqueueEvents(dev, n);
+#elif XORG > 117
+	QueueKeyboardEvents(dev, action, kc);
 #else
 	QueueKeyboardEvents(dev, action, kc, NULL);
 #endif
