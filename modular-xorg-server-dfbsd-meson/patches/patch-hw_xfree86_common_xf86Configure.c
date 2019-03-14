$NetBSD$

--- hw/xfree86/common/xf86Configure.c.orig	2019-03-05 16:34:21.000000000 +0000
+++ hw/xfree86/common/xf86Configure.c
@@ -821,6 +821,9 @@ DoConfigure(void)
     ErrorF("To test the server, run 'X -config %s'\n\n", filename);
 
  bail:
+#if defined(OPENBSD_MORE_CALLS)
+    CloseWellKnownConnections();
+#endif
     OsCleanup(TRUE);
     ddxGiveUp(EXIT_ERR_CONFIGURE);
     fflush(stderr);
