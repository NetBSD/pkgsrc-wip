$NetBSD$

--- include/valgrind.h.orig	2018-09-18 06:34:53.000000000 +0000
+++ include/valgrind.h
@@ -110,6 +110,7 @@
 */
 #undef PLAT_x86_darwin
 #undef PLAT_amd64_darwin
+#undef PLAT_amd64_netbsd
 #undef PLAT_x86_win32
 #undef PLAT_amd64_win64
 #undef PLAT_x86_linux
@@ -130,6 +131,8 @@
 #  define PLAT_x86_darwin 1
 #elif defined(__APPLE__) && defined(__x86_64__)
 #  define PLAT_amd64_darwin 1
+#elif defined(__NetBSD__) && defined(__amd64__)
+#  define PLAT_amd64_netbsd 1
 #elif (defined(__MINGW32__) && !defined(__MINGW64__)) \
       || defined(__CYGWIN32__) \
       || (defined(_WIN32) && defined(_M_IX86))
@@ -394,7 +397,8 @@ valgrind_do_client_request_expr(uintptr_
 
 #if defined(PLAT_amd64_linux)  ||  defined(PLAT_amd64_darwin) \
     ||  defined(PLAT_amd64_solaris) \
-    ||  (defined(PLAT_amd64_win64) && defined(__GNUC__))
+    ||  (defined(PLAT_amd64_win64) && defined(__GNUC__)) \
+    ||  defined(PLAT_amd64_netbsd)
 
 typedef
    struct { 
@@ -454,7 +458,7 @@ typedef
                     );                                           \
  } while (0)
 
-#endif /* PLAT_amd64_linux || PLAT_amd64_darwin || PLAT_amd64_solaris */
+#endif /* PLAT_amd64_linux || PLAT_amd64_darwin || PLAT_amd64_solaris || PLAT_amd64_netbsd */
 
 /* ------------------------- amd64-Win64 ------------------------- */
 
@@ -1577,7 +1581,7 @@ typedef
 /* ---------------- amd64-{linux,darwin,solaris} --------------- */
 
 #if defined(PLAT_amd64_linux)  ||  defined(PLAT_amd64_darwin) \
-    ||  defined(PLAT_amd64_solaris)
+    ||  defined(PLAT_amd64_solaris) || defined(PLAT_amd64_netbsd)
 
 /* ARGREGS: rdi rsi rdx rcx r8 r9 (the rest on stack in R-to-L order) */
 
