$NetBSD$

Fix boost 1.87 compatibility.
https://github.com/prusa3d/PrusaSlicer/issues/13799

Fix boost 1.88 compatibility.
https://github.com/prusa3d/PrusaSlicer/issues/14534

--- src/slic3r/Utils/Bonjour.cpp.orig	2025-11-06 09:19:38.000000000 +0000
+++ src/slic3r/Utils/Bonjour.cpp
@@ -17,6 +17,8 @@
 #include <boost/log/trivial.hpp>
 #include <boost/bind/bind.hpp>
 
+#include <boost/asio/deadline_timer.hpp>
+
 using boost::optional;
 using boost::system::error_code;
 namespace endian = boost::endian;
@@ -624,11 +626,11 @@ UdpSession::UdpSession(Bonjour::ReplyFn 
 	buffer.resize(DnsMessage::MAX_SIZE);
 }
 
-UdpSocket::UdpSocket( Bonjour::ReplyFn replyfn, const asio::ip::address& multicast_address, const asio::ip::address& interface_address, std::shared_ptr< boost::asio::io_service > io_service)
+UdpSocket::UdpSocket( Bonjour::ReplyFn replyfn, const asio::ip::address& multicast_address, const asio::ip::address& interface_address, std::shared_ptr< boost::asio::io_context > io_context)
 	: replyfn(replyfn)
 	, multicast_address(multicast_address)
