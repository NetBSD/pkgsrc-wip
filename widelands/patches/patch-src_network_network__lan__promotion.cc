$NetBSD$

Use boost error_code instead of std::error_code.

--- src/network/network_lan_promotion.cc.orig	2024-04-01 05:51:09.592667624 +0000
+++ src/network/network_lan_promotion.cc
@@ -156,7 +156,7 @@ LanBase::~LanBase() {
 
 bool LanBase::is_available() {
 	const auto do_is_available = [this](asio::ip::udp::socket& socket) -> bool {
-		std::error_code ec;
+		boost::system::error_code ec;
 		bool available = (socket.is_open() && socket.available(ec) > 0);
 		if (ec) {
 			log_err("[LAN] Error when checking whether data is available on IPv%d socket, closing it: "
@@ -212,7 +212,7 @@ size_t LanBase::receive(void* const buf,
 }
 
 bool LanBase::send(void const* const buf, size_t const len, const NetAddress& addr) {
-	std::error_code ec;
+	boost::system::error_code ec;
 	assert(addr.is_valid());
 	// If this assert failed, then there is some bug in the code. NetAddress should only be filled
 	// with valid IP addresses (e.g. no hostnames)
@@ -249,7 +249,7 @@ bool LanBase::broadcast(void const* cons
 	const auto do_broadcast = [this, buf, len, port](
 	                             asio::ip::udp::socket& socket, const std::string& address) -> bool {
 		if (socket.is_open()) {
-			std::error_code ec;
+			boost::system::error_code ec;
 			asio::ip::udp::endpoint destination(asio::ip::address::from_string(address), port);
 			socket.send_to(asio::buffer(buf, len), destination, 0, ec);
 			if (!ec) {
@@ -308,7 +308,7 @@ void LanBase::start_socket(asio::ip::udp
 		return;
 	}
 
-	std::error_code ec;
+	boost::system::error_code ec;
 	// Try to open the socket
 	socket->open(version, ec);
 	if (ec) {
@@ -363,7 +363,7 @@ void LanBase::report_network_error() {
 }
 
 void LanBase::close_socket(asio::ip::udp::socket* socket) {
-	std::error_code ec;
+	boost::system::error_code ec;
 	if (socket->is_open()) {
 		const asio::ip::udp::endpoint& endpoint = socket->local_endpoint(ec);
 		if (!ec) {
