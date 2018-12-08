$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_netbsd.cc.orig	2018-12-08 02:06:46.221494609 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_netbsd.cc
@@ -2113,6 +2113,24 @@ const unsigned RMD160_return_length = RM
 
 const unsigned MD5_CTX_sz = sizeof(MD5_CTX);
 const unsigned MD5_return_length = MD5_DIGEST_STRING_LENGTH;
+
+#define SHA2_CONST(LEN) \
+  const unsigned SHA##LEN##_CTX_sz = sizeof(SHA##LEN##_CTX); \
+  const unsigned SHA##LEN##_return_length = SHA##LEN##_DIGEST_STRING_LENGTH; \
+  const unsigned SHA##LEN##_block_length = SHA##LEN##_BLOCK_LENGTH; \
+  const unsigned SHA##LEN##_digest_length = SHA##LEN##_DIGEST_LENGTH
+
+SHA2_CONST(224);
+SHA2_CONST(256);
+SHA2_CONST(384);
+SHA2_CONST(512);
+
+#undef SHA2_CONST
+
+const int unvis_valid = UNVIS_VALID;
+const int unvis_validpush = UNVIS_VALIDPUSH;
+
+const unsigned fpos_t_sz = sizeof(fpos_t);
 }  // namespace __sanitizer
 
 using namespace __sanitizer;
