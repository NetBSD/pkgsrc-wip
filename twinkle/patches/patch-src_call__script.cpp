$NetBSD$

* make sure environ is defined, used later in the code

--- src/call_script.cpp.orig	2022-02-19 05:05:00.000000000 +0000
+++ src/call_script.cpp
@@ -46,6 +46,8 @@
 #define SCR_TRIGGER_LOCAL_RELEASE	"local_release"
 #define SCR_TRIGGER_REMOTE_RELEASE	"remote_release"
 
+extern char **environ;
+
 /////////////////////////
 // class t_script_result
 /////////////////////////
