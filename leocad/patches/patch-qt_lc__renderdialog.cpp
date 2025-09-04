$NetBSD$

Treat all Unices like Linux.

--- qt/lc_renderdialog.cpp.orig	2025-09-01 20:49:34.000000000 +0000
+++ qt/lc_renderdialog.cpp
@@ -292,7 +292,7 @@ void lcRenderDialog::RenderPOVRay()
 	POVRayPath = QDir::cleanPath(QCoreApplication::applicationDirPath() + QLatin1String("/povconsole32-sse2.exe"));
 #endif
 
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 	POVRayPath = lcGetProfileString(LC_PROFILE_POVRAY_PATH);
 	Arguments.append("+FN");
 	Arguments.append("-D");
@@ -332,7 +332,7 @@ void lcRenderDialog::RenderPOVRay()
 	}
 
 	lcRenderProcess* Process = new lcRenderProcess(this);
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNUX
 	connect(Process, SIGNAL(readyReadStandardError()), this, SLOT(ReadStdErr()));
 #endif
 	QStringList POVEnv = QProcess::systemEnvironment();
@@ -662,7 +662,7 @@ void lcRenderDialog::Update()
 
 	if (mProcess->state() == QProcess::NotRunning)
 	{
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 		QByteArray Output = mProcess->readAllStandardOutput();
 		mImage = QImage::fromData(Output);
 #endif
