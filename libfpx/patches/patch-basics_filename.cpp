$NetBSD$
* Add use statvfs since it's more portable than statfs.
  fixes build on NetBSD.
--- basics/filename.cpp.orig	2013-09-02 15:47:00.000000000 +0000
+++ basics/filename.cpp
@@ -38,6 +38,9 @@
 #ifdef _UNIX
 #  include <sys/types.h>
 #  include <sys/stat.h>
+#  if defined(HAVE_SYS_STATVFS_H)
+#    include <sys/statvfs.h>
+#  endif
 #  if defined(HAVE_SYS_STATFS_H)
 #    /* System V & Linux */
 #    include <sys/statfs.h>
@@ -428,6 +431,14 @@ long FicNom::PlaceDisponible() const
     return nFreeCluster * nSecPerCluster * nBytePerSec / 1024;
   else    // Function failed, don't know why
     return 0;
+#elif defined(HAVE_SYS_STATVFS_H)
+  struct statvfs buf;
+  int errNum;
+  errNum = statvfs ( ".", &buf);
+  if (errNum)
+	perror("statvfs on current directory");
+
+  return (buf.f_bsize*buf.f_bfree)/kOneKilobyte;
 #else
   struct statfs buf;
   int errNum;
