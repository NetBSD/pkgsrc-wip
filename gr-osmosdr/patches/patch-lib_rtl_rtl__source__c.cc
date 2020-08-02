$NetBSD: patch-lib_rtl_rtl__source__c.cc,v 1.1 2020/05/14 19:21:34 joerg Exp $

--- lib/rtl/rtl_source_c.cc.orig	2020-02-16 08:52:00.000000000 +0000
+++ lib/rtl/rtl_source_c.cc
@@ -32,7 +32,6 @@
 
 #include <boost/assign.hpp>
 #include <boost/format.hpp>
-#include <boost/detail/endian.hpp>
 #include <boost/algorithm/string.hpp>
 
 #include <stdexcept>
