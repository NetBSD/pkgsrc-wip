$NetBSD: patch-src_mongo_shell_linenoise__utf8.h,v 1.1 2015/01/05 11:45:32 fhajny Exp $

Use Boost swap instead of std. Fixes build on SunOS.
--- src/mongo/shell/linenoise_utf8.h.orig	2014-10-07 16:07:51.000000000 +0000
+++ src/mongo/shell/linenoise_utf8.h
@@ -15,6 +15,7 @@
  *    limitations under the License.
  */
 
+#include <boost/core/swap.hpp>
 #include <boost/smart_ptr/scoped_array.hpp>
 #include <string.h>
 
@@ -142,9 +143,9 @@ struct UtfStringMixin {
     size_t chars() const { return _chars; }
 
     void swap( UtfStringMixin& other ) {
-        std::swap( _len, other._len );
-        std::swap( _cap, other._cap );
-        std::swap( _chars, other._chars );
+        boost::swap( _len, other._len );
+        boost::swap( _cap, other._cap );
+        boost::swap( _chars, other._chars );
         _str.swap( other._str );
     }
 
