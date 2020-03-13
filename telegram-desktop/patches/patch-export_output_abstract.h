$NetBSD$

--- Telegram/SourceFiles/export/output/export_output_abstract.h.orig	2020-03-06 00:32:42.296561696 +0000
+++ Telegram/SourceFiles/export/output/export_output_abstract.h
@@ -8,6 +8,7 @@ https://github.com/telegramdesktop/tdesk
 #pragma once
 
 #include <QtCore/QString>
+#include <memory>
 
 namespace Export {
 namespace Data {
