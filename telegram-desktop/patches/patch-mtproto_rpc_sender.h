$NetBSD$

--- Telegram/SourceFiles/mtproto/mtproto_rpc_sender.h.orig	2020-01-28 17:45:49.000000000 +0000
+++ Telegram/SourceFiles/mtproto/mtproto_rpc_sender.h
@@ -7,7 +7,10 @@ https://github.com/telegramdesktop/tdesk
 */
 #pragma once
 
+#include "base/basic_types.h"
 #include "base/flat_set.h"
+#include "mtproto/mtproto_pch.h"
+
 
 class RPCError {
 public:
