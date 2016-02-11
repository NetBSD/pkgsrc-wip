$NetBSD$

--- runtime/druntime/src/core/sys/posix/pwd.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/pwd.d
@@ -85,6 +85,21 @@ else version( FreeBSD )
         int pw_fields;      /* internal: fields filled in */
     }
 }
+else version( NetBSD )
+{
+    struct passwd {
+    	char*          pw_name;		/* user name */
+    	char*          pw_passwd;	/* encrypted password */
+    	uid_t	       pw_uid;		/* user uid */
+    	gid_t	       pw_gid;		/* user gid */
+    	time_t	       pw_change;	/* password change time */
+    	char*          pw_class;	/* user login class */
+    	char*          pw_gecos;	/* general information */
+    	char*          pw_dir;		/* home directory */
+    	char*          pw_shell;	/* default shell */
+    	time_t 	       pw_expire;	/* account expiration */
+    }
+}
 else version (Solaris)
 {
     struct passwd
@@ -143,6 +158,11 @@ else version( FreeBSD )
     int getpwnam_r(in char*, passwd*, char*, size_t, passwd**);
     int getpwuid_r(uid_t, passwd*, char*, size_t, passwd**);
 }
+else version( NetBSD )
+{
+    int getpwnam_r(in char*, passwd*, char*, size_t, passwd**);
+    int getpwuid_r(uid_t, passwd*, char*, size_t, passwd**);
+}
 else version (Solaris)
 {
     int getpwnam_r(in char*, passwd*, char*, size_t, passwd**);
@@ -183,6 +203,12 @@ else version ( FreeBSD )
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
