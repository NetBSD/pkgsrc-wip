$NetBSD$

Adapt to NetBSD.

--- qjsc.c.orig   2019-07-09 19:49:47.000000000 +0200
+++ qjsc.c       2019-07-12 01:58:27.158678240 +0200
@@ -399,7 +399,9 @@
              lib_dir, bn_suffix, lto_suffix);
     *arg++ = libjsname;
     *arg++ = "-lm";
+#if !defined(__NetBSD__)
     *arg++ = "-ldl";
+#endif
     *arg = NULL;
     
     if (verbose) {
