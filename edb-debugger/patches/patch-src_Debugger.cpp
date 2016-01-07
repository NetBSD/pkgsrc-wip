$NetBSD$

--- src/Debugger.cpp.orig	2014-01-14 17:26:29.000000000 +0000
+++ src/Debugger.cpp
@@ -77,7 +77,7 @@ along with this program.  If not, see <h
 
 #include <sys/types.h>
 #include <sys/stat.h>
-#if defined(Q_OS_LINUX) || defined(Q_OS_OPENBSD)
+#if defined(Q_OS_LINUX) || defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
 #include <unistd.h>
 #endif
 
@@ -314,7 +314,7 @@ void Debugger::update_menu_state(GUI_STA
 // Desc: creates a TTY object for our command line I/O
 //------------------------------------------------------------------------------
 QString Debugger::create_tty() {
-#if defined(Q_OS_LINUX) || defined(Q_OS_OPENBSD) || defined(Q_OS_FREEBSD)
+#if defined(Q_OS_LINUX) || defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD) || defined(Q_OS_FREEBSD)
 	// we attempt to reuse an open output window
 	if(edb::v1::config().tty_enabled && tty_proc_->state() != QProcess::Running) {
 		const QString command = edb::v1::config().tty_command;
