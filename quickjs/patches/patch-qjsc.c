$NetBSD$

Adapt to NetBSD.

--- qjsc.c.orig	2019-07-09 17:49:47.000000000 +0000
+++ qjsc.c
@@ -399,7 +399,9 @@ static int output_executable(const char 
              lib_dir, bn_suffix, lto_suffix);
     *arg++ = libjsname;
     *arg++ = "-lm";
+#if !defined(__NetBSD__)
     *arg++ = "-ldl";
+#endif
     *arg = NULL;
     
     if (verbose) {
