$NetBSD$

Patch pulled from upstream (Commit: a1cb25ad2d9a98ea9ec0bb3ee27fe3cde6046434) to allow compilation with recent Boost versions
--- src/iterators.cc.orig	2015-10-26 20:11:32.000000000 +0000
+++ src/iterators.cc
@@ -96,7 +96,7 @@ namespace {
       TRACE_DTOR(create_price_xact);
     }
 
-    void operator()(datetime_t& date, const amount_t& price) {
+    void operator()(const datetime_t& date, const amount_t& price) {
       xact_t * xact;
       string   symbol = price.commodity().symbol();
 
