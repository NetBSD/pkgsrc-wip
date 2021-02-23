$NetBSD$

* turn off reduce locations on solaris since it currently doesn't work

--- configure.cmake.orig	2021-01-26 18:29:22.000000000 +0000
+++ configure.cmake
@@ -144,7 +144,7 @@ qt_config_linker_supports_flag_test(gdb_
 qt_config_compile_test(reduce_relocations
     LABEL "-Bsymbolic-functions support"
     CODE
-"#if !(defined(__i386) || defined(__i386__) || defined(__x86_64) || defined(__x86_64__) || defined(__amd64))
+"#if !(defined(__i386) || defined(__i386__) || defined(__x86_64) || defined(__x86_64__) || defined(__amd64)) || defined(__sun) || defined(__sun__)
 #  error Symbolic function binding on this architecture may be broken, disabling it (see QTBUG-36129).
 #endif
 
