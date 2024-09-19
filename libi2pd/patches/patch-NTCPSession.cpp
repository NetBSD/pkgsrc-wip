$NetBSD$

>"due the bug in gcc 4.7. std::shared_future.get() is not const"
github.com/PurpleI2P/i2pd/commit/30fb0f5a942cc5195c725feae25ab38f88b08436

--- libi2pd/NTCPSession.cpp	2018-01-30 16:14:29.000000000 +0000
+++ libi2pd/NTCPSession.cpp
@@ -171,7 +171,7 @@ namespace transport
 					return;
 				}
 			}
-#if (__GNUC__ == 4) && (__GNUC_MINOR__ <= 7)
+#if (__GNUC__ == 4) && (__GNUC_MINOR__ <= 7) || defined(__NetBSD__)
 // due the bug in gcc 4.7. std::shared_future.get() is not const
 			if (!m_DHKeysPair)
 				m_DHKeysPair = transports.GetNextDHKeysPair ();
@@ -250,7 +250,7 @@ namespace transport
 		}
 		else
 		{
-#if (__GNUC__ == 4) && (__GNUC_MINOR__ <= 7)
+#if (__GNUC__ == 4) && (__GNUC_MINOR__ <= 7) || defined (__NetBSD__)
 // due the bug in gcc 4.7. std::shared_future.get() is not const
 			CreateAESKey (m_Establisher->phase2.pubKey);
 			HandlePhase2 ();
