$NetBSD$

--- src/Debugger.cpp.orig	2017-02-18 21:21:09.000000000 +0000
+++ src/Debugger.cpp
@@ -78,7 +78,7 @@ along with this program.  If not, see <h
 
 #include <sys/types.h>
 #include <sys/stat.h>
-#if defined(Q_OS_LINUX) || defined(Q_OS_OPENBSD)
+#if defined(Q_OS_LINUX) || defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
 #include <unistd.h>
 #include <fcntl.h>
 #endif
@@ -533,7 +533,7 @@ QString Debugger::create_tty() {
 
 	QString result_tty = tty_file_;
 
-#if defined(Q_OS_LINUX) || defined(Q_OS_OPENBSD) || defined(Q_OS_FREEBSD)
+#if defined(Q_OS_LINUX) || defined(Q_OS_OPENBSD) || defined(Q_OS_NETBSD) || defined(Q_OS_FREEBSD)
 	// we attempt to reuse an open output window
 	if(edb::v1::config().tty_enabled && tty_proc_->state() != QProcess::Running) {
 		const QString command = edb::v1::config().tty_command;
