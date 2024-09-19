$NetBSD$

--- os/utils.c.orig	2019-03-05 16:34:21.000000000 +0000
+++ os/utils.c
@@ -734,9 +734,16 @@ ProcessCommandLine(int argc, char *argv[
 #if !defined(WIN32) || !defined(__MINGW32__)
             struct rlimit core_limit;
 
+#if defined(STRICT_XSRC_NETBSD)
+            if (getrlimit(RLIMIT_CORE, &core_limit) != -1) {
+                core_limit.rlim_cur = core_limit.rlim_max;
+                setrlimit(RLIMIT_CORE, &core_limit);
+            }
+#else
             getrlimit(RLIMIT_CORE, &core_limit);
             core_limit.rlim_cur = core_limit.rlim_max;
             setrlimit(RLIMIT_CORE, &core_limit);
+#endif /* STRICT_XSRC_NETBSD */
 #endif
             CoreDump = TRUE;
         }
