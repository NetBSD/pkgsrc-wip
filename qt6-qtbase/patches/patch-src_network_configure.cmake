$NetBSD$

* add libraries needed for networking on solaris

--- src/network/configure.cmake.orig	2021-01-26 18:29:22.000000000 +0000
+++ src/network/configure.cmake
@@ -9,6 +9,8 @@
 qt_find_package(WrapBrotli PROVIDED_TARGETS WrapBrotli::WrapBrotliDec MODULE_NAME network QMAKE_LIB brotli)
 qt_find_package(Libproxy PROVIDED_TARGETS PkgConfig::Libproxy MODULE_NAME network QMAKE_LIB libproxy)
 qt_find_package(WrapOpenSSLHeaders PROVIDED_TARGETS WrapOpenSSLHeaders::WrapOpenSSLHeaders MODULE_NAME network QMAKE_LIB openssl/nolink)
+qt_test_lib_target(TARGET QtTEST::needed_network_libs LIBS socket nsl)
+
 # openssl_headers
 qt_config_compile_test(openssl_headers
     LIBRARIES
@@ -66,6 +68,7 @@ qt_find_package(GSSAPI PROVIDED_TARGETS
 # getifaddrs
 qt_config_compile_test(getifaddrs
     LABEL "getifaddrs()"
+    LIBRARIES QtTEST::needed_network_libs
     CODE
 "
 #include <sys/types.h>
@@ -89,6 +92,7 @@ freeifaddrs(list);
 # ipv6ifname
 qt_config_compile_test(ipv6ifname
     LABEL "IPv6 ifname"
+    LIBRARIES QtTEST::needed_network_libs
     CODE
 "
 #include <sys/types.h>
