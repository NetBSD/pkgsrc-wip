$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/pwd.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/pwd.d
@@ -102,6 +102,22 @@ else version( DragonFlyBSD )
         int pw_fields;          /* internal: fields filled in */
     }
 }
+else version( NetBSD )
+{
+    struct passwd
+    {
+        char*   pw_name;        /* user name */
+        char*   pw_passwd;      /* encrypted password */
+        uid_t   pw_uid;         /* user uid */
+        gid_t   pw_gid;         /* user gid */
+        time_t  pw_change;      /* password change time */
+        char*   pw_class;       /* user access class */
+        char*   pw_gecos;       /* Honeywell login info */
+        char*   pw_dir;     /* home directory */
+        char*   pw_shell;       /* default shell */
+        time_t  pw_expire;      /* account expiration */
+    }
+}
 else version (Solaris)
 {
     struct passwd
@@ -165,6 +181,13 @@ else version( DragonFlyBSD )
     int getpwnam_r(in char*, passwd*, char*, size_t, passwd**);
     int getpwuid_r(uid_t, passwd*, char*, size_t, passwd**);
 }
+else version( NetBSD )
+{
+    int __getpwnam_r50(in char*, passwd*, char*, size_t, passwd**);
+    alias __getpwnam_r50 getpwnam_r;
+    int __getpwuid_r50(uid_t, passwd*, char*, size_t, passwd**);
+    alias __getpwuid_r50 getpwuid_r;
+}
 else version (Solaris)
 {
     int getpwnam_r(in char*, passwd*, char*, size_t, passwd**);
@@ -209,6 +232,12 @@ else version ( DragonFlyBSD )
 {
     void    endpwent();
     passwd* getpwent();
+    void    setpwent();
+}
+else version ( NetBSD )
+{
+    void    endpwent();
+    passwd* getpwent();
     void    setpwent();
 }
 else version (Solaris)
