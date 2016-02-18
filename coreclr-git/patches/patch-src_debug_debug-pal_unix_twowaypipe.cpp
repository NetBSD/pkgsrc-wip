$NetBSD$

--- src/debug/debug-pal/unix/twowaypipe.cpp.orig	2016-02-18 21:11:19.000000000 +0000
+++ src/debug/debug-pal/unix/twowaypipe.cpp
@@ -2,22 +2,21 @@
 // The .NET Foundation licenses this file to you under the MIT license.
 // See the LICENSE file in the project root for more information.
 
-#include <pal.h>
-
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <stdio.h>
 #include <limits.h>
-#include <pal_assert.h>
 
+#include "windefs.h"
 #include "twowaypipe.h"
 
 #define PIPE_NAME_FORMAT_STR "/tmp/clr-debug-pipe-%d-%s"
 
 static void GetPipeName(char *name, DWORD id, const char *suffix)
 {
-    int chars = _snprintf(name, PATH_MAX, PIPE_NAME_FORMAT_STR, id, suffix);
+    int chars = snprintf(name, PATH_MAX, PIPE_NAME_FORMAT_STR, id, suffix);
     _ASSERTE(chars > 0 && chars < PATH_MAX);
 }
 
@@ -43,14 +42,15 @@ bool TwoWayPipe::CreateServer(DWORD id)
 
     if (mkfifo(outPipeName, S_IRWXU) == -1)
     {
-        unlink(inPipeName);
+        remove(inPipeName);
         return false;
-    }
+    }    
 
     m_state = Created;
     return true;
 }
 
+
 // Connects to a previously opened server side of the pipe.
 // Id is used to locate the pipe on the machine. 
 // true - success, false - failure (use GetLastError() for more details)
@@ -138,7 +138,6 @@ int TwoWayPipe::Read(void *buffer, DWORD
         {
             break;
         }
-
         buffer = (char*)buffer + bytesRead;
         cb -= bytesRead;
     }
@@ -165,7 +164,6 @@ int TwoWayPipe::Write(const void *data, 
         {
             break;
         }
-
         data = (char*)data + bytesWritten;
         cb -= bytesWritten;
     }
@@ -177,6 +175,7 @@ int TwoWayPipe::Write(const void *data, 
 // true - success, false - failure (use GetLastError() for more details)
 bool TwoWayPipe::Disconnect()
 {
+
     if (m_outboundPipe != INVALID_PIPE && m_outboundPipe != 0)
     {
         close(m_outboundPipe);
@@ -187,19 +186,21 @@ bool TwoWayPipe::Disconnect()
     {
         close(m_inboundPipe);
         m_inboundPipe = INVALID_PIPE;
-    }
+    }    
 
     if (m_state == ServerConnected || m_state == Created)
     {
+
         char inPipeName[PATH_MAX];
         GetPipeName(inPipeName, m_id, "in");
-        unlink(inPipeName);
+        remove(inPipeName);
 
         char outPipeName[PATH_MAX];
         GetPipeName(outPipeName, m_id, "out");
-        unlink(outPipeName);
+        remove(outPipeName);
     }
 
     m_state = NotInitialized;
     return true;
 }
+
