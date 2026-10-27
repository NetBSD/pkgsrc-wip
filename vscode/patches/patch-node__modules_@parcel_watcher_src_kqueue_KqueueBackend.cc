$NetBSD$

* Add NetBSD support, no fdclosedir()

--- node_modules/@parcel/watcher/src/kqueue/KqueueBackend.cc.orig	2026-10-26 17:06:42.000000000 +0000
+++ node_modules/@parcel/watcher/src/kqueue/KqueueBackend.cc
@@ -189,9 +189,9 @@ std::vector<KqueueSubscription *> Kqueue
 }
 
 bool KqueueBackend::compareDir(int fd, std::string &path, std::unordered_set<WatcherRef> &watchers) {
-  // macOS doesn't support fdclosedir, so we have to duplicate the file descriptor
+  // macOS and NetBSD don't support fdclosedir, so we have to duplicate the file descriptor
   // to ensure the closedir doesn't also stop watching.
-  #if __APPLE__
+  #if defined(__APPLE__) || defined(__NetBSD__)
     fd = dup(fd);
   #endif
 
@@ -279,7 +279,7 @@ bool KqueueBackend::compareDir(int fd, s
     }
   }
 
-  #if __APPLE__
+  #if defined(__APPLE__) || defined(__NetBSD__)
     closedir(dir);
   #else
     fdclosedir(dir);
