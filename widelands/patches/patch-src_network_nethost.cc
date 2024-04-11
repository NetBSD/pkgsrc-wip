$NetBSD$

Use boost error_code instead of std::error_code.

--- src/network/nethost.cc.orig	2024-04-01 05:54:57.282840757 +0000
+++ src/network/nethost.cc
@@ -83,7 +83,7 @@ void NetHost::stop_listening() {
 	assert(!asio_thread_.joinable());
 
 	static const auto do_stop = [](asio::ip::tcp::acceptor& acceptor) {
-		std::error_code ec;
+		boost::system::error_code ec;
 		if (acceptor.is_open()) {
 			verb_log_info("[NetHost] Closing a listening IPv%d socket.", get_ip_version(acceptor));
 			acceptor.close(ec);
