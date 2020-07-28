$NetBSD$

static cast from a pointer to intptr_t is not allowed.

--- base/files/file_path_watcher_kqueue.cc.orig	2020-07-24 02:37:41.000000000 +0000
+++ base/files/file_path_watcher_kqueue.cc
@@ -74,7 +74,7 @@ int FilePathWatcherKQueue::EventsForPath
     struct kevent event;
     EV_SET(&event, fd, EVFILT_VNODE, (EV_ADD | EV_CLEAR | EV_RECEIPT),
            (NOTE_DELETE | NOTE_WRITE | NOTE_ATTRIB |
-            NOTE_RENAME | NOTE_REVOKE | NOTE_EXTEND), 0, data);
+            NOTE_RENAME | NOTE_REVOKE | NOTE_EXTEND), 0, reinterpret_cast<intptr_t>(data));
     events->push_back(event);
   }
   return last_existing_entry;
