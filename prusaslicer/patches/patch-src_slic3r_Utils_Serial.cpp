$NetBSD$

Treat NetBSD the same as OpenBSD.

--- src/slic3r/Utils/Serial.cpp.orig	2025-03-10 13:20:54.000000000 +0000
+++ src/slic3r/Utils/Serial.cpp
@@ -53,7 +53,7 @@
 	#include <sys/select.h>
 #endif
 
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__)
 	#include <termios.h>
 #elif defined __linux__
 	#include <fcntl.h>
@@ -282,12 +282,12 @@ std::vector<std::string> scan_serial_por
 namespace asio = boost::asio;
 using boost::system::error_code;
 
-Serial::Serial(asio::io_service& io_service) :
-	asio::serial_port(io_service)
+Serial::Serial(asio::io_context& io_context) :
+	asio::serial_port(io_context)
 {}
 
-Serial::Serial(asio::io_service& io_service, const std::string &name, unsigned baud_rate) :
-	asio::serial_port(io_service, name)
+Serial::Serial(asio::io_context& io_context, const std::string &name, unsigned baud_rate) :
+	asio::serial_port(io_context, name)
 {
 	set_baud_rate(baud_rate);
 }
@@ -346,7 +346,7 @@ void Serial::set_baud_rate(unsigned baud
 		ios.c_cc[VTIME] = 1;
 		handle_errno(::ioctl(handle, TCSETS2, &ios));
 
-#elif __OpenBSD__
+#elif __OpenBSD__ || __NetBSD__
 		struct termios ios;
 		handle_errno(::tcgetattr(handle, &ios));
 		handle_errno(::cfsetspeed(&ios, baud_rate));
@@ -390,19 +390,19 @@ void Serial::reset_line_num()
 
 bool Serial::read_line(unsigned timeout, std::string &line, error_code &ec)
 {
-	auto& io_service =
+	auto& io_context =
 #if BOOST_VERSION >= 107000
 		//FIXME this is most certainly wrong!
 		(boost::asio::io_context&)this->get_executor().context();
  #else
 		this->get_io_service();
 #endif
-	asio::deadline_timer timer(io_service);
+	asio::deadline_timer timer(io_context);
 	char c = 0;
 	bool fail = false;
 
 	while (true) {
-		io_service.reset();
+		io_context.reset();
 
 		asio::async_read(*this, boost::asio::buffer(&c, 1), [&](const error_code &read_ec, size_t size) {
 			if (ec || size == 0) {
@@ -423,7 +423,7 @@ bool Serial::read_line(unsigned timeout,
 			});
 		}
 
-		io_service.run();
+		io_context.run();
 
 		if (fail) {
 			return false;
