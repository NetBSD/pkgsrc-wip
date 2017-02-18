$NetBSD$

--- ash/shell.cc.orig	2017-02-02 02:02:47.000000000 +0000
+++ ash/shell.cc
@@ -579,7 +579,7 @@ void Shell::Init(const ShellInitParams& 
 
   immersive_handler_factory_ = base::MakeUnique<ImmersiveHandlerFactoryAsh>();
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   NOTREACHED() << "linux desktop does not support ash.";
 #endif
 
