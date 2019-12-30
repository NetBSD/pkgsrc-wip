$NetBSD$

* remove use of deprecated header
  from upstream:
  
--- src/lib/util/encode/base_n.cc.orig	2019-12-20 19:19:59.959141555 +0000
+++ src/lib/util/encode/base_n.cc
@@ -18,7 +18,7 @@
 #include <boost/archive/iterators/base64_from_binary.hpp>
 #include <boost/archive/iterators/binary_from_base64.hpp>
 #include <boost/archive/iterators/transform_width.hpp>
-#include <boost/math/common_factor.hpp>
+#include <boost/integer/common_factor.hpp>
 
 #include <stdint.h>
 #include <stdexcept>
@@ -267,7 +267,7 @@ struct BaseNTransformer {
     // without padding.  It's the least common multiple of 8 and BitsPerChunk,
     // e.g. 24 for base64.
     static const int BITS_PER_GROUP =
-        boost::math::static_lcm<BitsPerChunk, 8>::value;
+        boost::integer::static_lcm<BitsPerChunk, 8>::value;
 
     // MAX_PADDING_CHARS is the maximum number of padding characters
     // that can appear in a valid baseN encoded text.
