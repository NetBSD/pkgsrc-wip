$NetBSD$

Avoid deprecated Tcl.

--- platform/wish/unixMain.cc.orig	2015-10-08 15:38:24.000000000 +0000
+++ platform/wish/unixMain.cc
@@ -157,7 +157,7 @@ main(int argc, char **argv)
 
     if (Tk_ParseArgv(interp, (Tk_Window) NULL, &argc, CONST_CAST(CONST_FOR_ARGV char**,argv), argTable, 0)
 	    != TCL_OK) {
-	fprintf(stdout, "w %s\n.\n", interp->result);
+	fprintf(stdout, "w %s\n.\n", Tcl_GetStringResult(interp));
 	fflush(stdout); /* added mm */
 	exit(1);
     }
@@ -192,7 +192,7 @@ main(int argc, char **argv)
 #ifdef RS
     mainWindow = Tk_CreateMainWindow(interp, display, name, "Tk");
     if (mainWindow == NULL) {
-	fprintf(stdout, "w %s\n.\n", interp->result);
+	fprintf(stdout, "w %s\n.\n", Tcl_GetStringResult(interp));
 	fprintf(stdout, "s stop\n");
 	fflush(stdout); /* added mm */
 	exit(1);
@@ -232,7 +232,7 @@ main(int argc, char **argv)
      */
 
     if (Tcl_AppInit(interp) != TCL_OK) {
-	fprintf(stdout, "w Tcl_AppInit failed: %s\n.\n", interp->result);
+	fprintf(stdout, "w Tcl_AppInit failed: %s\n.\n", Tcl_GetStringResult(interp));
 	fflush(stdout); /* added mm */
     }
 
@@ -243,7 +243,7 @@ main(int argc, char **argv)
     if (geometry != NULL) {
 	code = Tcl_VarEval(interp, "wm geometry . ", geometry, (char *) NULL);
 	if (code != TCL_OK) {
-	    fprintf(stdout, "w %s\n.\n", interp->result);
+	    fprintf(stdout, "w %s\n.\n", Tcl_GetStringResult(interp));
 	    fflush(stdout); /* added mm */
 	}
     }
@@ -251,7 +251,7 @@ main(int argc, char **argv)
     /* mm: do not show the main window */
     code = Tcl_Eval(interp, "wm withdraw . ");
     if (code != TCL_OK) {
-      fprintf(stdout, "w %s\n.\n", interp->result);
+      fprintf(stdout, "w %s\n.\n", Tcl_GetStringResult(interp));
       fflush(stdout); /* added mm */
     }
 
@@ -301,7 +301,7 @@ main(int argc, char **argv)
 error:
     msg = CONST_CAST(char*,Tcl_GetVar(interp, CONST_CAST(CONST char*,"errorInfo"), TCL_GLOBAL_ONLY));
     if (msg == NULL) {
-	msg = interp->result;
+	msg = CONST_CAST(char*,Tcl_GetStringResult(interp));
     }
     fprintf(stdout, "w %s\n.\n", msg);
     fflush(stdout);  /* added mm */
@@ -380,10 +380,10 @@ StdinProc(ClientData clientData, int mas
     Tk_CreateFileHandler(0, 0, StdinProc, (ClientData) 0);
     code = Tcl_Eval(interp, cmd);
     Tk_CreateFileHandler(0, TK_READABLE, StdinProc, (ClientData) 0);
-    if (*interp->result != 0) {
+    if (Tcl_GetStringResult(interp) != 0) {
 	if ((code != TCL_OK) || (tty)) {
 	  fprintf(stdout,"w --- %s", cmd);
-	  fprintf(stdout,"---  %s\n---\n.\n", interp->result);
+	  fprintf(stdout,"---  %s\n---\n.\n", Tcl_GetStringResult(interp));
 	  fflush(stdout); /* by mm */
 	}
     }
@@ -432,7 +432,7 @@ Prompt(Tcl_Interp *interp, int partial)
 	if (code != TCL_OK) {
 	    Tcl_AddErrorInfo(interp,
 		    "\n    (script that generates prompt)");
-	    fprintf(stdout, "w %s\n.\n", interp->result);
+	    fprintf(stdout, "w %s\n.\n", Tcl_GetStringResult(interp));
 	    fflush(stdout); /* added mm */
 	    goto defaultPrompt;
 	}
