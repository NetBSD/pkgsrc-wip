$NetBSD$

Fix mount point detection code for AIX.
https://github.com/fltk/fltk/issues/942

--- src/drivers/Unix/Fl_Unix_System_Driver.cxx.orig	2024-03-20 16:41:08.000000000 +0000
+++ src/drivers/Unix/Fl_Unix_System_Driver.cxx
@@ -278,7 +278,7 @@ int Fl_Unix_System_Driver::file_browser_
   struct vmount *vp;
 
   // We always have the root filesystem
-  add("/", icon);
+  browser->add("/", icon);
   // Get the required buffer size for the vmount structures
   res = mntctl(MCTL_QUERY, sizeof(len), (char *) &len);
   if (!res) {
@@ -292,7 +292,8 @@ int Fl_Unix_System_Driver::file_browser_
       if (0 >= res) {
         res = -1;
       } else {
-        for (int i = 0, vp = (struct vmount *) list; i < res; ++i) {
+        vp = (struct vmount *) list;
+        for (int i = 0; i < res; ++i) {
           name = (char *) vp + vp->vmt_data[VMT_STUB].vmt_off;
           strlcpy(filename, name, lname);
           // Skip the already added root filesystem
