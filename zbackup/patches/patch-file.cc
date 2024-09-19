$NetBSD$

--- file.cc.orig	2015-09-16 07:28:04.000000000 +0000
+++ file.cc
@@ -6,7 +6,7 @@
 #include <unistd.h>
 #include <cerrno>
 #include <cstring>
-#ifdef __APPLE__
+#if defined(__APPLE_) || defined(__NetBSD__) || defined(__FreeBSD__)
   #include <sys/socket.h>
 #else
   #include <sys/sendfile.h>
@@ -67,6 +67,16 @@ void File::rename( std::string const & f
       #ifdef __APPLE__
       if ( -1 == sendfile(write_fd, read_fd, offset, &stat_buf.st_size, NULL, 0) )
          throw exCantRename( from + " to " + to );
+      #elif defined(__NetBSD__) || defined(__OpenBSD__)
+
+      size_t BUFSIZE = 4096, size;
+      char buf[BUFSIZE];
+
+      while ( ( size = ::read( read_fd, buf, BUFSIZE ) ) != -1 && size != 0 )
+        ::write( write_fd, buf, size );
+
+      if ( size == -1 )
+         throw exCantRename( from + " to " + to );
       #else
       if ( -1 == sendfile(write_fd, read_fd, &offset, stat_buf.st_size) )
          throw exCantRename( from + " to " + to );
