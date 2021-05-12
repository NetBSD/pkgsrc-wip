$NetBSD$

Conditionalize some AI_* constants not present on NetBSD. 

--- router/src/harness/include/mysql/harness/net_ts/internet.h.orig	2021-05-09 00:35:34.199395387 +0000
+++ router/src/harness/include/mysql/harness/net_ts/internet.h
@@ -598,8 +598,12 @@ class resolver_base {
   static constexpr flags canonical_name = AI_CANONNAME;
   static constexpr flags numeric_host = AI_NUMERICHOST;
   static constexpr flags numeric_service = AI_NUMERICSERV;
+#ifdef AI_V4MAPPED
   static constexpr flags v4_mapped = AI_V4MAPPED;
+#endif
+#ifdef AI_ALL
   static constexpr flags all_matching = AI_ALL;
+#endif
   static constexpr flags address_configured = AI_ADDRCONFIG;
 };
 
