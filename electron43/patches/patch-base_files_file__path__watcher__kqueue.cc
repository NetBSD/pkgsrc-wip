$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/files/file_path_watcher_kqueue.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/files/file_path_watcher_kqueue.cc
@@ -81,9 +81,15 @@ size_t FilePathWatcherKQueue::EventsForP
     FilePath::StringType subdir = (i != (components.end() - 1)) ? *(i + 1) : "";
     EventData* data = new EventData(built_path, subdir);
     struct kevent event;
+#if defined(__NetBSD__) && __NetBSD_Version__ < 999000000
+    EV_SET(&event, fd, EVFILT_VNODE, (EV_ADD | EV_CLEAR | EV_RECEIPT),
+           (NOTE_DELETE | NOTE_WRITE | NOTE_ATTRIB |
+            NOTE_RENAME | NOTE_REVOKE | NOTE_EXTEND), 0, reinterpret_cast<intptr_t>(data));
+#else
     EV_SET(&event, fd, EVFILT_VNODE, (EV_ADD | EV_CLEAR | EV_RECEIPT),
            (NOTE_DELETE | NOTE_WRITE | NOTE_ATTRIB |
             NOTE_RENAME | NOTE_REVOKE | NOTE_EXTEND), 0, data);
+#endif
     events->push_back(event);
   }
   return last_existing_entry;
