$NetBSD$

Avoid char which is ambiguous, and may be signed or unsigned.
https://github.com/USCiLab/cereal/commit/2c647d87d492bea4400e95cf71c2de7270e2f3ab

--- unittests/map.hpp.orig	2026-08-09 01:35:51.369193037 +0000
+++ unittests/map.hpp
@@ -62,7 +62,7 @@ void test_map()
 
     std::map<int8_t, StructExternalSplit> o_esplmap;
     for(int j=0; j<100; ++j)
-      o_esplmap.insert({random_value<char>(gen),  { random_value<int>(gen), random_value<int>(gen) }});
+      o_esplmap.insert({random_value<int8_t>(gen),  { random_value<int>(gen), random_value<int>(gen) }});
 
     std::ostringstream os;
     {
