$NetBSD$

--- hw/xfree86/common/xf86Configure.c.orig	2019-03-20 23:09:22.000000000 +0000
+++ hw/xfree86/common/xf86Configure.c
@@ -163,6 +163,12 @@ configureInputSection(void)
     ptr->inp_identifier = xnfstrdup("Keyboard0");
     ptr->inp_driver = xnfstrdup("kbd");
     ptr->list.next = NULL;
+#if defined(WSCONS_SUPPORT) && defined(TRY_DEV_WSKBD)
+    ptr->inp_option_lst = xf86addNewOption(ptr->inp_option_lst,
+        xstrdup("Protocol"), "wskbd");
+    ptr->inp_option_lst = xf86addNewOption(ptr->inp_option_lst,
+        xstrdup("Device"), "/dev/wskbd");
+#endif
 
     /* Crude mechanism to auto-detect mouse (os dependent) */
     {
@@ -821,6 +827,9 @@ DoConfigure(void)
     ErrorF("To test the server, run 'X -config %s'\n\n", filename);
 
  bail:
+#if defined(OPENBSD_MORE_CALLS)
+    CloseWellKnownConnections();
+#endif
     OsCleanup(TRUE);
     ddxGiveUp(EXIT_ERR_CONFIGURE);
     fflush(stderr);
