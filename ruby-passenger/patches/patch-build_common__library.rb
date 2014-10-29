$NetBSD: patch-build_common__library.rb,v 1.3 2014/10/29 12:59:17 fhajny Exp $

Fix pkgsrc libeio/libev support.
--- build/common_library.rb.orig	2013-10-26 22:00:00.000000000 +0000
+++ build/common_library.rb
@@ -151,8 +151,8 @@ if USE_VENDORED_LIBEV
 
 	task :clean => 'libev:clean'
 else
-	LIBEV_CFLAGS = string_option('LIBEV_CFLAGS', '-I/usr/include/libev')
-	LIBEV_LIBS   = string_option('LIBEV_LIBS', '-lev')
+	LIBEV_CFLAGS = string_option('LIBEV_CFLAGS', '-I@PREFIX@/include/ev')
+	LIBEV_LIBS   = string_option('LIBEV_LIBS', '-L@PREFIX@/lib/ev @COMPILER_RPATH_FLAG@@PREFIX@/lib/ev -lev')
 	LIBEV_TARGET = nil
 	task :libev  # do nothing
 end
@@ -202,8 +202,8 @@ if USE_VENDORED_LIBEIO
 		end
 	end
 else
-	LIBEIO_CFLAGS = string_option('LIBEIO_CFLAGS', '-I/usr/include/libeio')
-	LIBEIO_LIBS   = string_option('LIBEIO_LIBS', '-leio')
+	LIBEIO_CFLAGS = string_option('LIBEIO_CFLAGS', '-I@PREFIX@/include/eio')
+	LIBEIO_LIBS   = string_option('LIBEIO_LIBS', '-L@PREFIX@/lib/eio @COMPILER_RPATH_FLAG@@PREFIX@/lib/eio -leio')
 	LIBEIO_TARGET = nil
 	task :libeio  # do nothing
 end
