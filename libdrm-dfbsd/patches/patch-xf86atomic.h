$NetBSD$

This single patch allows glxgears to run properly on
an Intel integrated graphics IvyBridge machine on DragonFly.
libdrm atomic_add_unless() may reverse return value meaning
https://bugs.freedesktop.org/show_bug.cgi?id=100077

--- xf86atomic.h.orig	2015-09-22 04:34:51.000000000 +0000
+++ xf86atomic.h
@@ -111,7 +111,7 @@ static inline int atomic_add_unless(atom
 	c = atomic_read(v);
 	while (c != unless && (old = atomic_cmpxchg(v, c, c + add)) != c)
 		c = old;
-	return c == unless;
+	return c != unless;
 }
 
 #endif
