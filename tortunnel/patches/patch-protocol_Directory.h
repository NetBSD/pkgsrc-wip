$NetBSD: patch-protocol_Directory.h,v 1.1 2013/12/12 13:00:58 noud4 Exp $

prevents
error: ISO C++ forbids declaration of 'list' with no type

--- protocol/Directory.h.orig	2013-12-12 12:41:46.000000000 +0000
+++ protocol/Directory.h
@@ -34,6 +34,7 @@
 #include <boost/asio.hpp>
 #include <boost/function.hpp>
 #include <boost/bind.hpp>
+#include <list>
 #include <string>
 #include <stdio.h>
 
