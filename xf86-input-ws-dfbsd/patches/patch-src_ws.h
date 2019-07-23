$NetBSD$

OpenBSD xenocara option:

Dec 31 23:31:41 2017 UTC
If read() returns EIO, then the wsmouse device has gone away and our fd
to it is useless, so detach the xserver driver and close it.
Modeled on similar code in xf86-input-{keyboard,mouse}

--- src/ws.h.orig	2015-08-29 08:48:29.000000000 +0000
+++ src/ws.h
@@ -87,6 +87,10 @@ typedef struct WSDevice {
 		Time timeout;
 	} emulateWheel;
 
+#if defined(READ_EIO_XENOCARA_OPENBSD)
+	OsTimerPtr      remove_timer;   /* Callback for removal on EIO */
+#endif
+
 	struct wscons_event	events[NWSEVENTS];
 	size_t			events_count;
 	size_t			events_pos;
@@ -95,8 +99,19 @@ typedef struct WSDevice {
 /* Middle mouse button emulation */
 extern int wsmbEmuTimer(InputInfoPtr);
 extern BOOL wsmbEmuFilterEvent(InputInfoPtr, int, BOOL);
+#if defined(STRICT_XSRC_NETBSD)
+/* XXX compat-api.h */
+#if ABI_VIDEODRV_VERSION < SET_ABI_VERSION(23, 0)
+extern void wsmbEmuWakeupHandler(pointer, int, pointer);
+extern void wsmbEmuBlockHandler(pointer, struct timeval **, pointer);
+#else
+extern void wsmbEmuWakeupHandler(pointer, int);
+extern void wsmbEmuBlockHandler(pointer, pointer);
+#endif
+#else /* !STRICT_XSRC_NETBSD */
 extern void wsmbEmuWakeupHandler(pointer, int, pointer);
 extern void wsmbEmuBlockHandler(pointer, struct timeval **, pointer);
+#endif /* STRICT_XSRC_NETBSD */
 extern void wsmbEmuPreInit(InputInfoPtr);
 extern void wsmbEmuOn(InputInfoPtr);
 extern void wsmbEmuFinalize(InputInfoPtr);
