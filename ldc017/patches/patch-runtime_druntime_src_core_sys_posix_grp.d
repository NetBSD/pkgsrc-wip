$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/grp.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/grp.d
@@ -78,6 +78,16 @@ else version( DragonFlyBSD )
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
@@ -134,6 +144,11 @@ else version( DragonFlyBSD )
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
@@ -178,6 +193,12 @@ else version( DragonFlyBSD )
 {
     group* getgrent();
     @trusted void endgrent();
+    @trusted void setgrent();
+}
+else version( NetBSD )
+{
+    group* getgrent();
+    @trusted void endgrent();
     @trusted void setgrent();
 }
 else version( Solaris )
