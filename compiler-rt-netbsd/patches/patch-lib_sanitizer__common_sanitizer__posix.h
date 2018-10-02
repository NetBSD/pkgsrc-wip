$NetBSD$

--- lib/sanitizer_common/sanitizer_posix.h.orig	2018-08-31 08:13:43.000000000 +0000
+++ lib/sanitizer_common/sanitizer_posix.h
@@ -62,6 +62,8 @@ int internal_forkpty(int *amaster);
 
 int internal_sysctl(const int *name, unsigned int namelen, void *oldp,
                     uptr *oldlenp, const void *newp, uptr newlen);
+int internal_sysctlbyname(const char *sname, void *oldp, uptr *oldlenp,
+                          const void *newp, uptr newlen);
 
 // These functions call appropriate pthread_ functions directly, bypassing
 // the interceptor. They are weak and may not be present in some tools.
