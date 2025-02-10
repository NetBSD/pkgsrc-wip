$NetBSD$

* Fix to find libcrypto++

--- sdk/cmake/modules/sdklib_libraries.cmake.orig	2025-01-24 13:56:57.000000000 +0100
+++ sdk/cmake/modules/sdklib_libraries.cmake
@@ -95,7 +95,7 @@ macro(load_sdklib_libraries)
 
         find_package(PkgConfig REQUIRED) # For libraries loaded using pkg-config
 
-        pkg_check_modules(cryptopp REQUIRED IMPORTED_TARGET libcrypto++)
+        pkg_check_modules(cryptopp REQUIRED IMPORTED_TARGET libcryptopp)
         target_link_libraries(SDKlib PUBLIC PkgConfig::cryptopp) # TODO: Private for SDK core
 
         pkg_check_modules(sodium REQUIRED IMPORTED_TARGET libsodium)
