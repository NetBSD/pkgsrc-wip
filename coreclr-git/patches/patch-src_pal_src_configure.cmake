$NetBSD$

--- src/pal/src/configure.cmake.orig	2016-02-07 22:08:31.000000000 +0000
+++ src/pal/src/configure.cmake
@@ -19,7 +19,6 @@ endif()
 list(APPEND CMAKE_REQUIRED_DEFINITIONS -D_FILE_OFFSET_BITS=64)
 
 check_include_files(ieeefp.h HAVE_IEEEFP_H)
-check_include_files(alloca.h HAVE_ALLOCA_H)
 check_include_files(sys/vmparam.h HAVE_SYS_VMPARAM_H)
 check_include_files(mach/vm_types.h HAVE_MACH_VM_TYPES_H)
 check_include_files(mach/vm_param.h HAVE_MACH_VM_PARAM_H)
