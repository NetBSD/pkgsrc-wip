$NetBSD: patch-content_common_file__path__watcher_file__path__watcher__stub.cc,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- content/common/file_path_watcher/file_path_watcher_stub.cc.orig	2011-05-24 08:01:07.000000000 +0000
+++ content/common/file_path_watcher/file_path_watcher_stub.cc
@@ -5,15 +5,19 @@
 // This file exists for Unix systems which don't have the inotify headers, and
 // thus cannot build file_watcher_inotify.cc
 
-#include "chrome/common/file_path_watcher/file_path_watcher.h"
+#include "content/common/file_path_watcher/file_path_watcher.h"
 
 class FilePathWatcherImpl : public FilePathWatcher::PlatformDelegate {
  public:
   virtual bool Watch(const FilePath& path,
-                     FileWatcher::Delegate* delegate,
-                     base::MessageLoopProxy*) OVERRIDE {
+                     FilePathWatcher::Delegate* delegate) OVERRIDE {
     return false;
   }
+  virtual void Cancel() OVERRIDE {
+  }
+  virtual void CancelOnMessageLoopThread() OVERRIDE {
+  }
+
 };
 
 FilePathWatcher::FilePathWatcher() {
