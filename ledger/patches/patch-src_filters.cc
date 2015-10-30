$NetBSD$

Patch pulled from upstream (Commit: a1cb25ad2d9a98ea9ec0bb3ee27fe3cde6046434) to allow compilation with recent Boost versions
--- src/filters.cc.orig	2015-10-26 20:11:54.000000000 +0000
+++ src/filters.cc
@@ -707,7 +707,7 @@ namespace {
     insert_prices_in_map(price_map_t& _all_prices)
       : all_prices(_all_prices) {}
 
-    void operator()(datetime_t& date, const amount_t& price) {
+    void operator()(const datetime_t& date, const amount_t& price) {
       all_prices.insert(price_map_t::value_type(date, price));
     }
   };