-	, socket(*io_service)
-	, io_service(io_service)
+	, socket(*io_context)
+	, io_context(io_context)
 {
 	try {
 		// open socket
@@ -658,11 +660,11 @@ UdpSocket::UdpSocket( Bonjour::ReplyFn r
 }
 
 
-UdpSocket::UdpSocket( Bonjour::ReplyFn replyfn, const asio::ip::address& multicast_address, std::shared_ptr< boost::asio::io_service > io_service)
+UdpSocket::UdpSocket( Bonjour::ReplyFn replyfn, const asio::ip::address& multicast_address, std::shared_ptr< boost::asio::io_context > io_context)
 	: replyfn(replyfn)
 	, multicast_address(multicast_address)
-	, socket(*io_service)
-	, io_service(io_service)
+	, socket(*io_context)
+	, io_context(io_context)
 {
 	try {
 		// open socket
@@ -714,7 +716,7 @@ void UdpSocket::receive_handler(SharedSe
 	// let io_service to handle the datagram on session
 	// from boost documentation io_service::post:
 	// The io_service guarantees that the handler will only be called in a thread in which the run(), run_one(), poll() or poll_one() member functions is currently being invoked.
-	io_service->post(boost::bind(&UdpSession::handle_receive, session, error, bytes));
+        boost::asio::post(*io_context, boost::bind(&UdpSession::handle_receive, session, error, bytes));
 	// immediately accept new datagrams
 	async_receive();
 }
@@ -871,13 +873,13 @@ void Bonjour::priv::lookup_perform()
 {
 	service_dn = (boost::format("_%1%._%2%.local") % service % protocol).str();
 
-	std::shared_ptr< boost::asio::io_service > io_service(new boost::asio::io_service);
+	std::shared_ptr< boost::asio::io_context > io_context(new boost::asio::io_context);
 
 	std::vector<LookupSocket*> sockets;
 
 	// resolve intefaces - from PR#6646
 	std::vector<boost::asio::ip::address> interfaces;
-	asio::ip::udp::resolver resolver(*io_service);
+	asio::ip::udp::resolver resolver(*io_context);
 	boost::system::error_code ec;
 	// ipv4 interfaces
 	auto results = resolver.resolve(udp::v4(), asio::ip::host_name(), "", ec);
@@ -890,12 +892,12 @@ void Bonjour::priv::lookup_perform()
 		// create ipv4 socket for each interface
 		// each will send to querry to for both ipv4 and ipv6
 		for (const auto& intrfc : interfaces) 		
-			sockets.emplace_back(new LookupSocket(txt_keys, service, service_dn, protocol, replyfn, BonjourRequest::MCAST_IP4, intrfc, io_service));
+			sockets.emplace_back(new LookupSocket(txt_keys, service, service_dn, protocol, replyfn, BonjourRequest::MCAST_IP4, intrfc, io_context));
 	} else {
 		BOOST_LOG_TRIVIAL(info) << "Failed to resolve ipv4 interfaces: " << ec.message();
 	}
 	if (sockets.empty())
-		sockets.emplace_back(new LookupSocket(txt_keys, service, service_dn, protocol, replyfn, BonjourRequest::MCAST_IP4, io_service));
+		sockets.emplace_back(new LookupSocket(txt_keys, service, service_dn, protocol, replyfn, BonjourRequest::MCAST_IP4, io_context));
 	// ipv6 interfaces
 	interfaces.clear();
 	//udp::resolver::query query(host, PORT, boost::asio::ip::resolver_query_base::numeric_service);
@@ -910,9 +912,9 @@ void Bonjour::priv::lookup_perform()
 		// create ipv6 socket for each interface
 		// each will send to querry to for both ipv4 and ipv6
 		for (const auto& intrfc : interfaces)
-			sockets.emplace_back(new LookupSocket(txt_keys, service, service_dn, protocol, replyfn, BonjourRequest::MCAST_IP6, intrfc, io_service));
+			sockets.emplace_back(new LookupSocket(txt_keys, service, service_dn, protocol, replyfn, BonjourRequest::MCAST_IP6, intrfc, io_context));
 		if (interfaces.empty())
-			sockets.emplace_back(new LookupSocket(txt_keys, service, service_dn, protocol, replyfn, BonjourRequest::MCAST_IP6, io_service));
+			sockets.emplace_back(new LookupSocket(txt_keys, service, service_dn, protocol, replyfn, BonjourRequest::MCAST_IP6, io_context));
 	} else {
 		BOOST_LOG_TRIVIAL(info)<< "Failed to resolve ipv6 interfaces: " << ec.message();
 	}
@@ -923,13 +925,13 @@ void Bonjour::priv::lookup_perform()
 			socket->send();
 
 		// timer settings
-		asio::deadline_timer timer(*io_service);
+		asio::deadline_timer timer(*io_context);
 		retries--;
 		std::function<void(const error_code&)> timer_handler = [&](const error_code& error) {
 			// end 
 			if (retries == 0 || error) {
 				// is this correct ending?
-				io_service->stop();
+				io_context->stop();
 				if (completefn) {
 					completefn();
 				}
@@ -947,7 +949,7 @@ void Bonjour::priv::lookup_perform()
 		timer.expires_from_now(boost::posix_time::seconds(timeout));
 		timer.async_wait(timer_handler);
 		// start io_service, it will run until it has something to do - so in this case until stop is called in timer
-		io_service->run();
+		io_context->run();
 	}
 	catch (std::exception& e) {
 		BOOST_LOG_TRIVIAL(error) << e.what();
@@ -966,12 +968,12 @@ void Bonjour::priv::resolve_perform()
 			rpls.push_back(reply);
 	};
 
-	std::shared_ptr< boost::asio::io_service > io_service(new boost::asio::io_service);
+	std::shared_ptr< boost::asio::io_context > io_context(new boost::asio::io_context);
 	std::vector<ResolveSocket*> sockets;
 
 	// resolve interfaces - from PR#6646
 	std::vector<boost::asio::ip::address> interfaces;
-	asio::ip::udp::resolver resolver(*io_service);
+	asio::ip::udp::resolver resolver(*io_context);
 	boost::system::error_code ec;
 	// ipv4 interfaces
 	auto results = resolver.resolve(udp::v4(), asio::ip::host_name(), "", ec);
@@ -984,12 +986,12 @@ void Bonjour::priv::resolve_perform()
 		// create ipv4 socket for each interface
 		// each will send to querry to for both ipv4 and ipv6
 		for (const auto& intrfc : interfaces)
-			sockets.emplace_back(new ResolveSocket(hostname, reply_callback, BonjourRequest::MCAST_IP4, intrfc, io_service));
+			sockets.emplace_back(new ResolveSocket(hostname, reply_callback, BonjourRequest::MCAST_IP4, intrfc, io_context));
 	} else {
 		BOOST_LOG_TRIVIAL(info) << "Failed to resolve ipv4 interfaces: " << ec.message();
 	}
 	if (sockets.empty())
-		sockets.emplace_back(new ResolveSocket(hostname, reply_callback, BonjourRequest::MCAST_IP4, io_service));
+		sockets.emplace_back(new ResolveSocket(hostname, reply_callback, BonjourRequest::MCAST_IP4, io_context));
 
 	// ipv6 interfaces
 	interfaces.clear();
@@ -1003,9 +1005,9 @@ void Bonjour::priv::resolve_perform()
 		// create ipv6 socket for each interface
 		// each will send to querry to for both ipv4 and ipv6
 		for (const auto& intrfc : interfaces) 
-			sockets.emplace_back(new ResolveSocket(hostname, reply_callback, BonjourRequest::MCAST_IP6, intrfc, io_service));
+			sockets.emplace_back(new ResolveSocket(hostname, reply_callback, BonjourRequest::MCAST_IP6, intrfc, io_context));
 		if (interfaces.empty())
-			sockets.emplace_back(new ResolveSocket(hostname, reply_callback, BonjourRequest::MCAST_IP6, io_service));
+			sockets.emplace_back(new ResolveSocket(hostname, reply_callback, BonjourRequest::MCAST_IP6, io_context));
 	} else {
 		BOOST_LOG_TRIVIAL(info) << "Failed to resolve ipv6 interfaces: " << ec.message();
 	}
@@ -1016,14 +1018,14 @@ void Bonjour::priv::resolve_perform()
 			socket->send();
 
 		// timer settings
-		asio::deadline_timer timer(*io_service);
+		asio::deadline_timer timer(*io_context);
 		retries--;
 		std::function<void(const error_code&)> timer_handler = [&](const error_code& error) {
 			int replies_count = replies.size();
 			// end 
 			if (retries == 0 || error || replies_count > 0) {
 				// is this correct ending?
-				io_service->stop();
+				io_context->stop();
 				if (replies_count > 0 && resolvefn) {
 					resolvefn(replies);
 				}
@@ -1041,7 +1043,7 @@ void Bonjour::priv::resolve_perform()
 		timer.expires_from_now(boost::posix_time::seconds(timeout));
 		timer.async_wait(timer_handler);
 		// start io_service, it will run until it has something to do - so in this case until stop is called in timer
-		io_service->run();
+		io_context->run();
 	}
 	catch (std::exception& e) {
 		BOOST_LOG_TRIVIAL(error) << e.what();
