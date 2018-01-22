$NetBSD$

--- src/ProcessInfo.cpp.orig	2018-01-08 05:04:18.000000000 +0000
+++ src/ProcessInfo.cpp
@@ -982,6 +982,163 @@ private:
         return false;
     }
 };
+#elif defined(Q_OS_NETBSD)
+class NetBSDProcessInfo : public UnixProcessInfo
+{
+public:
+    NetBSDProcessInfo(int aPid, const QString &titleFormat) :
+        UnixProcessInfo(aPid, titleFormat)
+    {
+    }
+
+private:
+    bool readProcInfo(int aPid) Q_DECL_OVERRIDE
+    {
+        // indicies of various fields within the process status file which
+        // contain various information about the process
+        const int PARENT_PID_FIELD = 2;
+        const int PROCESS_NAME_FIELD = 0;
+        const int GROUP_PROCESS_FIELD = 3;
+        const int UID_PROCESS_FIELD = 11;
+
+        QString parentPidString;
+        QString processNameString;
+        QString foregroundPidString;
+        QString uidString;
+
+        // read process status file ( /proc/<pid/status )
+        //
+        // the expected file format is a list of fields separated by spaces, using
+        // parenthesies to escape fields such as the process name which may itself contain
+        // spaces:
+        //
+        // FIELD FIELD (FIELD WITH SPACES) FIELD FIELD
+        //
+        QFile processInfo( QStringLiteral("/proc/%1/status").arg(aPid) );
+        if ( processInfo.open(QIODevice::ReadOnly) )
+        {
+            QTextStream stream(&processInfo);
+            QString data = stream.readAll();
+
+            int stack = 0;
+            int field = 0;
+            int pos = 0;
+
+            while (pos < data.count()) {
+                QChar c = data[pos];
+
+                if ( c == QLatin1Char('(')) {
+                    stack++;
+                } else if ( c == QLatin1Char(')')) {
+                    stack--;
+                } else if ( stack == 0 && c == QLatin1Char(' ')) {
+                    field++;
+                } else {
+                    switch ( field )
+                    {
+                        case PARENT_PID_FIELD:
+                            parentPidString.append(c);
+                            break;
+                        case PROCESS_NAME_FIELD:
+                            processNameString.append(c);
+                            break;
+                        case GROUP_PROCESS_FIELD:
+                            foregroundPidString.append(c);
+                            break;
+                        case UID_PROCESS_FIELD:
+                            uidString.append(c);
+                            break;
+                    }
+                }
+
+                pos++;
+            }
+        }
+        else
+        {
+            setFileError( processInfo.error() );
+            return false;
+        }
+
+        // check that data was read successfully
+        bool ok = false;
+
+        // uid string must be less than 5 chars (uint)
+        if (uidString.size() > 5)
+            uidString.clear();
+
+        int uid = uidString.toInt(&ok);
+        if (ok)
+            setUserId(uid);
+        readUserName();
+
+        int foregroundPid = foregroundPidString.toInt(&ok);
+        if (ok)
+            setForegroundPid(foregroundPid);
+
+        int parentPid = parentPidString.toInt(&ok);
+        if (ok)
+            setParentPid(parentPid);
+
+        if (!processNameString.isEmpty())
+            setName(processNameString);
+
+        // update object state
+        setPid(aPid);
+
+        return ok;
+    }
+
+    bool readArguments(int aPid) Q_DECL_OVERRIDE
+    {
+        // read command-line arguments file found at /proc/<pid>/cmdline
+        // the expected format is a list of strings delimited by null characters,
+        // and ending in a double null character pair.
+
+        QFile argumentsFile( QStringLiteral("/proc/%1/cmdline").arg(aPid) );
+        if ( argumentsFile.open(QIODevice::ReadOnly) )
+        {
+            QTextStream stream(&argumentsFile);
+            QString data = stream.readAll();
+
+            QStringList argList = data.split( QLatin1Char('\0') );
+
+            foreach ( const QString &entry , argList )
+            {
+                if (!entry.isEmpty())
+                    addArgument(entry);
+            }
+        }
+        else
+        {
+            setFileError( argumentsFile.error() );
+        }
+
+        return true;
+    }
+
+    bool readCurrentDir(int aPid) Q_DECL_OVERRIDE
+    {
+        QFileInfo info( QStringLiteral("/proc/%1/cwd").arg(aPid) );
+
+        const bool readable = info.isReadable();
+
+        if ( readable && info.isSymLink() )
+        {
+            setCurrentDir( info.symLinkTarget() );
+            return true;
+        }
+        else
+        {
+            if ( !readable )
+                setError( PermissionsError );
+            else
+                setError( UnknownError );
+
+            return false;
+        }
+    }
+} ;
 #endif
 
 SSHProcessInfo::SSHProcessInfo(const ProcessInfo &process) :
@@ -1165,6 +1322,8 @@ ProcessInfo *ProcessInfo::newInstance(in
     info = new LinuxProcessInfo(aPid, titleFormat);
 #elif defined(Q_OS_SOLARIS)
     info = new SolarisProcessInfo(aPid, titleFormat);
+#elif defined(Q_OS_NETBSD)
+    return new NetBSDProcessInfo(aPid, titleFormat);
 #elif defined(Q_OS_MACOS)
     info = new MacProcessInfo(aPid, titleFormat);
 #elif defined(Q_OS_FREEBSD)
