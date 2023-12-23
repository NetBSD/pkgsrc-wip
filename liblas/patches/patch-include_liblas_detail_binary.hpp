$NetBSD$

Apply boost compat fix from merged upstream pull request
https://github.com/libLAS/libLAS/pull/166 .

--- include/liblas/detail/binary.hpp.orig	2022-06-20 17:45:56.297823730 +0000
+++ include/liblas/detail/binary.hpp
@@ -17,6 +17,8 @@
 #ifndef LIBLAS_DETAIL_BINARY_HPP_INCLUDED
 #define LIBLAS_DETAIL_BINARY_HPP_INCLUDED
 
+#include <liblas/detail/endian.hpp>
+
 #include <cassert>
 #include <climits>
 #include <cstring>
@@ -25,7 +27,6 @@
 
 #include <boost/config.hpp>
 #include <boost/static_assert.hpp>
-#include <boost/detail/endian.hpp>
 #include <boost/type_traits/is_signed.hpp>
 
 #if CHAR_BIT != 8
@@ -43,7 +44,7 @@ namespace detail { namespace binary {
 struct big_endian_tag {};
 struct little_endian_tag {};
 
-#ifdef BOOST_BIG_ENDIAN
+#ifdef LIBLAS_BIG_ENDIAN
 typedef big_endian_tag native_endian_tag;
 #else
 typedef little_endian_tag native_endian_tag;
