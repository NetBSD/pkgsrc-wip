$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_netbsd.cc.orig	2018-12-10 09:29:18.793773992 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_netbsd.cc
@@ -2131,6 +2131,9 @@ SHA2_CONST(384);
 SHA2_CONST(512);
 
 #undef SHA2_CONST
+
+const int unvis_valid = UNVIS_VALID;
+const int unvis_validpush = UNVIS_VALIDPUSH;
 }  // namespace __sanitizer
 
 using namespace __sanitizer;
