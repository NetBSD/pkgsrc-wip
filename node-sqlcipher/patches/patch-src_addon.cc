$NetBSD$

Breakpoint 1 at 0x345f10
<function, no debug info> __cxa_thread_atexit@plt;
REG dtor=0x71f5e7d50110 obj=0x71f608376630 dso=0x71f5e7dfaa80
Napi::Reference<Napi::Function>::~Reference() in section .text of /usr/pkgsrc/wip/signal-desktop/work/Signal-Desktop-8.33.0/node_modules/.pnpm/@signalapp+sqlcipher@4.1.0/node_modules/@signalapp/sqlcipher/prebuilds/netbsd-x64/node_sqlcipher.node
#0  0x000071f5e7c45e20 in __cxa_thread_atexit@plt () from /usr/pkgsrc/wip/signal-desktop/work/Signal-Desktop-8.33.0/node_modules/.pnpm/@signalapp+sqlcipher@4.1.0/node_modules/@signalapp/sqlcipher/prebuilds/netbsd-x64/node_sqlcipher.node
#1  0x000071f5e7c4e3f4 in SetLogger(Napi::CallbackInfo const&) () from /usr/pkgsrc/wip/signal-desktop/work/Signal-Desktop-8.33.0/node_modules/.pnpm/@signalapp+sqlcipher@4.1.0/node_modules/@signalapp/sqlcipher/prebuilds/netbsd-x64/node_sqlcipher.node
#2  0x000071f5e7d51338 in Napi::details::CallbackData<void (*)(Napi::CallbackInfo const&), void>::Wrapper(napi_env__*, napi_callback_info__*) () from /usr/pkgsrc/wip/signal-desktop/work/Signal-Desktop-8.33.0/node_modules/.pnpm/@signalapp+sqlcipher@4.1.0/node_modules/@signalapp/sqlcipher/prebuilds/netbsd-x64/node_sqlcipher.node
DATABASE_SCHEMA.md was updated.
Thread 1 "MainThread" received signal SIGSEGV, Segmentation fault.
0x0000000000eb086f in napi_delete_reference ()
CRASH pc=0xeb086f
#0  0x0000000000eb086f in napi_delete_reference ()


--- src/addon.cc.orig	2026-08-20 17:23:05.000000000 +0000
+++ src/addon.cc
@@ -233,7 +233,7 @@ static void SetLogger(const Napi::Callba
   assert(callback.IsFunction());
 
   logger_fn_.Reset(callback, 1);
-
+  logger_fn_.SuppressDestruct();
   sqlite3_config(SQLITE_CONFIG_LOG, LoggerWrapper);
 }
 
