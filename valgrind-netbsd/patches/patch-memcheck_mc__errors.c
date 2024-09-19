$NetBSD$

--- memcheck/mc_errors.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ memcheck/mc_errors.c
@@ -202,6 +202,7 @@ struct _MC_Error {
    Memcheck, we don't use.  Hence a no-op.
 */
 void MC_(before_pp_Error) ( const Error* err ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 /* Do a printf-style operation on either the XML or normal output
@@ -209,6 +210,7 @@ void MC_(before_pp_Error) ( const Error*
 */
 static void emit_WRK ( const HChar* format, va_list vargs )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (VG_(clo_xml)) {
       VG_(vprintf_xml)(format, vargs);
    } else {
@@ -218,6 +220,7 @@ static void emit_WRK ( const HChar* form
 static void emit ( const HChar* format, ... ) PRINTF_CHECK(1, 2);
 static void emit ( const HChar* format, ... )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    va_list vargs;
    va_start(vargs, format);
    emit_WRK(format, vargs);
@@ -227,6 +230,7 @@ static void emit ( const HChar* format, 
 
 static const HChar* str_leak_lossmode ( Reachedness lossmode )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    const HChar *loss = "?";
    switch (lossmode) {
       case Unreached:    loss = "definitely lost"; break;
@@ -239,6 +243,7 @@ static const HChar* str_leak_lossmode ( 
 
 static const HChar* xml_leak_kind ( Reachedness lossmode )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    const HChar *loss = "?";
    switch (lossmode) {
       case Unreached:    loss = "Leak_DefinitelyLost"; break;
@@ -254,6 +259,7 @@ const HChar* MC_(parse_leak_kinds_tokens
 
 UInt MC_(all_Reachedness)(void)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    static UInt all;
 
    if (all == 0) {
@@ -270,6 +276,7 @@ UInt MC_(all_Reachedness)(void)
 
 static const HChar* pp_Reachedness_for_leak_kinds(Reachedness r)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    switch(r) {
    case Reachable:    return "reachable";
    case Possible:     return "possible";
@@ -281,6 +288,7 @@ static const HChar* pp_Reachedness_for_l
 
 static void mc_pp_origin ( ExeContext* ec, UInt okind )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    const HChar* src = NULL;
    tl_assert(ec);
 
@@ -306,6 +314,7 @@ HChar * MC_(snprintf_delta) (HChar * buf
                              SizeT current_val, SizeT old_val, 
                              LeakCheckDeltaMode delta_mode)
 {
+//VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    // Make sure the buffer size is large enough. With old_val == 0 and
    // current_val == ULLONG_MAX the delta including inserted commas is:
    // 18,446,744,073,709,551,615
@@ -325,6 +334,7 @@ HChar * MC_(snprintf_delta) (HChar * buf
 static void pp_LossRecord(UInt n_this_record, UInt n_total_records,
                           LossRecord* lr, Bool xml)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    // char arrays to produce the indication of increase/decrease in case
    // of delta_mode != LCD_Any
    HChar d_bytes[31];
@@ -408,14 +418,18 @@ static void pp_LossRecord(UInt n_this_re
 void MC_(pp_LossRecord)(UInt n_this_record, UInt n_total_records,
                         LossRecord* l)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    pp_LossRecord (n_this_record, n_total_records, l, /* xml */ False);
 }
 
 void MC_(pp_Error) ( const Error* err )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    const Bool xml  = VG_(clo_xml); /* a shorthand */
    MC_Error* extra = VG_(get_error_extra)(err);
 
+   VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
+
    switch (VG_(get_error_kind)(err)) {
       case Err_CoreMem:
          /* What the hell *is* a CoreMemError? jrs 2005-May-18 */
@@ -711,6 +725,7 @@ void MC_(pp_Error) ( const Error* err )
                      VG_(get_error_kind)(err));
          VG_(tool_panic)("unknown error code in mc_pp_Error)");
    }
+   VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 /*------------------------------------------------------------*/
@@ -725,6 +740,7 @@ void MC_(pp_Error) ( const Error* err )
    for the --workaround-gcc296-bugs kludge. */
 static Bool is_just_below_ESP( Addr esp, Addr aa )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    esp -= VG_STACK_REDZONE_SZB;
    if (esp > aa && (esp - aa) <= VG_GCC296_BUG_STACK_SLOP)
       return True;
@@ -737,9 +753,12 @@ static Bool is_just_below_ESP( Addr esp,
 void MC_(record_address_error) ( ThreadId tid, Addr a, Int szB,
                                  Bool isWrite )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Error extra;
    Bool     just_below_esp;
 
+VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
+
    if (MC_(in_ignored_range)(a)) 
       return;
 
@@ -764,11 +783,14 @@ void MC_(record_address_error) ( ThreadI
    extra.Err.Addr.szB       = szB;
    extra.Err.Addr.maybe_gcc = just_below_esp;
    extra.Err.Addr.ai.tag    = Addr_Undescribed;
+VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    VG_(maybe_record_error)( tid, Err_Addr, a, /*s*/NULL, &extra );
+VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 void MC_(record_value_error) ( ThreadId tid, Int szB, UInt otag )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Error extra;
    tl_assert( MC_(clo_mc_level) >= 2 );
    if (otag > 0)
@@ -781,6 +803,7 @@ void MC_(record_value_error) ( ThreadId 
 
 void MC_(record_cond_error) ( ThreadId tid, UInt otag )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Error extra;
    tl_assert( MC_(clo_mc_level) >= 2 );
    if (otag > 0)
@@ -795,11 +818,13 @@ void MC_(record_cond_error) ( ThreadId t
 /* This is for memory errors in signal-related memory. */
 void MC_(record_core_mem_error) ( ThreadId tid, const HChar* msg )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    VG_(maybe_record_error)( tid, Err_CoreMem, /*addr*/0, msg, /*extra*/NULL );
 }
 
 void MC_(record_regparam_error) ( ThreadId tid, const HChar* msg, UInt otag )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Error extra;
    tl_assert(VG_INVALID_THREADID != tid);
    if (otag > 0)
@@ -812,6 +837,7 @@ void MC_(record_regparam_error) ( Thread
 void MC_(record_memparam_error) ( ThreadId tid, Addr a, 
                                   Bool isAddrErr, const HChar* msg, UInt otag )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Error extra;
    tl_assert(VG_INVALID_THREADID != tid);
    if (!isAddrErr) 
@@ -829,6 +855,7 @@ void MC_(record_memparam_error) ( Thread
 
 void MC_(record_jump_error) ( ThreadId tid, Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Error extra;
    tl_assert(VG_INVALID_THREADID != tid);
    extra.Err.Jump.ai.tag = Addr_Undescribed;
@@ -837,6 +864,7 @@ void MC_(record_jump_error) ( ThreadId t
 
 void MC_(record_free_error) ( ThreadId tid, Addr a ) 
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Error extra;
    tl_assert(VG_INVALID_THREADID != tid);
    extra.Err.Free.ai.tag = Addr_Undescribed;
@@ -845,6 +873,7 @@ void MC_(record_free_error) ( ThreadId t
 
 void MC_(record_freemismatch_error) ( ThreadId tid, MC_Chunk* mc )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Error extra;
    AddrInfo* ai = &extra.Err.FreeMismatch.ai;
    tl_assert(VG_INVALID_THREADID != tid);
@@ -862,6 +891,7 @@ void MC_(record_freemismatch_error) ( Th
 
 void MC_(record_illegal_mempool_error) ( ThreadId tid, Addr a ) 
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Error extra;
    tl_assert(VG_INVALID_THREADID != tid);
    extra.Err.IllegalMempool.ai.tag = Addr_Undescribed;
@@ -871,6 +901,7 @@ void MC_(record_illegal_mempool_error) (
 void MC_(record_overlap_error) ( ThreadId tid, const HChar* function,
                                  Addr src, Addr dst, SizeT szB )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Error extra;
    tl_assert(VG_INVALID_THREADID != tid);
    extra.Err.Overlap.src = src;
@@ -884,6 +915,7 @@ Bool MC_(record_leak_error) ( ThreadId t
                               UInt n_total_records, LossRecord* lr,
                               Bool print_record, Bool count_error )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Error extra;
    extra.Err.Leak.n_this_record   = n_this_record;
    extra.Err.Leak.n_total_records = n_total_records;
@@ -897,6 +929,7 @@ Bool MC_(record_leak_error) ( ThreadId t
 Bool MC_(record_fishy_value_error) ( ThreadId tid, const HChar *function_name,
                                      const HChar *argument_name, SizeT value)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Error extra;
 
    tl_assert(VG_INVALID_THREADID != tid);
@@ -916,6 +949,7 @@ Bool MC_(record_fishy_value_error) ( Thr
 void MC_(record_user_error) ( ThreadId tid, Addr a,
                               Bool isAddrErr, UInt otag )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Error extra;
    if (otag != 0) {
       tl_assert(!isAddrErr);
@@ -934,6 +968,7 @@ void MC_(record_user_error) ( ThreadId t
 
 Bool MC_(is_mempool_block)(MC_Chunk* mc_search)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Mempool* mp;
 
    if (!MC_(mempool_list))
@@ -965,6 +1000,7 @@ Bool MC_(is_mempool_block)(MC_Chunk* mc_
    are allowed to be different.  */
 Bool MC_(eq_Error) ( VgRes res, const Error* e1, const Error* e2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Error* extra1 = VG_(get_error_extra)(e1);
    MC_Error* extra2 = VG_(get_error_extra)(e2);
 
@@ -1035,12 +1071,14 @@ Bool MC_(eq_Error) ( VgRes res, const Er
 static
 Bool addr_is_in_MC_Chunk_default_REDZONE_SZB(MC_Chunk* mc, Addr a)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return VG_(addr_is_in_block)( a, mc->data, mc->szB,
                                  MC_(Malloc_Redzone_SzB) );
 }
 static
 Bool addr_is_in_MC_Chunk_with_REDZONE_SZB(MC_Chunk* mc, Addr a, SizeT rzB)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return VG_(addr_is_in_block)( a, mc->data, mc->szB,
                                  rzB );
 }
@@ -1055,6 +1093,7 @@ static Bool mempool_block_maybe_describe
    putting the result in ai. */
 static void describe_addr ( DiEpoch ep, Addr a, /*OUT*/AddrInfo* ai )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Chunk*  mc;
 
    tl_assert(Addr_Undescribed == ai->tag);
@@ -1126,6 +1165,7 @@ static void describe_addr ( DiEpoch ep, 
 
 void MC_(pp_describe_addr) ( DiEpoch ep, Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    AddrInfo ai;
 
    ai.tag = Addr_Undescribed;
@@ -1139,6 +1179,7 @@ void MC_(pp_describe_addr) ( DiEpoch ep,
 static void update_origin ( /*OUT*/ExeContext** origin_ec,
                             UInt otag )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt ecu = otag & ~3;
    *origin_ec = NULL;
    if (VG_(is_plausible_ECU)(ecu)) {
@@ -1149,6 +1190,7 @@ static void update_origin ( /*OUT*/ExeCo
 /* Updates the copy with address info if necessary (but not for all errors). */
 UInt MC_(update_Error_extra)( const Error* err )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Error* extra = VG_(get_error_extra)(err);
    DiEpoch   ep    = VG_(get_ExeContext_epoch)(VG_(get_error_where)(err));
 
@@ -1232,6 +1274,7 @@ UInt MC_(update_Error_extra)( const Erro
 static Bool client_block_maybe_describe( Addr a,
                                          /*OUT*/AddrInfo* ai )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UWord      i;
    CGenBlock* cgbs = NULL;
    UWord      cgb_used = 0;
@@ -1264,6 +1307,7 @@ static Bool client_block_maybe_describe(
 static Bool mempool_block_maybe_describe( Addr a, Bool is_metapool,
                                           /*OUT*/AddrInfo* ai )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Mempool* mp;
    tl_assert( MC_(mempool_list) );
 
@@ -1321,6 +1365,7 @@ typedef 
 
 Bool MC_(is_recognised_suppression) ( const HChar* name, Supp* su )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SuppKind skind;
 
    if      (VG_STREQ(name, "Param"))   skind = ParamSupp;
@@ -1375,6 +1420,7 @@ typedef struct {
 Bool MC_(read_extra_suppression_info) ( Int fd, HChar** bufpp,
                                         SizeT* nBufp, Int* lineno, Supp *su )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Bool eof;
    Int i;
 
@@ -1438,6 +1484,7 @@ Bool MC_(read_extra_suppression_info) ( 
 
 Bool MC_(error_matches_suppression) ( const Error* err, const Supp* su )
 {
+//VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int       su_szB;
    MC_Error* extra = VG_(get_error_extra)(err);
    ErrorKind ekind = VG_(get_error_kind)(err);
@@ -1524,6 +1571,7 @@ Bool MC_(error_matches_suppression) ( co
 
 const HChar* MC_(get_error_name) ( const Error* err )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    switch (VG_(get_error_kind)(err)) {
    case Err_RegParam:       return "Param";
    case Err_MemParam:       return "Param";
@@ -1568,6 +1616,7 @@ const HChar* MC_(get_error_name) ( const
 SizeT MC_(get_extra_suppression_info) ( const Error* err,
                                         /*OUT*/HChar* buf, Int nBuf )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    ErrorKind ekind = VG_(get_error_kind)(err);
    tl_assert(buf);
    tl_assert(nBuf >= 1);
@@ -1594,6 +1643,7 @@ SizeT MC_(get_extra_suppression_info) ( 
 SizeT MC_(print_extra_suppression_use) ( const Supp *su,
                                          /*OUT*/HChar *buf, Int nBuf )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(nBuf >= 1);
 
    if (VG_(get_supp_kind)(su) == LeakSupp) {
@@ -1614,6 +1664,7 @@ SizeT MC_(print_extra_suppression_use) (
 
 void MC_(update_extra_suppression_use) ( const Error* err, const Supp* su)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (VG_(get_supp_kind)(su) == LeakSupp) {
       MC_LeakSuppExtra *lse = (MC_LeakSuppExtra*) VG_(get_supp_extra) (su);
       MC_Error* extra = VG_(get_error_extra)(err);
