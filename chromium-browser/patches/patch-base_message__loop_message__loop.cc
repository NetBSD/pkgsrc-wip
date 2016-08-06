$NetBSD$

--- base/message_loop/message_loop.cc.orig	2016-08-05 17:13:37.000000000 +0000
+++ base/message_loop/message_loop.cc
@@ -214,7 +214,7 @@ std::unique_ptr<MessagePump> MessageLoop
 // TODO(rvargas): Get rid of the OS guards.
 #if defined(USE_GLIB) && !defined(OS_NACL)
   typedef MessagePumpGlib MessagePumpForUI;
-#elif defined(OS_LINUX) && !defined(OS_NACL)
+#elif (defined(OS_LINUX) && !defined(OS_NACL)) || defined(OS_BSD)
   typedef MessagePumpLibevent MessagePumpForUI;
 #endif
 
