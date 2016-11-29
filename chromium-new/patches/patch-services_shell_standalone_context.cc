$NetBSD$

--- services/shell/standalone/context.cc.orig	2016-11-10 20:02:16.000000000 +0000
+++ services/shell/standalone/context.cc
@@ -198,7 +198,7 @@ void Context::Init(std::unique_ptr<InitP
     tracing_remote_interfaces->GetInterface(
         tracing::mojom::StartupPerformanceDataCollector::Name_,
         mojo::GetProxy(&collector).PassMessagePipe());
-#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
     // CurrentProcessInfo::CreationTime is only defined on some platforms.
     const base::Time creation_time = base::CurrentProcessInfo::CreationTime();
     collector->SetShellProcessCreationTime(creation_time.ToInternalValue());
