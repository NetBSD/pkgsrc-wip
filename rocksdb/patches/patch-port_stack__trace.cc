$NetBSD$

--- port/stack_trace.cc.orig	2018-01-03 02:58:03.000000000 +0000
+++ port/stack_trace.cc
@@ -72,7 +72,7 @@ void PrintStackTraceLine(const char* sym
 
   fprintf(stderr, "\n");
 }
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_NETBSD)
 
 void PrintStackTraceLine(const char* symbol, void* frame) {
   static int pid = getpid();
@@ -106,7 +106,7 @@ void PrintStack(int first_frames_to_skip
   auto num_frames = backtrace(frames, kMaxFrames);
   auto symbols = backtrace_symbols(frames, num_frames);
 
-  for (int i = first_frames_to_skip; i < num_frames; ++i) {
+  for (unsigned int i = first_frames_to_skip; i < num_frames; ++i) {
     fprintf(stderr, "#%-2d  ", i - first_frames_to_skip);
     PrintStackTraceLine((symbols != nullptr) ? symbols[i] : nullptr, frames[i]);
   }
