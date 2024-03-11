diff --git a/include/ip_info.h b/include/ip_info.h
index 40e99ef687..c1329a8569 100644
--- include/ip_info.h.dist
+++ include/ip_info.h
@@ -9,6 +9,7 @@
 #include "ip_subnet.h"
 #include "ip_selector.h"
 #include "ip_sockaddr.h"
+#include "ip_index.h"
 
 struct ip_info {
 	/*
@@ -113,8 +114,10 @@ struct ip_info {
 
 };
 
-extern const struct ip_info ipv4_info;
-extern const struct ip_info ipv6_info;
+extern const struct ip_info ip_families[IP_INDEX_ROOF];
+
+#define ipv4_info ip_families[IPv4_INDEX]
+#define ipv6_info ip_families[IPv6_INDEX]
 
 extern const struct ip_info *aftoinfo(int af);
 
