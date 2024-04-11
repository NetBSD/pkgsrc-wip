$NetBSD$

Use boost error_code instead of std::error_code.

--- src/network/network.cc.orig	2024-04-01 05:56:26.201386553 +0000
+++ src/network/network.cc
@@ -63,7 +63,7 @@ bool NetAddress::resolve_to_v6(NetAddres
 }
 
 bool NetAddress::parse_ip(NetAddress* addr, const std::string& ip, uint16_t port) {
-	std::error_code ec;
+	boost::system::error_code ec;
 	asio::ip::address new_addr = asio::ip::address::from_string(ip, ec);
 	if (ec) {
 		return false;
