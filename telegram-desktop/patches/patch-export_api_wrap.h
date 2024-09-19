$NetBSD$

--- Telegram/SourceFiles/export/export_api_wrap.h.orig	2020-02-22 15:24:22.773948270 +0000
+++ Telegram/SourceFiles/export/export_api_wrap.h
@@ -7,6 +7,7 @@ https://github.com/telegramdesktop/tdesk
 */
 #pragma once
 
+#include "base/base_pch.h"
 #include "mtproto/mtproto_concurrent_sender.h"
 
 namespace Export {
