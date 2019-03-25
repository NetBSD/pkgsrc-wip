$NetBSD$

* fix manpath

--- cmake/InstallFreeRDPMan.cmake.orig	2018-11-20 10:43:51.000000000 +0000
+++ cmake/InstallFreeRDPMan.cmake
@@ -1,9 +1,5 @@
 function(install_freerdp_man manpage section)
  if(WITH_MANPAGES)
-   if(OPENBSD OR FREEBSD)
        install(FILES ${manpage} DESTINATION man/man${section})
-    else()
-       install(FILES ${manpage} DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/man/man${section})
-   endif()
  endif()
 endfunction()
