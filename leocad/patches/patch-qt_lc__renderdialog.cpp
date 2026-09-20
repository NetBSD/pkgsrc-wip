$NetBSD$

Treat all Unices like Linux.

--- qt/lc_renderdialog.cpp.orig	2026-09-19 23:44:29.000000000 +0000
+++ qt/lc_renderdialog.cpp
@@ -293,7 +293,7 @@ void lcRenderDialog::RenderPOVRay()
 	POVRayPath = QDir::cleanPath(QCoreApplication::applicationDirPath() + QLatin1String("/povconsole32-sse2.exe"));
 #endif
 
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 	POVRayPath = lcGetProfileString(LC_PROFILE_POVRAY_PATH);
 	Arguments.append("+FN");
 	Arguments.append("-D");
@@ -333,7 +333,7 @@ void lcRenderDialog::RenderPOVRay()
 	}
 
 	lcRenderProcess* Process = new lcRenderProcess(this);
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 	connect(Process, &QProcess::readyReadStandardError, this, [this]() { bool Error; ReadStdErr(Error); });
 #endif
 	QStringList POVEnv = QProcess::systemEnvironment();
@@ -749,7 +749,7 @@ void lcRenderDialog::Update()
 
 	if (ProcessFinished)
 	{
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 		QByteArray Output = mProcess->readAllStandardOutput();
 		mImage = QImage::fromData(Output);
 #endif
