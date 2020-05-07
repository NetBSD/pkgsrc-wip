$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/stdc/string.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/stdc/string.d
@@ -80,6 +80,10 @@ else version (FreeBSD)
 {
     int strerror_r(int errnum, char* buf, size_t buflen);
 }
+else version (NetBSD)
+{
+    int strerror_r(int errnum, char* buf, size_t buflen);
+}
 else version (Solaris)
 {
     int strerror_r(int errnum, char* buf, size_t buflen);
