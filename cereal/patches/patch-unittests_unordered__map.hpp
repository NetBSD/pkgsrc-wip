$NetBSD$

Avoid char which is ambiguous, and may be signed or unsigned.
https://github.com/USCiLab/cereal/commit/2c647d87d492bea4400e95cf71c2de7270e2f3ab

--- unittests/unordered_map.hpp.orig	2026-08-09 01:42:43.700552774 +0000
+++ unittests/unordered_map.hpp
@@ -54,7 +54,7 @@ void test_unordered_map()
 
     std::unordered_map<int8_t, StructExternalSplit> o_esplunordered_map;
     for(int j=0; j<100; ++j)
-      o_esplunordered_map.insert({random_value<char>(gen),  { random_value<int>(gen), random_value<int>(gen) }});
+      o_esplunordered_map.insert({random_value<int8_t>(gen),  { random_value<int>(gen), random_value<int>(gen) }});
 
     std::ostringstream os;
     {
