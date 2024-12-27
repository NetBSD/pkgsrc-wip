$NetBSD$

The code mixes C++ and C (math.h), ensure that isnan resolves correctly.

--- code/fgame/scriptthread.cpp.orig	2024-12-27 08:39:31.399112650 +0000
+++ code/fgame/scriptthread.cpp
@@ -55,6 +55,8 @@ Foundation, Inc., 51 Franklin St, Fifth 
 
 #define scriptfiles sv_scriptfiles
 
+using std::isnan;
+
 Event EV_ScriptThread_GetCvar
 (
     "getcvar",
@@ -7049,4 +7051,4 @@ void ScriptThread::TraceDetails(Event *e
     array.setArrayAtRef(entityIndex, entityValue);
 
     ev->AddValue(array);
-}
\ No newline at end of file
+}
