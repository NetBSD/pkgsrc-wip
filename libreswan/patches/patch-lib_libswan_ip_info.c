diff --git a/lib/libswan/ip_info.c b/lib/libswan/ip_info.c
index 70cd6a368f..97296d3a11 100644
--- lib/libswan/ip_info.c.dist
+++ lib/libswan/ip_info.c
@@ -158,7 +158,9 @@ static ip_port port_from_ipv6_sockaddr(const ip_sockaddr sa)
 
 #define IPv4_FF { { 255, 255, 255, 255, }, }
 
-const struct ip_info ipv4_info = {
+const struct ip_info ip_families[IP_INDEX_ROOF] = {
+
+	[IPv4_INDEX] = {
 
 	.ip_version = IPv4,
 	.ip_size = sizeof(struct in_addr),
@@ -210,11 +212,11 @@ const struct ip_info ipv4_info = {
 	.id_ip_addr = ID_IPV4_ADDR,
 	.id_ip_addr_subnet = ID_IPV4_ADDR_SUBNET,
 	.id_ip_addr_range = ID_IPV4_ADDR_RANGE,
-};
+	},
 
 #define IPv6_FF { { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, }
 
-const struct ip_info ipv6_info = {
+	[IPv6_INDEX] = {
 
 	.ip_version = IPv6,
 	.ip_size = sizeof(struct in6_addr),
@@ -266,6 +268,7 @@ const struct ip_info ipv6_info = {
 	.id_ip_addr = ID_IPV6_ADDR,
 	.id_ip_addr_subnet = ID_IPV6_ADDR_SUBNET,
 	.id_ip_addr_range = ID_IPV6_ADDR_RANGE,
+	}
 };
 
 const struct ip_info *aftoinfo(int af)
