$NetBSD$

--- src/VBox/Debugger/DBGCCommands.cpp.orig	2016-03-04 19:25:46.000000000 +0000
+++ src/VBox/Debugger/DBGCCommands.cpp
@@ -1847,7 +1847,7 @@ static DECLCALLBACK(int) dbgcCmdWriteCor
 /**
  * @callback_method_impl{FNDBGCFUNC, The randu32() function implementation.}
  */
-static DECLCALLBACK(int) dbgcFuncRandU32(PCDBGCFUNC pFunc, PDBGCCMDHLP pCmdHlp, PVM pUVM, PCDBGCVAR paArgs, uint32_t cArgs,
+static DECLCALLBACK(int) dbgcFuncRandU32(PCDBGCFUNC pFunc, PDBGCCMDHLP pCmdHlp, vbox_PVM pUVM, PCDBGCVAR paArgs, uint32_t cArgs,
                                          PDBGCVAR pResult)
 {
     AssertReturn(cArgs == 0, VERR_DBGC_PARSE_BUG);
@@ -1856,4 +1856,3 @@ static DECLCALLBACK(int) dbgcFuncRandU32
     NOREF(pFunc); NOREF(pCmdHlp); NOREF(pUVM); NOREF(paArgs);
     return VINF_SUCCESS;
 }
-
