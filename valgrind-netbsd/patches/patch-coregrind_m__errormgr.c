$NetBSD$

--- coregrind/m_errormgr.c.orig	2018-08-17 15:58:00.000000000 +0000
+++ coregrind/m_errormgr.c
@@ -584,6 +584,7 @@ static void pp_Error ( const Error* err,
 {
    /* If this fails, you probably specified your tool's method
       dictionary incorrectly. */
+   VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    vg_assert(VG_(needs).tool_errors);
 
    if (xml) {
@@ -642,6 +643,7 @@ static void pp_Error ( const Error* err,
    }
 
    do_actions_on_error(err, allow_db_attach);
+   VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 
@@ -685,6 +687,7 @@ void VG_(maybe_record_error) ( ThreadId 
                                ErrorKind ekind, Addr a, 
                                const HChar* s, void* extra )
 {
+VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
           Error  err;
           Error* p;
           Error* p_prev;
@@ -729,13 +732,16 @@ void VG_(maybe_record_error) ( ThreadId 
          VG_(umsg)("\n");
          stopping_message = True;
       }
+VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
       return;
    }
 
    /* Ignore it if error acquisition is disabled for this thread. */
    { ThreadState* tst = VG_(get_ThreadState)(tid);
-     if (tst->err_disablement_level > 0)
+     if (tst->err_disablement_level > 0) {
+VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
         return;
+ }
    }
 
    /* After M_COLLECT_ERRORS_SLOWLY_AFTER different errors have
@@ -842,18 +848,22 @@ void VG_(maybe_record_error) ( ThreadId 
    p->next = errors;
    p->supp = is_suppressible_error(&err);
    errors  = p;
+VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (p->supp == NULL) {
       /* update stats */
       n_err_contexts++;
       n_errs_found++;
       n_errs_shown++;
       /* Actually show the error; more complex than you might think. */
+VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
       pp_Error( p, /*allow_db_attach*/True, VG_(clo_xml) );
+VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    } else {
       n_supp_contexts++;
       n_errs_suppressed++;
       p->supp->count++;
    }
+VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 /* Second top-level entry point to the error management subsystem, for
