$NetBSD: patch-build_common__library.rb,v 1.5 2015/04/20 16:25:04 fhajny Exp $

Fix pkgsrc libeio/libev support.
--- build/common_library.rb.orig	2013-10-26 22:00:00.000000000 +0000
+++ build/common_library.rb
@@ -122,7 +122,7 @@ if USE_VENDORED_LIBEV
       "--disable-shared --enable-static " +
       # libev's configure script may select a different default compiler than we
       # do, so we force our compiler choice.
-      "CC='#{cc}' CXX='#{cxx}' CFLAGS='#{cflags}' orig_CFLAGS=1"
+      "CC='#{cc}' CXX='#{cxx}' CFLAGS='#{cflags}' orig_CFLAGS=1 @LIBEV_EXTRA_ARGS@"
   end
 
   libev_sources = Dir["ext/libev/{*.c,*.h}"]
@@ -141,8 +141,8 @@ if USE_VENDORED_LIBEV
 
   task :clean => 'libev:clean'
 else
-  LIBEV_CFLAGS = string_option('LIBEV_CFLAGS', '-I/usr/include/libev')
-  LIBEV_LIBS   = string_option('LIBEV_LIBS', '-lev')
+  LIBEV_CFLAGS = string_option('LIBEV_CFLAGS', '-I@PREFIX@/include/ev')
+  LIBEV_LIBS   = string_option('LIBEV_LIBS', '-L@PREFIX@/lib/ev @COMPILER_RPATH_FLAG@@PREFIX@/lib/ev -lev')
   LIBEV_TARGET = nil
   task :libev  # do nothing
 end
@@ -200,8 +200,8 @@ if USE_VENDORED_LIBEIO
 
   task :clean => 'libeio:clean'
 else
-  LIBEIO_CFLAGS = string_option('LIBEIO_CFLAGS', '-I/usr/include/libeio')
-  LIBEIO_LIBS   = string_option('LIBEIO_LIBS', '-leio')
+  LIBEIO_CFLAGS = string_option('LIBEIO_CFLAGS', '-I@PREFIX@/include/eio')
+  LIBEIO_LIBS   = string_option('LIBEIO_LIBS', '-L@PREFIX@/lib/eio @COMPILER_RPATH_FLAG@@PREFIX@/lib/eio -leio')
   LIBEIO_TARGET = nil
   task :libeio  # do nothing
 end
