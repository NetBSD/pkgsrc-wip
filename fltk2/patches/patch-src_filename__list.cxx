$NetBSD$

Add a version check for NetBSD. The nonstandard scandir() parameter types are
no longer required since version 8. Newer versions will be catched by check
of configure script and the HAVE_SCANDIR_POSIX condition.

--- src/filename_list.cxx.orig	2012-03-23 05:49:17.000000000 +0000
+++ src/filename_list.cxx
@@ -67,7 +67,7 @@ int fltk::filename_list(const char *d, d
 #elif defined(HAVE_SCANDIR_POSIX)
   // POSIX (2008) defines the comparison function like this:
   int n = scandir(d, list, 0, (int(*)(const dirent **, const dirent **))sort);
-#elif defined(__linux) || defined (__FreeBSD__) || defined (__NetBSD__)
+#elif defined(__linux) || defined (__FreeBSD__) || (defined (__NetBSD__) && __NetBSD_Version__-0 < 799005100)
   int n = scandir(d, list, 0, (int(*)(const void*,const void*))sort);
 #elif defined(__osf__) || defined(__sgi)
   // OSF, DU 4.0x
