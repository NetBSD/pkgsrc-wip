$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/grp.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/grp.d
@@ -68,6 +68,16 @@ else version( FreeBSD )
         char**  gr_mem;
     }
 }
+else version( NetBSD )
+{
+    struct group
+    {
+        char*   gr_name;
+        char*   gr_passwd;
+        gid_t   gr_gid;
+        char**  gr_mem;
+    }
+}
 else version( Solaris )
 {
     struct group
@@ -119,6 +129,11 @@ else version( FreeBSD )
     int getgrnam_r(in char*, group*, char*, size_t, group**);
     int getgrgid_r(gid_t, group*, char*, size_t, group**);
 }
+else version( NetBSD )
+{
+    int getgrnam_r(in char*, group*, char*, size_t, group**);
+    int getgrgid_r(gid_t, group*, char*, size_t, group**);
+}
 else version( Solaris )
 {
     int getgrnam_r(in char*, group*, char*, int, group**);
@@ -159,6 +174,12 @@ else version( FreeBSD )
     @trusted void endgrent();
     @trusted void setgrent();
 }
+else version( NetBSD )
+{
+    group* getgrent();
+    @trusted void endgrent();
+    @trusted void setgrent();
+}
 else version( Solaris )
 {
     group* getgrent();
