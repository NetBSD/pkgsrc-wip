$NetBSD$

Support FreeBSD and NetBSD.

--- src/helper/UserSession.cpp.orig	2019-03-09 18:26:56.000000000 +0000
+++ src/helper/UserSession.cpp
@@ -33,6 +33,9 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <sched.h>
+#if defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
+#include <login_cap.h>
+#endif /* defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) */
 
 namespace SDDM {
     UserSession::UserSession(HelperApp *parent)
@@ -130,6 +133,21 @@ namespace SDDM {
 
         // switch user
         const QByteArray username = qobject_cast<HelperApp*>(parent())->user().toLocal8Bit();
+#if defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
+        struct passwd *pw = getpwnam(username.constData());
+        /* execve() uses the environment prepared in Backend::openSession(),
+           therefore environment variables which are set here are ignored. */
+        if (setusercontext(NULL, pw, pw->pw_uid, LOGIN_SETALL) != 0) {
+            qCritical() << "setusercontext(NULL, *, " << pw->pw_uid << ", LOGIN_SETALL) failed for user: " << username;
+            exit(Auth::HELPER_OTHER_ERROR);
+        }
+        if (chdir(pw->pw_dir) != 0) {
+            qCritical() << "chdir(" << pw->pw_dir << ") failed for user: " << username;
+            qCritical() << "verify directory exist and has sufficient permissions";
+            exit(Auth::HELPER_OTHER_ERROR);
+        }
+        const QString homeDir = QString::fromLocal8Bit(pw->pw_dir);
+#else /* defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) */
         struct passwd pw;
         struct passwd *rpw;
         long bufsize = sysconf(_SC_GETPW_R_SIZE_MAX);
@@ -221,6 +239,7 @@ namespace SDDM {
             exit(Auth::HELPER_OTHER_ERROR);
         }
         const QString homeDir = QString::fromLocal8Bit(pw.pw_dir);
+#endif /* defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) */
 
         //we cannot use setStandardError file as this code is run in the child process
         //we want to redirect after we setuid so that the log file is owned by the user
