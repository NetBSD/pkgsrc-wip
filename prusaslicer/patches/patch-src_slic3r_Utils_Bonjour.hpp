$NetBSD$

Fix boost 1.87 compatibility.
https://github.com/prusa3d/PrusaSlicer/issues/13799

--- src/slic3r/Utils/Bonjour.hpp.orig	2025-04-06 03:09:43.494517035 +0000
+++ src/slic3r/Utils/Bonjour.hpp
@@ -155,11 +155,11 @@ public:
 	UdpSocket(Bonjour::ReplyFn replyfn
 		, const boost::asio::ip::address& multicast_address
 		, const boost::asio::ip::address& interface_address
-		, std::shared_ptr< boost::asio::io_service > io_service);
+		, std::shared_ptr< boost::asio::io_context > io_context);
 
 	UdpSocket(Bonjour::ReplyFn replyfn
 		, const boost::asio::ip::address& multicast_address
-		, std::shared_ptr< boost::asio::io_service > io_service);
+		, std::shared_ptr< boost::asio::io_context > io_context);
 
 	void send();
 	void async_receive();
@@ -172,7 +172,7 @@ protected:
 	boost::asio::ip::address					    multicast_address;
 	boost::asio::ip::udp::socket					socket;
 	boost::asio::ip::udp::endpoint					mcast_endpoint;
-	std::shared_ptr< boost::asio::io_service >	io_service;
+	std::shared_ptr< boost::asio::io_context >	io_context;
 	std::vector<BonjourRequest>						requests;
 };
 
@@ -186,8 +186,8 @@ public:
 		, Bonjour::ReplyFn replyfn
 		, const boost::asio::ip::address& multicast_address
 		, const boost::asio::ip::address& interface_address
-		, std::shared_ptr< boost::asio::io_service > io_service)
-		: UdpSocket(replyfn, multicast_address, interface_address, io_service)
+		, std::shared_ptr< boost::asio::io_context > io_context)
+		: UdpSocket(replyfn, multicast_address, interface_address, io_context)
 		, txt_keys(txt_keys)
 		, service(service)
 		, service_dn(service_dn)
@@ -203,8 +203,8 @@ public:
 		, std::string protocol
 		, Bonjour::ReplyFn replyfn
 		, const boost::asio::ip::address& multicast_address
-		, std::shared_ptr< boost::asio::io_service > io_service)
-		: UdpSocket(replyfn, multicast_address, io_service)
+		, std::shared_ptr< boost::asio::io_context > io_context)
+		: UdpSocket(replyfn, multicast_address, io_context)
 		, txt_keys(txt_keys)
 		, service(service)
 		, service_dn(service_dn)
@@ -241,8 +241,8 @@ public:
 		, Bonjour::ReplyFn replyfn
 		, const boost::asio::ip::address& multicast_address
 		, const boost::asio::ip::address& interface_address
-		, std::shared_ptr< boost::asio::io_service > io_service)
-		: UdpSocket(replyfn, multicast_address, interface_address, io_service)
+		, std::shared_ptr< boost::asio::io_context > io_context)
+		: UdpSocket(replyfn, multicast_address, interface_address, io_context)
 		, hostname(hostname)
 
 	{
@@ -253,8 +253,8 @@ public:
 	ResolveSocket(const std::string& hostname
 		, Bonjour::ReplyFn replyfn
 		, const boost::asio::ip::address& multicast_address
-		, std::shared_ptr< boost::asio::io_service > io_service)
-		: UdpSocket(replyfn, multicast_address, io_service)
+		, std::shared_ptr< boost::asio::io_context > io_context)
+		: UdpSocket(replyfn, multicast_address, io_context)
 		, hostname(hostname)
 
 	{
