$NetBSD$

--- base/files/file_path_watcher_kqueue.cc.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/files/file_path_watcher_kqueue.cc
@@ -71,7 +71,13 @@ int FilePathWatcherKQueue::EventsForPath
     struct kevent event;
     EV_SET(&event, fd, EVFILT_VNODE, (EV_ADD | EV_CLEAR | EV_RECEIPT),
            (NOTE_DELETE | NOTE_WRITE | NOTE_ATTRIB |
-            NOTE_RENAME | NOTE_REVOKE | NOTE_EXTEND), 0, data);
+            NOTE_RENAME | NOTE_REVOKE | NOTE_EXTEND), 0,
+#if defined(__NetBSD__)
+            reinterpret_cast<intptr_t>(data));
+#else
+            data);
+#endif
+
     events->push_back(event);
   }
   return last_existing_entry;
