$NetBSD$

--- misc/CMake/CompilerFlags.cmake.orig	2016-08-09 06:52:30.000000000 +0000
+++ misc/CMake/CompilerFlags.cmake
@@ -101,26 +101,26 @@ endmacro(RESTORE_CACHED_BUILD_FLAGS)
 # rely on CMake to specify Windows compilation flags - until
 # that changes, we can't afford to strip flags out on MSVC
 macro(CLEAR_BUILD_FLAGS)
-  set(BUILD_FLAGS_TO_CLEAR
-    CMAKE_C_FLAGS
-    CMAKE_CXX_FLAGS
-    CMAKE_SHARED_LINKER_FLAGS
-    CMAKE_EXE_LINKER_FLAGS
-    )
-  if (NOT MSVC)
-    foreach(bflag ${BUILD_FLAGS_TO_CLEAR})
-      set(${bflag} "")
-      unset(${bflag} CACHE)
-      foreach(BTYPE ${CMAKE_BUILD_TYPES})
-	set(${bflag}_${BTYPE} "")
-	unset(${bflag}_${BTYPE} CACHE)
-      endforeach(BTYPE ${CMAKE_BUILD_TYPES})
-    endforeach(bflag ${BUILD_FLAGS_TO_CLEAR})
-
-    set(CMAKE_C_FLAGS "$ENV{CFLAGS}")
-    set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS}")
-    set(CMAKE_SHARED_LINKER_FLAGS "$ENV{LDFLAGS}")
-  endif (NOT MSVC)
+#  set(BUILD_FLAGS_TO_CLEAR
+#    CMAKE_C_FLAGS
+#    CMAKE_CXX_FLAGS
+#    CMAKE_SHARED_LINKER_FLAGS
+#    CMAKE_EXE_LINKER_FLAGS
+#    )
+#  if (NOT MSVC)
+#    foreach(bflag ${BUILD_FLAGS_TO_CLEAR})
+#      set(${bflag} "")
+#      unset(${bflag} CACHE)
+#      foreach(BTYPE ${CMAKE_BUILD_TYPES})
+#	set(${bflag}_${BTYPE} "")
+#	unset(${bflag}_${BTYPE} CACHE)
+#      endforeach(BTYPE ${CMAKE_BUILD_TYPES})
+#    endforeach(bflag ${BUILD_FLAGS_TO_CLEAR})
+#
+#    set(CMAKE_C_FLAGS "$ENV{CFLAGS}")
+#    set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS}")
+#    set(CMAKE_SHARED_LINKER_FLAGS "$ENV{LDFLAGS}")
+#  endif (NOT MSVC)
 endmacro(CLEAR_BUILD_FLAGS)
 
 # To reduce verbosity in this file, determine up front which
