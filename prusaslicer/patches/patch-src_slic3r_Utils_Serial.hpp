$NetBSD$

Fix boost 1.87 compatibility.
https://github.com/prusa3d/PrusaSlicer/issues/13799

--- src/slic3r/Utils/Serial.hpp.orig	2025-04-06 03:12:04.097988431 +0000
+++ src/slic3r/Utils/Serial.hpp
@@ -43,8 +43,8 @@ extern std::vector<SerialPortInfo> 	scan
 class Serial : public boost::asio::serial_port
 {
 public:
-	Serial(boost::asio::io_service &io_service);
-	Serial(boost::asio::io_service &io_service, const std::string &name, unsigned baud_rate);
+	Serial(boost::asio::io_context &io_context);
+	Serial(boost::asio::io_context &io_context, const std::string &name, unsigned baud_rate);
 	Serial(const Serial &) = delete;
 	Serial &operator=(const Serial &) = delete;
 	~Serial();
