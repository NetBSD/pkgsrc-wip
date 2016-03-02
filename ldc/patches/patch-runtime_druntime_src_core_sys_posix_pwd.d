$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/pwd.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/pwd.d
@@ -85,6 +85,22 @@ else version( FreeBSD )
         int pw_fields;      /* internal: fields filled in */
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
@@ -143,6 +159,13 @@ else version( FreeBSD )
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
@@ -183,6 +206,12 @@ else version ( FreeBSD )
     passwd* getpwent();
     void    setpwent();
 }
+else version ( NetBSD )
+{
+    void    endpwent();
+    passwd* getpwent();
+    void    setpwent();
+}
 else version (Solaris)
 {
     void endpwent();
