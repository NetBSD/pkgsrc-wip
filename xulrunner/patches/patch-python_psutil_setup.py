$NetBSD: patch-python_psutil_setup.py,v 1.1 2013/05/12 01:49:16 makoto Exp $

Add NetBSD case, without this you may get following
Installing pip...............done.
platform netbsd6 is not supported

Error processing command. Ignoring because optional. (optional:setup.py:python/psutil:build_ext
--- python/psutil/setup.py.orig	2013-05-07 18:01:43.000000000 +0900
+++ python/psutil/setup.py	2013-05-12 07:48:13.000000000 +0900
@@ -86,6 +86,15 @@ elif sys.platform.startswith("freebsd"):
                             libraries=["devstat"],
                             ),
                   posix_extension]
+# NetBSD
+elif sys.platform.startswith("netbsd"):
+    extensions = [Extension('_psutil_bsd',
+                            sources = ['psutil/_psutil_bsd.c',
+                                       'psutil/_psutil_common.c',
+                                       'psutil/arch/bsd/process_info.c'],
+                            libraries=["devstat"],
+                            ),
+                  posix_extension]
 # Linux
 elif sys.platform.startswith("linux"):
     extensions = [Extension('_psutil_linux',
