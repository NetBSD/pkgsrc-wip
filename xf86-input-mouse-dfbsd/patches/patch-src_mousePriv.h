$NetBSD$

Patches from FreeBSD ports / DragonFly dports x11-drivers/xf86-input-mouse 1.9.2.

--- src/mousePriv.h.orig	2012-05-28 00:01:45.000000000 +0000
+++ src/mousePriv.h
@@ -63,8 +63,10 @@ typedef struct {
     int         acc;
     CARD32      pnpLast;
     Bool        disablePnPauto;
+#if !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(__DragonFly__)
     float       fracdx,fracdy;
     float       sensitivity;
+#endif /* !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(__DragonFly__) */
 } mousePrivRec, *mousePrivPtr;
 
 /* mouse proto flags */
