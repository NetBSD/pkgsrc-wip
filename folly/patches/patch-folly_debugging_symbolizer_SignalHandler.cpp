$NetBSD$

NetBSD support.

--- folly/debugging/symbolizer/SignalHandler.cpp.orig	2024-08-19 19:38:02.775838120 +0000
+++ folly/debugging/symbolizer/SignalHandler.cpp
@@ -197,8 +197,8 @@ void dumpTimeInfo() {
   print("') ***\n");
 }
 
-const char* sigill_reason(int si_code) {
-  switch (si_code) {
+const char* sigill_reason(int folly_si_code) {
+  switch (folly_si_code) {
     case ILL_ILLOPC:
       return "illegal opcode";
     case ILL_ILLOPN:
@@ -221,8 +221,8 @@ const char* sigill_reason(int si_code) {
   }
 }
 
-const char* sigfpe_reason(int si_code) {
-  switch (si_code) {
+const char* sigfpe_reason(int folly_si_code) {
+  switch (folly_si_code) {
     case FPE_INTDIV:
       return "integer divide by zero";
     case FPE_INTOVF:
@@ -245,8 +245,8 @@ const char* sigfpe_reason(int si_code) {
   }
 }
 
-const char* sigsegv_reason(int si_code) {
-  switch (si_code) {
+const char* sigsegv_reason(int folly_si_code) {
+  switch (folly_si_code) {
     case SEGV_MAPERR:
       return "address not mapped to object";
     case SEGV_ACCERR:
@@ -257,8 +257,8 @@ const char* sigsegv_reason(int si_code) 
   }
 }
 
-const char* sigbus_reason(int si_code) {
-  switch (si_code) {
+const char* sigbus_reason(int folly_si_code) {
+  switch (folly_si_code) {
     case BUS_ADRALN:
       return "invalid address alignment";
     case BUS_ADRERR:
@@ -273,8 +273,8 @@ const char* sigbus_reason(int si_code) {
   }
 }
 
-const char* sigtrap_reason(int si_code) {
-  switch (si_code) {
+const char* sigtrap_reason(int folly_si_code) {
+  switch (folly_si_code) {
     case TRAP_BRKPT:
       return "process breakpoint";
     case TRAP_TRACE:
@@ -287,8 +287,8 @@ const char* sigtrap_reason(int si_code) 
   }
 }
 
-const char* sigchld_reason(int si_code) {
-  switch (si_code) {
+const char* sigchld_reason(int folly_si_code) {
+  switch (folly_si_code) {
     case CLD_EXITED:
       return "child has exited";
     case CLD_KILLED:
@@ -307,8 +307,8 @@ const char* sigchld_reason(int si_code) 
   }
 }
 
-const char* sigio_reason(int si_code) {
-  switch (si_code) {
+const char* sigio_reason(int folly_si_code) {
+  switch (folly_si_code) {
     case POLL_IN:
       return "data input available";
     case POLL_OUT:
@@ -327,22 +327,22 @@ const char* sigio_reason(int si_code) {
   }
 }
 
-const char* signal_reason(int signum, int si_code) {
+const char* signal_reason(int signum, int folly_si_code) {
   switch (signum) {
     case SIGILL:
-      return sigill_reason(si_code);
+      return sigill_reason(folly_si_code);
     case SIGFPE:
-      return sigfpe_reason(si_code);
+      return sigfpe_reason(folly_si_code);
     case SIGSEGV:
-      return sigsegv_reason(si_code);
+      return sigsegv_reason(folly_si_code);
     case SIGBUS:
-      return sigbus_reason(si_code);
+      return sigbus_reason(folly_si_code);
     case SIGTRAP:
-      return sigtrap_reason(si_code);
+      return sigtrap_reason(folly_si_code);
     case SIGCHLD:
-      return sigchld_reason(si_code);
+      return sigchld_reason(folly_si_code);
     case SIGIO:
-      return sigio_reason(si_code); // aka SIGPOLL
+      return sigio_reason(folly_si_code); // aka SIGPOLL
 
     default:
       return nullptr;
