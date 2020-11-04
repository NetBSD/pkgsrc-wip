$NetBSD$

Use newer endian handling in boost.

--- src/admesh/stlinit.cpp.orig	2020-03-21 10:55:51.000000000 +0000
+++ src/admesh/stlinit.cpp
@@ -26,9 +26,9 @@
 #include <math.h>
 #include <assert.h>
 
+#include <boost/endian.hpp>
 #include <boost/log/trivial.hpp>
 #include <boost/nowide/cstdio.hpp>
-#include <boost/detail/endian.hpp>
 
 #include "stl.h"
 
@@ -36,7 +36,7 @@
 #error "SEEK_SET not defined"
 #endif
 
-#ifndef BOOST_LITTLE_ENDIAN
+#if __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
 extern void stl_internal_reverse_quads(char *buf, size_t cnt);
 #endif /* BOOST_LITTLE_ENDIAN */
 
@@ -89,7 +89,7 @@ static FILE* stl_open_count_facets(stl_f
     	// Read the int following the header.  This should contain # of facets.
 	  	uint32_t header_num_facets;
     	bool header_num_faces_read = fread(&header_num_facets, sizeof(uint32_t), 1, fp) != 0;
-#ifndef BOOST_LITTLE_ENDIAN
+#if __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
     	// Convert from little endian to big endian.
     	stl_internal_reverse_quads((char*)&header_num_facets, 4);
 #endif /* BOOST_LITTLE_ENDIAN */
@@ -158,7 +158,7 @@ static bool stl_read(stl_file *stl, FILE
       		// Read a single facet from a binary .STL file. We assume little-endian architecture!
       		if (fread(&facet, 1, SIZEOF_STL_FACET, fp) != SIZEOF_STL_FACET)
       			return false;
-#ifndef BOOST_LITTLE_ENDIAN
+#if __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
       		// Convert the loaded little endian data to big endian.
       		stl_internal_reverse_quads((char*)&facet, 48);
 #endif /* BOOST_LITTLE_ENDIAN */
