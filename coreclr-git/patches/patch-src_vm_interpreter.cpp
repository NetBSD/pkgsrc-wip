$NetBSD$

--- src/vm/interpreter.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/interpreter.cpp
@@ -1630,7 +1630,7 @@ ARG_SLOT Interpreter::ExecuteMethodWrapp
 #endif
 
     size_t sizeWithGS = GetFrameSize(interpMethInfo) + sizeof(GSCookie);
-    BYTE* frameMemoryGS = static_cast<BYTE*>(_alloca(sizeWithGS));
+    BYTE* frameMemoryGS = static_cast<BYTE*>(Alloca(sizeWithGS));
 
     ARG_SLOT retVal = 0;
     unsigned jmpCallToken = 0;
@@ -5965,7 +5965,7 @@ void Interpreter::NewObj()
             assert(m_curStackHt >= dwNumArgs);
             m_curStackHt -= dwNumArgs;
 
-            INT32* args = (INT32*)_alloca(dwNumArgs * sizeof(INT32));
+            INT32* args = (INT32*)Alloca(dwNumArgs * sizeof(INT32));
 
             unsigned dwArg;
             for (dwArg = 0; dwArg < dwNumArgs; dwArg++)
@@ -9381,13 +9381,13 @@ void Interpreter::DoCallWork(bool virtua
     }
     else
     {
-        args = (ARG_SLOT*)_alloca(totalArgSlots * sizeof(ARG_SLOT));
+        args = (ARG_SLOT*)Alloca(totalArgSlots * sizeof(ARG_SLOT));
 #if defined(_ARM_)
         // The HFA return buffer, if any, is assumed to be at a negative
         // offset from the IL arg pointer, so adjust that pointer upward.
         args = args + HFAReturnArgSlots;
 #endif // defined(_ARM_)
-        argTypes = (InterpreterType*)_alloca(nSlots * sizeof(InterpreterType));
+        argTypes = (InterpreterType*)Alloca(nSlots * sizeof(InterpreterType));
     }
     // Make sure that we don't scan any of these until we overwrite them with
     // the real types of the arguments.
@@ -9647,7 +9647,7 @@ void Interpreter::DoCallWork(bool virtua
 #ifdef ENREGISTERED_RETURNTYPE_MAXSIZE
                 retBuffSize = max(retTypeSz, ENREGISTERED_RETURNTYPE_MAXSIZE);
 #endif // ENREGISTERED_RETURNTYPE_MAXSIZE
-                pLargeStructRetVal = (BYTE*)_alloca(retBuffSize);
+                pLargeStructRetVal = (BYTE*)Alloca(retBuffSize);
                 // Clear this in case a GC happens.
                 for (unsigned i = 0; i < retTypeSz; i++) pLargeStructRetVal[i] = 0;
                 // Register this as location needing GC.
@@ -10120,8 +10120,8 @@ void Interpreter::CallI()
     }
     else
     {
-        args = (ARG_SLOT*)_alloca(nSlots * sizeof(ARG_SLOT));
-        argTypes = (InterpreterType*)_alloca(nSlots * sizeof(InterpreterType));
+        args = (ARG_SLOT*)Alloca(nSlots * sizeof(ARG_SLOT));
+        argTypes = (InterpreterType*)Alloca(nSlots * sizeof(InterpreterType));
     }
     // Make sure that we don't scan any of these until we overwrite them with
     // the real types of the arguments.
@@ -10206,7 +10206,7 @@ void Interpreter::CallI()
 #ifdef ENREGISTERED_RETURNTYPE_MAXSIZE
                 retBuffSize = max(retTypeSz, ENREGISTERED_RETURNTYPE_MAXSIZE);
 #endif // ENREGISTERED_RETURNTYPE_MAXSIZE
-                pLargeStructRetVal = (BYTE*)_alloca(retBuffSize);
+                pLargeStructRetVal = (BYTE*)Alloca(retBuffSize);
 
                 // Clear this in case a GC happens.
                 for (unsigned i = 0; i < retTypeSz; i++)
@@ -10716,7 +10716,7 @@ void Interpreter::VerificationError(cons
     // TODO: Should raise an exception eventually; for now:
     const char* const msgPrefix = "Verification Error: ";
     size_t len = strlen(msgPrefix) + strlen(msg) + 1;
-    char* msgFinal = (char*)_alloca(len);
+    char* msgFinal = (char*)Alloca(len);
     strcpy_s(msgFinal, len, msgPrefix);
     strcat_s(msgFinal, len, msg);
     _ASSERTE_MSG(false, msgFinal);
