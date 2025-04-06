$NetBSD$

Fix boost 1.87 compatibility.
https://github.com/prusa3d/PrusaSlicer/issues/13799

--- src/slic3r/Utils/TCPConsole.cpp.orig	2025-04-06 03:25:22.230721404 +0000
+++ src/slic3r/Utils/TCPConsole.cpp
@@ -4,6 +4,7 @@
 ///|/ PrusaSlicer is released under the terms of the AGPLv3 or higher
 ///|/
 #include <boost/asio/buffer.hpp>
+#include <boost/asio/connect.hpp>
 #include <boost/asio/io_context.hpp>
 #include <boost/asio/ip/tcp.hpp>
 #include <boost/asio/read_until.hpp>
@@ -161,7 +162,7 @@ bool TCPConsole::run_queue()
 
         auto endpoints = m_resolver.resolve(m_host_name, m_port_name);
 
-        m_socket.async_connect(endpoints->endpoint(),
+        boost::asio::async_connect(m_socket, endpoints,
             boost::bind(&TCPConsole::handle_connect, this, boost::placeholders::_1)
         );
 
