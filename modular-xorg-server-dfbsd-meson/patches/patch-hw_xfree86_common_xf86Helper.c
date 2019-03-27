$NetBSD$

--- hw/xfree86/common/xf86Helper.c.orig	2019-03-05 16:34:21.000000000 +0000
+++ hw/xfree86/common/xf86Helper.c
@@ -1281,6 +1281,18 @@ xf86MatchDevice(const char *drivername,
     if (sectlist)
         *sectlist = NULL;
 
+#if defined(STRICT_XSRC_NETBSD)
+    /*
+     * 20111009 jmcneill: This line was removed with the following commit upstream:
+     *  http://cgit.freedesktop.org/xorg/xserver/commit/hw/xfree86/common/xf86Helper.c?id=0ceac6f64f5ad9bc2ac4b19be2dd245ffba78b05
+     *
+     * However, the log message is inaccurate: xf86MatchDevice will get called at
+     * configuration time by drivers who still implement the legacy probing
+     * API.
+     */
+    if (xf86DoConfigure && xf86DoConfigurePass1) return 1;
+#endif
+
     /*
      * This can happen when running Xorg -showopts and a module like ati
      * or vmware tries to load its submodules when xf86ConfigLayout is empty
