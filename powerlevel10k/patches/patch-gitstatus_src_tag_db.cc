$NetBSD$

Fix build with GCC 14: std::unique_lock constructor is [[nodiscard]] so a
temporary unique_lock in a comma expression causes -Werror=unused-result.
Split into a named lock variable.

--- gitstatus/src/tag_db.cc.orig	2026-05-16 17:06:03.121364290 +0100
+++ gitstatus/src/tag_db.cc	2026-05-16 17:06:17.624705848 +0100
@@ -130,7 +130,8 @@
     if (res < tag && TagHasTarget(ref.c_str(), &oid)) res = tag;
   }
 
-  if ((std::unique_lock<std::mutex>(mutex_), id2name_dirty_)) {
+  std::unique_lock<std::mutex> lock(mutex_);
+  if (id2name_dirty_) {
     for (auto it = name2id_.rbegin(); it != name2id_.rend(); ++it) {
       if (!memcmp((*it)->id.id, oid.id, GIT_OID_RAWSZ) && !IsLooseTag((*it)->name)) {
         if (res < (*it)->name) res = (*it)->name;
