$NetBSD$

* Make sure current_thread_data_key has been obtained from pthread_key_create
  before before it, set_thread_data ensures this. Fixes crash when closing threaded
  Qt6 apps on NetBSD.

  Sent to and applied upstream:
  https://codereview.qt-project.org/c/qt/qtbase/+/421914

--- src/corelib/thread/qthread_unix.cpp.orig	2022-07-13 13:11:12.532990932 +0000
+++ src/corelib/thread/qthread_unix.cpp
@@ -171,8 +171,7 @@ static void set_thread_data(QThreadData 
 
 static void clear_thread_data()
 {
-    currentThreadData = nullptr;
-    pthread_setspecific(current_thread_data_key, nullptr);
+    set_thread_data(nullptr);
 }
 
 template <typename T>
