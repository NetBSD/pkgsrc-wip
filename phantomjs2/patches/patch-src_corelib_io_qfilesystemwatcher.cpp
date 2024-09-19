$NetBSD: patch-src_corelib_io_qfilesystemwatcher.cpp,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

* Add NetBSD support

--- src/qt/qtbase/src/corelib/io/qfilesystemwatcher.cpp.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtbase/src/corelib/io/qfilesystemwatcher.cpp
@@ -60,7 +60,7 @@
 #  include "qfilesystemwatcher_win_p.h"
 #elif defined(USE_INOTIFY)
 #  include "qfilesystemwatcher_inotify_p.h"
-#elif defined(Q_OS_FREEBSD) || defined(Q_OS_IOS) || (defined(Q_OS_OSX) && MAC_OS_X_VERSION_MIN_REQUIRED < MAC_OS_X_VERSION_10_7)
+#elif defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) || defined(Q_OS_IOS) || (defined(Q_OS_OSX) && MAC_OS_X_VERSION_MIN_REQUIRED < MAC_OS_X_VERSION_10_7)
 #  include "qfilesystemwatcher_kqueue_p.h"
 #elif defined(Q_OS_OSX) && MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_6
 #  include "qfilesystemwatcher_fsevents_p.h"
@@ -76,7 +76,7 @@ QFileSystemWatcherEngine *QFileSystemWat
     // there is a chance that inotify may fail on Linux pre-2.6.13 (August
     // 2005), so we can't just new inotify directly.
     return QInotifyFileSystemWatcherEngine::create(parent);
-#elif defined(Q_OS_FREEBSD) || defined(Q_OS_IOS) || (defined(Q_OS_OSX) && MAC_OS_X_VERSION_MIN_REQUIRED < MAC_OS_X_VERSION_10_7)
+#elif defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) || defined(Q_OS_IOS) || (defined(Q_OS_OSX) && MAC_OS_X_VERSION_MIN_REQUIRED < MAC_OS_X_VERSION_10_7)
     return QKqueueFileSystemWatcherEngine::create(parent);
 #elif defined(Q_OS_OSX) && MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_6
     return QFseventsFileSystemWatcherEngine::create(parent);
