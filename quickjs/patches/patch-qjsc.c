$NetBSD$

Adapt to NetBSD.

--- qjsc.c.orig	2019-08-10 10:58:42.000000000 +0000
+++ qjsc.c
@@ -450,7 +450,9 @@ static int output_executable(const char 
              lib_dir, bn_suffix, lto_suffix);
     *arg++ = libjsname;
     *arg++ = "-lm";
+#if !defined(__NetBSD__)
     *arg++ = "-ldl";
+#endif
     *arg++ = "-lpthread";
     *arg = NULL;
     
