$NetBSD$

* ASSERT_COMPILES includes ; it is also called with a ; at the end,
  this expands to ;;, so remove one of them

--- libcaf_core/test/scheduled_actor.cpp.orig	2021-07-16 09:33:16.000000000 +0000
+++ libcaf_core/test/scheduled_actor.cpp
@@ -12,7 +12,7 @@ using namespace caf;
 
 #define ASSERT_COMPILES(expr, msg)                                             \
   static_assert(                                                               \
-    std::is_void_v<decltype(std::declval<scheduled_actor*>()->expr)>, msg);
+    std::is_void_v<decltype(std::declval<scheduled_actor*>()->expr)>, msg)
 
 namespace {
 
