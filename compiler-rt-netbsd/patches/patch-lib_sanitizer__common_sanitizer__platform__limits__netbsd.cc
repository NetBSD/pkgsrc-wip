$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_netbsd.cc.orig	2018-12-05 15:17:53.000000000 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_netbsd.cc
@@ -2101,6 +2101,35 @@ const int modctl_load = MODCTL_LOAD;
 const int modctl_unload = MODCTL_UNLOAD;
 const int modctl_stat = MODCTL_STAT;
 const int modctl_exists = MODCTL_EXISTS;
+
+const unsigned SHA1_CTX_sz = sizeof(SHA1_CTX);
+const unsigned SHA1_return_length = SHA1_DIGEST_STRING_LENGTH; // 41
+const unsigned MD2_CTX_sz = sizeof(MD2_CTX);
+const unsigned MD2_return_length = MD2_DIGEST_STRING_LENGTH; // 33
+const unsigned MD4_CTX_sz = sizeof(MD4_CTX);
+const unsigned MD4_return_length = 33;
+const unsigned MD5_CTX_sz = sizeof(MD5_CTX);
+const unsigned MD5_return_length = MD5_DIGEST_STRING_LENGTH; // 33
+const unsigned RMD160_CTX_sz = sizeof(RMD160_CTX);
+const unsigned RMD160_return_length = RMD160_DIGEST_STRING_LENGTH;// 41
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
