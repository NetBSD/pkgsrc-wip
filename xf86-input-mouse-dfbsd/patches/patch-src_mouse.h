$NetBSD$

Patches from FreeBSD ports / DragonFly dports x11-drivers/xf86-input-mouse 1.9.2.

--- src/mouse.h.orig	2012-10-08 01:40:07.000000000 +0000
+++ src/mouse.h
@@ -220,10 +220,17 @@ typedef struct _MouseDevRec {
     Bool                emulate3ButtonsSoft;
     int                 emulate3Timeout;/* Timeout for 3 button emulation */
     Bool                chordMiddle;
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    Bool                disableXY;
+#endif /* defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) */
     Bool                flipXY;
     int                 invX;
     int                 invY;
     int                 resolution;
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    Bool                hasW;
+    Bool                hasZ;
+#endif /* defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) */
     int                 negativeZ;      /* button mask */
     int                 positiveZ;      /* button mask */
     int                 negativeW;      /* button mask */
@@ -262,6 +269,10 @@ typedef struct _MouseDevRec {
     int                 doubleClickOldSourceState;
     int                 lastMappedButtons;
     int                 buttonMap[MSE_MAXBUTTONS];
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    float               fracdx,fracdy;
+    float               sensitivity;
+#endif /* defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) */
 } MouseDevRec, *MouseDevPtr;
 
 #endif /* _XF86OSMOUSE_H_ */
