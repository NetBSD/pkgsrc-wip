$NetBSD$

--- src/Debugger.h.orig	2017-02-18 21:21:09.000000000 +0000
+++ src/Debugger.h
@@ -325,7 +325,7 @@ private:
 	IDebugEvent::const_pointer                       last_event_;
 	QLabel *                                         status_;
 
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_NETBSD)
 	edb::address_t                                   debug_pointer_;
 	bool                                             dynamic_info_bp_set_;
 #endif
