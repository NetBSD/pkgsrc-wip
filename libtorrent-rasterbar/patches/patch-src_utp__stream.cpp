$NetBSD: patch-src_utp__stream.cpp,v 1.1 2015/07/13 07:57:39 thomasklausner Exp $

Make sure INT64_MAX is defined.

--- src/utp_stream.cpp.orig	2013-09-20 12:07:06.000000000 +0000
+++ src/utp_stream.cpp
@@ -30,6 +30,7 @@ POSSIBILITY OF SUCH DAMAGE.
 
 */
 
+#define __STDC_LIMIT_MACROS
 #include "libtorrent/config.hpp"
 #include "libtorrent/utp_stream.hpp"
 #include "libtorrent/sliding_average.hpp"
