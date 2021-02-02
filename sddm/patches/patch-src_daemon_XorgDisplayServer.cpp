$NetBSD$

Patches from Fabian Vogt to retry starting the display server

--- src/daemon/XorgDisplayServer.cpp.orig	2020-11-03 09:49:10.000000000 +0000
+++ src/daemon/XorgDisplayServer.cpp
@@ -118,6 +118,11 @@ namespace SDDM {
         if (m_started)
             return false;
 
+        if (process) {
+            qCritical() << "Tried to start Xorg before previous instance exited";
+            return false;
+        }
+
         // create process
         process = new QProcess(this);
 
@@ -136,106 +141,97 @@ namespace SDDM {
             return false;
         }
 
-        if (daemonApp->testing()) {
-            QStringList args;
-            QDir x11socketDir(QStringLiteral("/tmp/.X11-unix"));
-            int display = 100;
-            while (x11socketDir.exists(QStringLiteral("X%1").arg(display))) {
-                ++display;
-            }
-            m_display = QStringLiteral(":%1").arg(display);
-            args << m_display << QStringLiteral("-auth") << m_authPath << QStringLiteral("-br") << QStringLiteral("-noreset") << QStringLiteral("-screen") << QStringLiteral("800x600");
-            process->start(mainConfig.X11.XephyrPath.get(), args);
-
-
-            // wait for display server to start
-            if (!process->waitForStarted()) {
-                // log message
-                qCritical() << "Failed to start display server process.";
+        // set process environment
+        QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
+        env.insert(QStringLiteral("XCURSOR_THEME"), mainConfig.Theme.CursorTheme.get());
+        process->setProcessEnvironment(env);
 
-                // return fail
-                return false;
-            }
-            emit started();
-        } else {
-            // set process environment
-            QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
-            env.insert(QStringLiteral("XCURSOR_THEME"), mainConfig.Theme.CursorTheme.get());
-            process->setProcessEnvironment(env);
-
-            //create pipe for communicating with X server
-            //0 == read from X, 1== write to from X
-            int pipeFds[2];
-            if (pipe(pipeFds) != 0) {
-                qCritical("Could not create pipe to start X server");
-            }
+        //create pipe for communicating with X server
+        //0 == read from X, 1== write to from X
+        int pipeFds[2];
+        if (pipe(pipeFds) != 0) {
+            qCritical("Could not create pipe to start X server");
+        }
 
-            // start display server
-            QStringList args = mainConfig.X11.ServerArguments.get().split(QLatin1Char(' '), QString::SkipEmptyParts);
-            args << QStringLiteral("-auth") << m_authPath
+        // start display server
+        QStringList args;
+        if (!daemonApp->testing()) {
+            process->setProgram(mainConfig.X11.ServerPath.get());
+            args << mainConfig.X11.ServerArguments.get().split(QLatin1Char(' '), QString::SkipEmptyParts)
                  << QStringLiteral("-background") << QStringLiteral("none")
-                 << QStringLiteral("-noreset")
-                 << QStringLiteral("-displayfd") << QString::number(pipeFds[1])
                  << QStringLiteral("-seat") << displayPtr()->seat()->name();
 
             if (displayPtr()->seat()->name() == QLatin1String("seat0")) {
                 args << QStringLiteral("vt%1").arg(displayPtr()->terminalId());
             }
-            qDebug() << "Running:"
-                     << qPrintable(mainConfig.X11.ServerPath.get())
-                     << qPrintable(args.join(QLatin1Char(' ')));
-            process->start(mainConfig.X11.ServerPath.get(), args);
-
-            // wait for display server to start
-            if (!process->waitForStarted()) {
-                // log message
-                qCritical() << "Failed to start display server process.";
-
-                // return fail
-                close(pipeFds[0]);
-                return false;
-            }
+        } else {
+            process->setProgram(mainConfig.X11.XephyrPath.get());
+            args << QStringLiteral("-br")
+                 << QStringLiteral("-screen") << QStringLiteral("800x600");
+        }
 
-            // close the other side of pipe in our process, otherwise reading
-            // from it may stuck even X server exit.
-            close(pipeFds[1]);
+        args << QStringLiteral("-auth") << m_authPath
+             << QStringLiteral("-noreset")
+             << QStringLiteral("-displayfd") << QString::number(pipeFds[1]);
+
+        process->setArguments(args);
+        qDebug() << "Running:"
+            << qPrintable(process->program())
+            << qPrintable(process->arguments().join(QLatin1Char(' ')));
+        process->start();
+
+        // wait for display server to start
+        if (!process->waitForStarted()) {
+            // log message
+            qCritical() << "Failed to start display server process.";
 
-            QFile readPipe;
+            // return fail
+            close(pipeFds[0]);
+            return false;
+        }
 
-            if (!readPipe.open(pipeFds[0], QIODevice::ReadOnly)) {
-                qCritical("Failed to open pipe to start X Server");
+        // close the other side of pipe in our process, otherwise reading
+        // from it may stuck even X server exit.
+        close(pipeFds[1]);
 
-                close(pipeFds[0]);
-                return false;
-            }
-            QByteArray displayNumber = readPipe.readLine();
-            if (displayNumber.size() < 2) {
-                // X server gave nothing (or a whitespace).
-                qCritical("Failed to read display number from pipe");
+        QFile readPipe;
 
-                close(pipeFds[0]);
-                return false;
-            }
-            displayNumber.prepend(QByteArray(":"));
-            displayNumber.remove(displayNumber.size() -1, 1); // trim trailing whitespace
-            m_display = QString::fromLocal8Bit(displayNumber);
+        if (!readPipe.open(pipeFds[0], QIODevice::ReadOnly)) {
+            qCritical("Failed to open pipe to start X Server");
 
-            // close our pipe
             close(pipeFds[0]);
+            stop();
+            return false;
+        }
+        QByteArray displayNumber = readPipe.readLine();
+        if (displayNumber.size() < 2) {
+            // X server gave nothing (or a whitespace).
+            qCritical("Failed to read display number from pipe");
 
-            emit started();
+            close(pipeFds[0]);
+            stop();
+            return false;
         }
+        displayNumber.prepend(QByteArray(":"));
+        displayNumber.remove(displayNumber.size() -1, 1); // trim trailing whitespace
+        m_display = QString::fromLocal8Bit(displayNumber);
+
+        // close our pipe
+        close(pipeFds[0]);
 
         // The file is also used by the greeter, which does care about the
         // display number. Write the proper entry, if it's different.
         if(m_display != QStringLiteral(":0")) {
             if(!addCookie(m_authPath)) {
                 qCritical() << "Failed to write xauth file";
+                stop();
                 return false;
             }
         }
         changeOwner(m_authPath);
 
+        emit started();
+
         // set flag
         m_started = true;
 
@@ -244,8 +240,7 @@ namespace SDDM {
     }
 
     void XorgDisplayServer::stop() {
-        // check flag
-        if (!m_started)
+        if (!process)
             return;
 
         // log message
@@ -260,6 +255,12 @@ namespace SDDM {
     }
 
     void XorgDisplayServer::finished() {
+        // clean up
+        if (process) {
+            process->deleteLater();
+            process = nullptr;
+        }
+
         // check flag
         if (!m_started)
             return;
@@ -295,10 +296,6 @@ namespace SDDM {
         displayStopScript->deleteLater();
         displayStopScript = nullptr;
 
-        // clean up
-        process->deleteLater();
-        process = nullptr;
-
         // remove authority file
         QFile::remove(m_authPath);
 
