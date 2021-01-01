$NetBSD$

Fix a copypasto in order to make read receipts really configurable.

Shared upstream via:

 https://github.com/ars3niy/tdlib-purple/pull/102

--- tdlib-purple.cpp.orig	2021-01-01 15:49:27.000000000 +0000
+++ tdlib-purple.cpp
@@ -1013,8 +1013,8 @@ static void tgprpl_init (PurplePlugin *p
 
     if (canDisableReadReceipts()) {
         opt = purple_account_option_bool_new ("Send read receipts",
-                                              AccountOptions::EnableSecretChats,
-                                              AccountOptions::EnableSecretChatsDefault);
+                                              AccountOptions::ReadReceipts,
+                                              AccountOptions::ReadReceiptsDefault);
         prpl_info.protocol_options = g_list_append(prpl_info.protocol_options, opt);
     }
 }
