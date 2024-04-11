$NetBSD$

Use boost error_code instead of std::error_code.

--- src/network/bufferedconnection.cc.orig	2024-04-01 05:38:03.875284374 +0000
+++ src/network/bufferedconnection.cc
@@ -132,7 +132,7 @@ bool BufferedConnection::is_connected() 
 }
 
 void BufferedConnection::close() {
-	std::error_code ec;
+	boost::system::error_code ec;
 	asio::ip::tcp::endpoint remote = socket_.remote_endpoint(ec);
 	if (!ec) {
 		verb_log_info("[BufferedConnection] Closing network socket connected to %s:%i.",
@@ -249,9 +249,9 @@ void BufferedConnection::start_sending()
 	asio::async_write(
 	   socket_, asio::buffer(nonempty_queue->front()),
 #ifndef NDEBUG
-	   [this, nonempty_queue](std::error_code ec, std::size_t length) {
+	   [this, nonempty_queue](boost::system::error_code ec, std::size_t length) {
 #else
-	   [this, nonempty_queue](std::error_code ec, std::size_t /*length*/) {
+	   [this, nonempty_queue](boost::system::error_code ec, std::size_t /*length*/) {
 #endif
 		   std::unique_lock<std::mutex> lock2(mutex_send_);
 		   currently_sending_ = false;
@@ -285,7 +285,7 @@ void BufferedConnection::start_receiving
 
 	socket_.async_read_some(
 	   asio::buffer(asio_receive_buffer_, kNetworkBufferSize),
-	   [this](std::error_code ec, std::size_t length) {
+	   [this](boost::system::error_code ec, std::size_t length) {
 		   if (!ec) {
 			   assert(length > 0);
 			   assert(length <= kNetworkBufferSize);
@@ -319,7 +319,7 @@ void BufferedConnection::reduce_send_buf
 	// Reduce the size of the send buffer. This will result in (slightly) slower
 	// file transfers but keeps the program responsive (e.g., chat messages are
 	// displayed) while transmitting files
-	std::error_code ec;
+	boost::system::error_code ec;
 	asio::socket_base::send_buffer_size send_buffer_size;
 	socket.get_option(send_buffer_size, ec);
 	if (!ec && send_buffer_size.value() > 20 * static_cast<int>(kNetworkBufferSize)) {
@@ -340,7 +340,7 @@ BufferedConnection::BufferedConnection(c
 
 	verb_log_info("[BufferedConnection] Trying to connect to %s:%u ... ",
 	              host.ip.to_string().c_str(), host.port);
-	std::error_code ec;
+	boost::system::error_code ec;
 	socket_.connect(destination, ec);
 	if (!ec && is_connected()) {
 		verb_log_info("success.\n");
