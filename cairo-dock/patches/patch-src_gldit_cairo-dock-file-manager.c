$NetBSD$

--- src/gldit/cairo-dock-file-manager.c.orig	2015-02-19 15:03:40.000000000 +0000
+++ src/gldit/cairo-dock-file-manager.c
@@ -21,7 +21,9 @@
 #include <string.h>      // memset
 #include <sys/stat.h>    // stat
 #include <fcntl.h>  // open
-#include <sys/sendfile.h>  // sendfile
+#if defined(__FreeBSD__) || defined(__linux__)
+# include <sys/sendfile.h>  // sendfile
+#endif
 #include <errno.h>  // errno
 
 #include "gldi-config.h"
@@ -503,10 +505,12 @@ gboolean cairo_dock_copy_file (const gch
 	{
 		// perform in-kernel transfer (zero copy to user space)
 		int size;
-		#ifdef __FreeBSD__
+		#if defined(__FreeBSD__)
 		size = sendfile (src_fd, dest_fd, 0, stat.st_size, NULL, NULL, 0);
-		#else  // Linux >= 2.6.33 for being able to have a regular file as the output socket
+		#elif defined(__linux__)  // Linux >= 2.6.33 for being able to have a regular file as the output socket
 		size = sendfile (dest_fd, src_fd, NULL, stat.st_size);  // note the inversion between both calls ^_^;
+		#else
+		size = -1;
 		#endif
 		if (size < 0)  // error, fallback to a read-write method
 		{
