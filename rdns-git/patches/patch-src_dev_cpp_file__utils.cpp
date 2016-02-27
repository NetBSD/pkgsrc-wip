$NetBSD$

--- src/dev/cpp/file_utils.cpp.orig	2016-02-27 19:03:52.000000000 +0000
+++ src/dev/cpp/file_utils.cpp
@@ -76,7 +76,11 @@
 
 # if defined(__APPLE__)
 # include <libproc.h>
-#endif
+# endif
+
+# if defined(__NetBSD__)
+# include <sys/sysctl.h>
+# endif
 
 # define getcwd_ getcwd
 # define rmdir_ rmdir
@@ -1102,6 +1106,27 @@ out_error:
                 }
 
                 path = tls_path_buffer;
+# elif defined(__NetBSD__)
+                if (pid == -1)
+                {
+                    pid = ::getpid();
+                }
+
+#ifdef KERN_PROC_PATHNAME
+                static const int name[] = {
+                    CTL_KERN, KERN_PROC_ARGS, pid, KERN_PROC_PATHNAME,
+                };
+
+                size_t len = TLS_PATH_BUFFER_SIZE;
+                if (sysctl(name, __arraycount(name), tls_path_buffer, &len, NULL, 0) == -1)
+                {
+                    return ERR_PATH_NOT_FOUND;
+                }
+
+                path = tls_path_buffer;
+#else
+# error not implemented yet
+#endif
 # else
 # error not implemented yet
 # endif
