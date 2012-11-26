$NetBSD: patch-src_plugins_debugger_gdb_gdbengine.cpp,v 1.1 2012/11/26 01:05:11 fwsf Exp $

Fix debugger commands for systems with unix line endings.

--- src/plugins/debugger/gdb/gdbengine.cpp.orig	2012-08-08 13:47:06.000000000 +0000
+++ src/plugins/debugger/gdb/gdbengine.cpp
@@ -891,7 +891,7 @@ void GdbEngine::flushCommand(const GdbCo
         QMetaObject::invokeMethod(this, "handleResponse",
             Q_ARG(QByteArray, buffer));
     } else {
-        m_gdbAdapter->write(cmd.command + "\r\n");
+        m_gdbAdapter->write(cmd.command + "\n");
 
         // Start Watchdog.
         if (m_commandTimer.interval() <= 20000)
