$NetBSD$

--- src/main.c.orig	2017-01-23 19:49:04.000000000 +0000
+++ src/main.c
@@ -43,10 +43,12 @@ struct netdata_static_thread static_thre
     {"freebsd",            "plugins",   "freebsd",    1, NULL, NULL, freebsd_main},
 #elif defined(__APPLE__)
     {"macos",              "plugins",   "macos",      1, NULL, NULL, macos_main},
+#elif defined(__NetBSD__)
+    {"netbsd",             "plugins",   "netbsd",    1, NULL, NULL, netbsd_main},
 #else
     {"proc",               "plugins",   "proc",       1, NULL, NULL, proc_main},
     {"diskspace",          "plugins",   "diskspace",  1, NULL, NULL, proc_diskspace_main},
-#endif /* __FreeBSD__, __APPLE__*/
+#endif /* __FreeBSD__, __APPLE__, __NetBSD__*/
     {"cgroups",            "plugins",   "cgroups",    1, NULL, NULL, cgroups_main},
     {"check",              "plugins",   "checks",     0, NULL, NULL, checks_main},
     {"backends",            NULL,       NULL,         1, NULL, NULL, backends_main},
@@ -567,9 +569,9 @@ int main(int argc, char **argv)
             if(setrlimit(RLIMIT_CORE, &rl) != 0)
                 error("Cannot request unlimited core dumps for debugging... Proceeding anyway...");
 
-#if !(defined(__FreeBSD__) || defined(__APPLE__))
+#if !(defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__))
             prctl(PR_SET_DUMPABLE, 1, 0, 0, 0);
-#endif /* __FreeBSD__ || __APPLE__*/
+#endif /* __FreeBSD__ || __APPLE__ || __NetBSD__*/
         }
 
         // --------------------------------------------------------------------
@@ -744,9 +746,9 @@ int main(int argc, char **argv)
         struct rlimit rl = { RLIM_INFINITY, RLIM_INFINITY };
         if(setrlimit(RLIMIT_CORE, &rl) != 0)
             error("Cannot request unlimited core dumps for debugging... Proceeding anyway...");
-#if !(defined(__FreeBSD__) || defined(__APPLE__))
+#if !(defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__))
         prctl(PR_SET_DUMPABLE, 1, 0, 0, 0);
-#endif /* __FreeBSD__ || __APPLE__*/
+#endif /* __FreeBSD__ || __APPLE__ || __NetBSD__ */
     }
 #endif /* NETDATA_INTERNAL_CHECKS */
 
