$NetBSD$

* Fix build on NetBSD

--- node_modules/node-pty/src/unix/pty.cc.orig	2025-03-01 10:48:28.000000000 +0000
+++ node_modules/node-pty/src/unix/pty.cc
@@ -42,6 +42,9 @@
 #elif defined(__FreeBSD__)
 #include <libutil.h>
 #include <termios.h>
+#elif defined(__NetBSD__)
+#include <util.h>
+#include <termios.h>
 #endif
 
 /* Some platforms name VWERASE and VDISCARD differently */
@@ -445,10 +448,10 @@ Napi::Value PtyFork(const Napi::Callback
   }
 #endif
 
-  Napi::Object obj = Napi::Object::New(napiEnv);  
-  obj.Set("fd", Napi::Number::New(napiEnv, master));  
-  obj.Set("pid", Napi::Number::New(napiEnv, pid));  
-  obj.Set("pty", Napi::String::New(napiEnv, ptsname(master)));  
+  Napi::Object obj = Napi::Object::New(napiEnv);
+  obj.Set("fd", Napi::Number::New(napiEnv, master));
+  obj.Set("pid", Napi::Number::New(napiEnv, pid));
+  obj.Set("pty", Napi::String::New(napiEnv, ptsname(master)));
 
   // Set up process exit callback.
   Napi::Function cb = info[10].As<Napi::Function>();
@@ -489,10 +492,10 @@ Napi::Value PtyOpen(const Napi::Callback
     throw Napi::Error::New(env, "Could not set slave fd to nonblocking.");
   }
 
-  Napi::Object obj = Napi::Object::New(env);  
-  obj.Set("master", Napi::Number::New(env, master));  
-  obj.Set("slave", Napi::Number::New(env, slave));  
-  obj.Set("pty", Napi::String::New(env, ptsname(master)));  
+  Napi::Object obj = Napi::Object::New(env);
+  obj.Set("master", Napi::Number::New(env, master));
+  obj.Set("slave", Napi::Number::New(env, slave));
+  obj.Set("pty", Napi::String::New(env, ptsname(master)));
 
   return obj;
 }
