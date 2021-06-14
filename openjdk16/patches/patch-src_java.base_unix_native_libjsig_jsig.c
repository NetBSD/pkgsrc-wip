$NetBSD: patch-src_java.base_unix_native_libjsig_jsig.c,v 1.1 2019/10/01 12:36:34 tnn Exp $

On NetBSD, __sigaction14 should be used as sigaction.

--- src/java.base/unix/native/libjsig/jsig.c.orig	2021-04-23 22:52:34.000000000 -0400
+++ src/java.base/unix/native/libjsig/jsig.c	2021-06-10 13:37:22.780517606 -0400
@@ -207,7 +207,11 @@
 static int call_os_sigaction(int sig, const struct sigaction  *act,
                              struct sigaction *oact) {
   if (os_sigaction == NULL) {
+#if defined(__NetBSD__)
+    os_sigaction = (sigaction_t)dlsym(RTLD_NEXT, "__sigaction14");
+#else
     os_sigaction = (sigaction_t)dlsym(RTLD_NEXT, "sigaction");
+#endif
     if (os_sigaction == NULL) {
       printf("%s\n", dlerror());
       exit(0);
