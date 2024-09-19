$NetBSD$

# Support latest boost API

--- src/preforked-http-server.cpp.orig	2018-07-24 13:59:15 UTC
+++ src/preforked-http-server.cpp
@@ -206,7 +206,7 @@ void preforked_server::start()
 
 bool preforked_server::read_socket_from_parent(int fd_socket, boost::asio::ip::tcp::socket& socket)
 {
-	typedef boost::asio::ip::tcp::socket::native_type native_type;
+	typedef boost::asio::ip::tcp::socket::native_handle_type native_type;
 
 #if __APPLE__
 	// macos is special...
@@ -270,7 +270,7 @@ bool preforked_server::read_socket_from_
 
 void preforked_server::write_socket_to_worker(int fd_socket, boost::asio::ip::tcp::socket& socket)
 {
-	typedef boost::asio::ip::tcp::socket::native_type native_type;
+	typedef boost::asio::ip::tcp::socket::native_handle_type native_type;
 	
 	struct msghdr msg;
 	union {
@@ -293,7 +293,7 @@ void preforked_server::write_socket_to_w
 	*(reinterpret_cast<native_type*>(CMSG_DATA(cmptr))) = socket.native();
 	*/
 	native_type *fdptr = reinterpret_cast<native_type*>(CMSG_DATA(cmptr));
-	*fdptr = socket.native();
+	*fdptr = socket.native_handle();
 	
 	msg.msg_name = nullptr;
 	msg.msg_namelen = 0;
