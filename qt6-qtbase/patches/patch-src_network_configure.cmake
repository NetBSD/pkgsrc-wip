$NetBSD$

* add libraries needed for networking on solaris

--- src/network/configure.cmake.orig	2021-09-23 07:42:06.000000000 +0000
+++ src/network/configure.cmake
@@ -56,13 +56,14 @@ SSL_free(SSL_new(0));
 ")
 
 qt_find_package(GSSAPI PROVIDED_TARGETS GSSAPI::GSSAPI MODULE_NAME network QMAKE_LIB gssapi)
-
+qt_test_lib_target(TARGET QtTEST::needed_network_libs LIBS socket nsl)
 
 #### Tests
 
 # getifaddrs
 qt_config_compile_test(getifaddrs
     LABEL "getifaddrs()"
+    LIBRARIES QtTEST::needed_network_libs
     CODE
 "#include <sys/types.h>
 #include <sys/socket.h>
@@ -100,6 +101,7 @@ req.ifr_index = 0;
 # ipv6ifname
 qt_config_compile_test(ipv6ifname
     LABEL "IPv6 ifname"
+    LIBRARIES QtTEST::needed_network_libs
     CODE
 "#include <sys/types.h>
 #include <sys/socket.h>
