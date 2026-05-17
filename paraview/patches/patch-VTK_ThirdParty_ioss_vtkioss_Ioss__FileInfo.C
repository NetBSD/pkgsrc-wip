$NetBSD$

NFS temporarily disabled for NetBSD

--- VTK/ThirdParty/ioss/vtkioss/Ioss_FileInfo.C.orig	2026-03-31 10:30:33.000000000 +0000
+++ VTK/ThirdParty/ioss/vtkioss/Ioss_FileInfo.C
@@ -30,14 +30,7 @@
 #endif
 #else
 #include <unistd.h>
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
-#include <sys/mount.h>
-#elif defined(__OpenBSD__)
-#include <sys/mount.h>
-#include <sys/types.h>
-#else
-#include <sys/statfs.h>
-#endif
+#include <sys/statvfs.h>
 #endif
 
 #ifdef SEACAS_HAVE_MPI
@@ -179,9 +172,9 @@ namespace Ioss {
     char *path = ::realpath(tmp_path.c_str(), nullptr);
     if (path != nullptr) {
 
-      struct statfs stat_fs;
+      struct statvfs stat_vfs;
       // We want to run `statfs` on the path; not the filename since it might not exist.
-      if (statfs(path, &stat_fs) == -1) {
+      if (statvfs(path, &stat_vfs) == -1) {
         free(path);
         std::ostringstream errmsg;
         errmsg << "ERROR: Could not run statfs on '" << filename_ << "'.\n";
@@ -189,17 +182,7 @@ namespace Ioss {
       }
       free(path);
 
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
-      return stat_fs.f_fstypename;
-#else
-      /* linux statfs defines that 0x6969 is NFS filesystem */
-      if (stat_fs.f_type == 0x0BD00BD0)
-        return "lustre";
-      if (stat_fs.f_type == 0x47504653)
-        return "gpfs";
-      if (stat_fs.f_type == 0x6969)
-        return "nfs";
-#endif
+      return stat_vfs.f_fstypename;
     }
 #endif
     return "unknown";
@@ -208,7 +191,7 @@ namespace Ioss {
   //: Return TRUE if file is on an NFS filesystem...
   bool FileInfo::is_nfs() const
   {
-#if !defined(__IOSS_WINDOWS__)
+#if !defined(__IOSS_WINDOWS__) && !defined(__NetBSD__)
     auto tmp_path = pathname();
     if (tmp_path.empty()) {
       char *current_cwd = getcwd(nullptr, 0);
