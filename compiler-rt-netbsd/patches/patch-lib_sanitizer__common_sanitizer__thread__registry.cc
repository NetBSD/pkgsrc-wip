$NetBSD$

--- lib/sanitizer_common/sanitizer_thread_registry.cc.orig	2017-10-17 18:35:46.000000000 +0000
+++ lib/sanitizer_common/sanitizer_thread_registry.cc
@@ -47,7 +47,7 @@ void ThreadContextBase::SetDead() {
 void ThreadContextBase::SetJoined(void *arg) {
   // FIXME(dvyukov): print message and continue (it's user error).
   CHECK_EQ(false, detached);
-  CHECK_EQ(ThreadStatusFinished, status);
+//  CHECK_EQ(ThreadStatusFinished, status);
   status = ThreadStatusDead;
   user_id = 0;
   OnJoined(arg);
