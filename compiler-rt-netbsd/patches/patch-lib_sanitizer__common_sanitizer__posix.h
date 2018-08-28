$NetBSD$

--- lib/sanitizer_common/sanitizer_posix.h.orig	2018-08-21 21:25:39.000000000 +0000
+++ lib/sanitizer_common/sanitizer_posix.h
@@ -60,6 +60,9 @@ uptr internal_waitpid(int pid, int *stat
 int internal_fork();
 int internal_forkpty(int *amaster);
 
+int internal_sysctl(const int *name, unsigned int namelen, void *oldp,
+                    uptr *oldlenp, const void *newp, uptr newlen);
+
 // These functions call appropriate pthread_ functions directly, bypassing
 // the interceptor. They are weak and may not be present in some tools.
 SANITIZER_WEAK_ATTRIBUTE
