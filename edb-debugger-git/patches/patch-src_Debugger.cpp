$NetBSD$

--- src/Debugger.cpp.orig	2017-02-18 21:21:09.000000000 +0000
+++ src/Debugger.cpp
@@ -78,12 +78,12 @@ along with this program.  If not, see <h
 
 #include <sys/types.h>
 #include <sys/stat.h>
-#if defined(Q_OS_LINUX) || defined(Q_OS_OPENBSD)
+#if defined(Q_OS_LINUX) || defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
 #include <unistd.h>
 #include <fcntl.h>
 #endif
 
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_NETBSD)
 #include "linker.h"
 #endif
 
@@ -105,6 +105,7 @@ const quint64 ld_loader_tag     = Q_UINT
 
 template <class Addr>
 void handle_library_event(IProcess *process, edb::address_t debug_pointer) {
+#if defined(Q_OS_LINUX)
 	edb::linux::r_debug<Addr> dynamic_info;
 	const bool ok = process->read_bytes(debug_pointer, &dynamic_info, sizeof(dynamic_info));
 	if(ok) {
@@ -130,11 +131,40 @@ void handle_library_event(IProcess *proc
 			break;
 		}
 	}
+#elif defined(Q_OS_NETBSD)
+	edb::netbsd::r_debug<Addr> dynamic_info;
+	const bool ok = process->read_bytes(debug_pointer, &dynamic_info, sizeof(dynamic_info));
+	if(ok) {
+
+		// NOTE(eteran): at least on my system, the name of
+		//               what is being loaded is either in
+		//               r8 or r13 depending on which event
+		//               we are looking at.
+		// TODO(eteran): find a way to get the name reliably
+
+		switch(dynamic_info.r_state) {
+		case edb::netbsd::r_debug<Addr>::RT_CONSISTENT:
+			// TODO(eteran): enable this once we are confident
+	#if 0
+			edb::v1::memory_regions().sync();
+	#endif
+			break;
+		case edb::netbsd::r_debug<Addr>::RT_ADD:
+			//qDebug("LIBRARY LOAD EVENT");
+			break;
+		case edb::netbsd::r_debug<Addr>::RT_DELETE:
+			//qDebug("LIBRARY UNLOAD EVENT");
+			break;
+		}
+	}
+#else
+#error portme
+#endif
 }
 
 template <class Addr>
 edb::address_t find_linker_hook_address(IProcess *process, edb::address_t debug_pointer) {
-
+#if defined(Q_OS_LINUX)
 	edb::linux::r_debug<Addr> dynamic_info;
 	const bool ok = process->read_bytes(debug_pointer, &dynamic_info, sizeof(dynamic_info));
 	if(ok) {
@@ -142,6 +172,17 @@ edb::address_t find_linker_hook_address(
 	}
 
 	return 0;
+#elif defined(Q_OS_NETBSD)
+	edb::netbsd::r_debug<Addr> dynamic_info;
+	const bool ok = process->read_bytes(debug_pointer, &dynamic_info, sizeof(dynamic_info));
+	if(ok) {
+		return edb::address_t::fromZeroExtended(dynamic_info.r_brk);
+	}
+
+	return 0;
+#else
+#error portme
+#endif
 }
 
 //--------------------------------------------------------------------------
@@ -533,7 +574,7 @@ QString Debugger::create_tty() {
 
 	QString result_tty = tty_file_;
 
-#if defined(Q_OS_LINUX) || defined(Q_OS_OPENBSD) || defined(Q_OS_FREEBSD)
+#if defined(Q_OS_LINUX) || defined(Q_OS_OPENBSD) || defined(Q_OS_NETBSD) || defined(Q_OS_FREEBSD)
 	// we attempt to reuse an open output window
 	if(edb::v1::config().tty_enabled && tty_proc_->state() != QProcess::Running) {
 		const QString command = edb::v1::config().tty_command;
@@ -2130,7 +2171,7 @@ edb::EVENT_STATUS Debugger::handle_trap(
 		state.set_instruction_pointer(previous_ip);
 		edb::v1::debugger_core->set_state(state);
 
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_NETBSD)
 		// test if we have hit our internal LD hook BP. If so, read in the r_debug
 		// struct so we can get the state, then we can just resume
 		// TODO(eteran): add an option to let the user stop of debug events
