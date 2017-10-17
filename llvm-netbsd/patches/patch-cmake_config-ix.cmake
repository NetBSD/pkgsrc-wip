$NetBSD$

--- cmake/config-ix.cmake.orig	2017-10-16 20:22:53.000000000 +0000
+++ cmake/config-ix.cmake
@@ -144,7 +144,7 @@ if( NOT PURE_WINDOWS AND NOT LLVM_USE_SA
   endif()
   if(LLVM_ENABLE_TERMINFO)
     set(HAVE_TERMINFO 0)
-    foreach(library tinfo terminfo curses ncurses ncursesw)
+    foreach(library terminfo tinfo curses ncurses ncursesw)
       string(TOUPPER ${library} library_suffix)
       check_library_exists(${library} setupterm "" HAVE_TERMINFO_${library_suffix})
       if(HAVE_TERMINFO_${library_suffix})
