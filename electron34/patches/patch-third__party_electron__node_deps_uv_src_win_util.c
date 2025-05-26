$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/deps/uv/src/win/util.c.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/deps/uv/src/win/util.c
@@ -1685,10 +1685,17 @@ int uv_os_uname(uv_utsname_t* buffer) {
     #ifdef _MSC_VER
     #pragma warning(suppress : 4996)
     #endif
+    #ifdef __clang__
+    #pragma clang diagnostic push
+    #pragma clang diagnostic ignored "-Wdeprecated-declarations"
+    #endif
     if (GetVersionExW(&os_info) == 0) {
       r = uv_translate_sys_error(GetLastError());
       goto error;
     }
+    #ifdef __clang__
+    #pragma clang diagnostic pop
+    #endif
   }
 
   /* Populate the version field. */
