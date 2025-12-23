$NetBSD$

allod NetBSD pthread_setname_np() variant

--- src/pipewireproduce.cpp.orig	2025-11-04 14:59:25.000000000 +0000
+++ src/pipewireproduce.cpp
@@ -174,7 +174,11 @@ void PipeWireProduce::setupStream()
             m_outputCondition.notify_all();
         }
     });
+#if defined(__NetBSD__)
+    pthread_setname_np(m_passthroughThread.native_handle(), "%s", (void *)"PipeWireProduce::passthrough");
+#else
     pthread_setname_np(m_passthroughThread.native_handle(), "PipeWireProduce::passthrough");
+#endif
 
     m_outputThread = std::thread([this]() {
         m_outputRunning = true;
@@ -196,7 +200,11 @@ void PipeWireProduce::setupStream()
             QMetaObject::invokeMethod(this, &PipeWireProduce::handleEncodedFramesChanged, Qt::QueuedConnection);
         }
     });
+#if defined(__NetBSD__)
+    pthread_setname_np(m_outputThread.native_handle(), "%s", (void *)"PipeWireProduce::output");
+#else
     pthread_setname_np(m_outputThread.native_handle(), "PipeWireProduce::output");
+#endif
 
     if (m_frameStatisticsTimer) {
         m_frameStatisticsTimer->start();
