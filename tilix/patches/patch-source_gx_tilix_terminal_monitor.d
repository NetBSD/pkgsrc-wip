$NetBSD$

--- source/gx/tilix/terminal/monitor.d.orig	2019-04-22 14:46:58.000000000 +0000
+++ source/gx/tilix/terminal/monitor.d
@@ -43,7 +43,7 @@ private:
 
     bool fireEvents() {
         synchronized {
-            foreach(process; processes.values()) {
+            foreach(process; processes) {
                 if (process.eventType != MonitorEventType.NONE) {
                     onChildProcess.emit(process.eventType, process.gpid, process.activePid, process.activeName);
                     process.eventType = MonitorEventType.NONE;
@@ -138,7 +138,7 @@ void monitorProcesses(int sleep, Tid tid
             // all open terminals. We need to get these using shell
             // PID and will store them to raise events for each terminal.
             auto activeProcesses = getActiveProcessList();
-            foreach(process; processes.values()) {
+            foreach(process; processes) {
                 auto activeProcess  = activeProcesses.get(process.gpid, null);
                 // No need to raise event for same process.
                 if (activeProcess !is null && activeProcess.pid != process.activePid) {
