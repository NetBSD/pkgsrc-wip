$NetBSD$

Treat all Unices like Linux.

--- qt/lc_renderdialog.cpp.orig	2021-06-05 23:41:42.000000000 +0000
+++ qt/lc_renderdialog.cpp
@@ -183,7 +183,7 @@ void lcRenderDialog::on_RenderButton_cli
 	POVRayPath = QDir::cleanPath(QCoreApplication::applicationDirPath() + QLatin1String("/povconsole32-sse2.exe"));
 #endif
 
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 	POVRayPath = lcGetProfileString(LC_PROFILE_POVRAY_PATH);
 	Arguments.append("+FN");
 	Arguments.append("-D");
@@ -194,7 +194,7 @@ void lcRenderDialog::on_RenderButton_cli
 #endif
 
 	mProcess = new QProcess(this);
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 	connect(mProcess, SIGNAL(readyReadStandardError()), this, SLOT(ReadStdErr()));
 #endif
 	mProcess->start(POVRayPath, Arguments);
@@ -221,7 +221,7 @@ void lcRenderDialog::ReadStdErr()
 {
 	QString StdErr = QString(mProcess->readAllStandardError());
 	mStdErrList.append(StdErr);
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 	QRegExp RegexPovRayProgress("Rendered (\\d+) of (\\d+) pixels.*");
 	RegexPovRayProgress.setCaseSensitivity(Qt::CaseInsensitive);
 	if (RegexPovRayProgress.indexIn(StdErr) == 0)
@@ -240,7 +240,7 @@ void lcRenderDialog::Update()
 
 	if (mProcess->state() == QProcess::NotRunning)
 	{
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 		QByteArray Output = mProcess->readAllStandardOutput();
 		mImage = QImage::fromData(Output);
 #endif
