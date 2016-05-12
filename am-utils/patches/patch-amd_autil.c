$NetBSD$

Linux wants the parent ctime to change as well.

--- ./amd/autil.c.orig	2014-10-28 17:12:59.000000000 +0000
+++ ./amd/autil.c
@@ -183,6 +183,7 @@ forcibly_timeout_mp(am_node *mp)
      * more.
      */
     clocktime(&mp->am_parent->am_fattr.na_mtime);
+    mp->am_parent->am_fattr.na_ctime = mp->am_parent->am_fattr.na_mtime;
     reschedule_timeout_mp();
   }
 }
@@ -312,8 +313,10 @@ am_mounted(am_node *mp)
   /*
    * Update mtime of parent node (copying "struct nfstime" in '=' below)
    */
-  if (mp->am_parent && mp->am_parent->am_al->al_mnt)
+  if (mp->am_parent && mp->am_parent->am_al->al_mnt) {
     mp->am_parent->am_fattr.na_mtime = mp->am_fattr.na_mtime;
+    mp->am_parent->am_fattr.na_ctime = mp->am_fattr.na_mtime;
+  }
 
   /*
    * This is ugly, but essentially unavoidable
@@ -711,8 +714,10 @@ am_unmounted(am_node *mp)
   /*
    * Update mtime of parent node
    */
-  if (mp->am_parent && mp->am_parent->am_al->al_mnt)
+  if (mp->am_parent && mp->am_parent->am_al->al_mnt) {
     clocktime(&mp->am_parent->am_fattr.na_mtime);
+    mp->am_parent->am_fattr.na_ctime = mp->am_parent->am_fattr.na_mtime;
+  }
 
   if (mp->am_parent && (mp->am_flags & AMF_REMOUNT)) {
     char *fname = xstrdup(mp->am_name);
