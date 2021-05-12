$NetBSD$

* add c++11 override to kqueue methods
  https://codereview.qt-project.org/c/qt/qtbase/+/345328

--- src/corelib/io/qfilesystemwatcher_kqueue_p.h.orig	2021-05-08 15:38:41.326716498 +0000
+++ src/corelib/io/qfilesystemwatcher_kqueue_p.h
@@ -71,8 +71,8 @@ public:
 
     static QKqueueFileSystemWatcherEngine *create(QObject *parent);
 
-    QStringList addPaths(const QStringList &paths, QStringList *files, QStringList *directories);
-    QStringList removePaths(const QStringList &paths, QStringList *files, QStringList *directories);
+    QStringList addPaths(const QStringList &paths, QStringList *files, QStringList *directories) override;
+    QStringList removePaths(const QStringList &paths, QStringList *files, QStringList *directories) override;
 
 private Q_SLOTS:
     void readFromKqueue();
