$NetBSD$

use system OpenSSL

--- cmake/plugins.cmake.orig	2026-07-15 12:37:44.000000000 +0000
+++ cmake/plugins.cmake
@@ -70,7 +70,7 @@ if(FEATURE_PLUGIN_SSL)
         target_link_libraries(SqueakSSL PRIVATE OpenSSL::SSL OpenSSL::Crypto)
         # The VM builds on an ubuntu with openssl 1.0, thus the ssl plugin links to it.
         # Ship ssl 1.0 with the VM, so the ssl plugin loads
-        if(BUILD_BUNDLE)
+        if(BUILD_BUNDLE AND NOT NETBSD)
             add_third_party_dependency("openssl-1.0.2q")
         endif()
     endif()
