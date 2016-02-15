$NetBSD$

--- src/md/enc/metamodelrw.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/md/enc/metamodelrw.cpp
@@ -5968,7 +5968,7 @@ CMiniMdRW::FixParamSequence(
             IfFailRet(GetParamPtrRecord(endRid - 1, &pNewParamPtr));
         }
         int cbCopy = m_TableDefs[TBL_ParamPtr].m_cbRec;
-        void * pbBackup = _alloca(cbCopy);
+        void * pbBackup = Alloca(cbCopy);
         memcpy(pbBackup, pNewParamPtr, cbCopy);
         
         IfFailRet(getEndParamListOfMethod(md, &endRid));
