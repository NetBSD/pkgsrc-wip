$NetBSD: patch-base_debug_trace__event.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/debug/trace_event.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/debug/trace_event.cc
@@ -74,7 +74,7 @@ void TraceLog::Trace(const std::string& 
   TimeTicks tick = TimeTicks::Now();
 #endif
   TimeDelta delta = tick - trace_start_time_;
-  int64 usec = delta.InMicroseconds();
+  int64_t usec = delta.InMicroseconds();
   std::string msg =
     StringPrintf("{'pid':'0x%lx', 'tid':'0x%lx', 'type':'%s', "
                  "'name':'%s', 'id':'%p', 'extra':'%s', 'file':'%s', "
