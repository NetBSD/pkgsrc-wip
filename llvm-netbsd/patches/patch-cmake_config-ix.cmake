$NetBSD$

--- cmake/config-ix.cmake.orig	2017-12-08 18:50:04.615602612 +0000
+++ cmake/config-ix.cmake
@@ -153,7 +153,7 @@ if(NOT LLVM_USE_SANITIZER MATCHES "Memor
     endif()
     if(LLVM_ENABLE_TERMINFO)
       set(HAVE_TERMINFO 0)
-      foreach(library tinfo terminfo curses ncurses ncursesw)
+      foreach(library terminfo tinfo curses ncurses ncursesw)
         string(TOUPPER ${library} library_suffix)
         check_library_exists(${library} setupterm "" HAVE_TERMINFO_${library_suffix})
         if(HAVE_TERMINFO_${library_suffix})
