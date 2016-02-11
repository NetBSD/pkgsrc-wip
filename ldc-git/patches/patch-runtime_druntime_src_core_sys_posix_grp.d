$NetBSD$

--- runtime/druntime/src/core/sys/posix/grp.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/grp.d
@@ -68,6 +68,19 @@ else version( FreeBSD )
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
+
+    group* getgrnam(in char*);
+    group* getgrgid(gid_t);
+}
 else version( Solaris )
 {
     struct group
@@ -119,6 +132,11 @@ else version( FreeBSD )
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
@@ -159,6 +177,12 @@ else version( FreeBSD )
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
