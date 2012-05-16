$NetBSD: patch-ext__boost__config__stdlib__libstdcpp3.hpp,v 1.1.1.1 2012/05/16 14:08:19 fhajny Exp $

Fix for boost threads and GCC 4.7, as per:
https://svn.boost.org/trac/boost/ticket/6165
--- ext/boost/config/stdlib/libstdcpp3.hpp.orig	2012-05-11 08:21:03.384282290 +0000
+++ ext/boost/config/stdlib/libstdcpp3.hpp
@@ -31,7 +31,8 @@
 
 #ifdef __GLIBCXX__ // gcc 3.4 and greater:
 #  if defined(_GLIBCXX_HAVE_GTHR_DEFAULT) \
-        || defined(_GLIBCXX__PTHREADS)
+        || defined(_GLIBCXX__PTHREADS) \
+        || defined(_GLIBCXX_HAS_GTHREADS)
       //
       // If the std lib has thread support turned on, then turn it on in Boost
       // as well.  We do this because some gcc-3.4 std lib headers define _REENTANT
