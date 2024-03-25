$NetBSD$

Fix mount point detection code for AIX and NetBSD.
https://github.com/fltk/fltk/issues/942
https://github.com/fltk/fltk/issues/944

--- src/drivers/Unix/Fl_Unix_System_Driver.cxx.orig	2024-03-24 07:48:45.000000000 +0000
+++ src/drivers/Unix/Fl_Unix_System_Driver.cxx
@@ -278,6 +278,8 @@ int Fl_Unix_System_Driver::file_browser_
 
   // We always have the root filesystem
   browser->add("/", icon);
+  num_files++;
+
   // Get the required buffer size for the vmount structures
   res = mntctl(MCTL_QUERY, sizeof(len), (char *) &len);
   if (!res) {
@@ -299,6 +301,7 @@ int Fl_Unix_System_Driver::file_browser_
           if (strcmp("/", filename) != 0) {
             strlcat(filename, "/", lname);
             browser->add(filename, icon);
+            num_files++;
           }
           vp = (struct vmount *) ((char *) vp + vp->vmt_length);
         }
@@ -317,6 +320,8 @@ int Fl_Unix_System_Driver::file_browser_
 
   // We always have the root filesystem
   browser->add("/", icon);
+  num_files++;
+
 #  ifdef HAVE_PTHREAD
   // Lock mutex for thread safety
   if (!pthread_mutex_lock(&getvfsstat_mutex)) {
@@ -330,6 +335,7 @@ int Fl_Unix_System_Driver::file_browser_
         if (strcmp("/", filename) != 0) {
           strlcat(filename, "/", lname);
           browser->add(filename, icon);
+          num_files++;
         }
       }
     } else {
