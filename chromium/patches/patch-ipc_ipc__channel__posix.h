$NetBSD: patch-ipc_ipc__channel__posix.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- ipc/ipc_channel_posix.h.orig	2011-04-13 08:01:34.000000000 +0000
+++ ipc/ipc_channel_posix.h
@@ -125,7 +125,7 @@ class Channel::ChannelImpl : public Mess
   };
 
   // This is a control message buffer large enough to hold kMaxReadFDs
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_NETBSD)
   // TODO(agl): OSX appears to have non-constant CMSG macros!
   char input_cmsg_buf_[1024];
 #else
