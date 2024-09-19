$NetBSD$

--- memcheck/mc_leakcheck.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ memcheck/mc_leakcheck.c
@@ -251,6 +251,7 @@
 // Compare the MC_Chunks by 'data' (i.e. the address of the block).
 static Int compare_MC_Chunks(const void* n1, const void* n2)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    const MC_Chunk* mc1 = *(const MC_Chunk *const *)n1;
    const MC_Chunk* mc2 = *(const MC_Chunk *const *)n2;
    if (mc1->data < mc2->data) return -1;
@@ -266,6 +267,7 @@ Int find_chunk_for_OLD ( Addr       ptr,
                          Int        n_chunks )
 
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int  i;
    Addr a_lo, a_hi;
    PROF_EVENT(MCPE_FIND_CHUNK_FOR_OLD);
@@ -290,6 +292,7 @@ Int find_chunk_for ( Addr       ptr, 
                      MC_Chunk** chunks,
                      Int        n_chunks )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Addr a_mid_lo, a_mid_hi;
    Int lo, mid, hi, retVal;
    // VG_(printf)("find chunk for %p = ", ptr);
@@ -336,6 +339,7 @@ Int find_chunk_for ( Addr       ptr, 
 static MC_Chunk**
 find_active_chunks(Int* pn_chunks)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    // Our goal is to construct a set of chunks that includes every
    // mempool chunk, and every malloc region that *doesn't* contain a
    // mempool chunk.
@@ -526,6 +530,7 @@ static SizeT MC_(blocks_heuristically_re
 static Bool
 lc_is_a_chunk_ptr(Addr ptr, Int* pch_no, MC_Chunk** pch, LC_Extra** pex)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int ch_no;
    MC_Chunk* ch;
    LC_Extra* ex;
@@ -566,6 +571,7 @@ lc_is_a_chunk_ptr(Addr ptr, Int* pch_no,
 // Push a chunk (well, just its index) onto the mark stack.
 static void lc_push(Int ch_no, MC_Chunk* ch)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (!lc_extras[ch_no].pending) {
       if (0) {
          VG_(printf)("pushing %#lx-%#lx\n", ch->data, ch->data + ch->szB);
@@ -582,6 +588,7 @@ static void lc_push(Int ch_no, MC_Chunk*
 // there isn't one.
 static Bool lc_pop(Int* ret)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (-1 == lc_markstack_top) {
       return False;
    } else {
@@ -596,6 +603,7 @@ static Bool lc_pop(Int* ret)
 
 static const HChar* pp_heuristic(LeakCheckHeuristic h)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    switch(h) {
    case LchNone:                return "none";
    case LchStdString:           return "stdstring";
@@ -616,6 +624,7 @@ static const HChar* pp_heuristic(LeakChe
 // function.
 static Bool aligned_ptr_above_page0_is_vtable_addr(Addr ptr)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    // ??? If performance problem:
    // ??? maybe implement a cache (array indexed by ptr % primenr)
    // ??? of "I am a vtable ptr" ???
@@ -681,6 +690,7 @@ static Bool aligned_ptr_above_page0_is_v
 // true if a is properly aligned and points to 64bits of valid memory
 static Bool is_valid_aligned_ULong ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (sizeof(Word) == 8)
       return MC_(is_valid_aligned_word)(a);
 
@@ -706,6 +716,7 @@ static
 void leak_search_fault_catcher ( Int sigNo, Addr addr,
                                  const HChar *who, VG_MINIMAL_JMP_BUF(jmpbuf) )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    vki_sigset_t sigmask;
 
    if (0)
@@ -742,6 +753,7 @@ static VG_MINIMAL_JMP_BUF(heuristic_reac
 static
 void heuristic_reachedness_fault_catcher ( Int sigNo, Addr addr )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    leak_search_fault_catcher (sigNo, addr, 
                               "heuristic_reachedness_fault_catcher",
                               heuristic_reachedness_jmpbuf);
@@ -760,7 +772,7 @@ static LeakCheckHeuristic heuristic_reac
                                                  MC_Chunk *ch, LC_Extra *ex,
                                                  UInt heur_set)
 {
-
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    fault_catcher_t prev_catcher;
 
    prev_catcher = VG_(set_fault_catcher)(heuristic_reachedness_fault_catcher);
@@ -887,6 +899,7 @@ static LeakCheckHeuristic heuristic_reac
 static void
 lc_push_without_clique_if_a_chunk_ptr(Addr ptr, Bool is_prior_definite)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int ch_no;
    MC_Chunk* ch;
    LC_Extra* ex;
@@ -945,6 +958,7 @@ lc_push_without_clique_if_a_chunk_ptr(Ad
 static void
 lc_push_if_a_chunk_ptr_register(ThreadId tid, const HChar* regname, Addr ptr)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    lc_push_without_clique_if_a_chunk_ptr(ptr, /*is_prior_definite*/True);
 }
 
@@ -954,6 +968,7 @@ lc_push_if_a_chunk_ptr_register(ThreadId
 static void
 lc_push_with_clique_if_a_chunk_ptr(Addr ptr, Int clique, Int cur_clique)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int ch_no;
    MC_Chunk* ch;
    LC_Extra* ex;
@@ -996,6 +1011,7 @@ static void
 lc_push_if_a_chunk_ptr(Addr ptr,
                        Int clique, Int cur_clique, Bool is_prior_definite)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (-1 == clique) 
       lc_push_without_clique_if_a_chunk_ptr(ptr, is_prior_definite);
    else
@@ -1007,6 +1023,7 @@ static VG_MINIMAL_JMP_BUF(lc_scan_memory
 static
 void lc_scan_memory_fault_catcher ( Int sigNo, Addr addr )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    leak_search_fault_catcher (sigNo, addr, 
                               "lc_scan_memory_fault_catcher",
                               lc_scan_memory_jmpbuf);
@@ -1046,6 +1063,7 @@ lc_scan_memory(Addr start, SizeT len, Bo
                Int clique, Int cur_clique,
                Addr searched, SizeT szB)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    /* memory scan is based on the assumption that valid pointers are aligned
       on a multiple of sizeof(Addr). So, we can (and must) skip the begin and
       end portions of the block if they are not aligned on sizeof(Addr):
@@ -1182,6 +1200,7 @@ lc_scan_memory(Addr start, SizeT len, Bo
 // Process the mark stack until empty.
 static void lc_process_markstack(Int clique)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int  top = -1;    // shut gcc up
    Bool is_prior_definite;
 
@@ -1199,6 +1218,7 @@ static void lc_process_markstack(Int cli
 
 static Word cmp_LossRecordKey_LossRecord(const void* key, const void* elem)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    const LossRecordKey* a = key;
    const LossRecordKey* b = &(((const LossRecord*)elem)->key);
 
@@ -1217,6 +1237,7 @@ static Word cmp_LossRecordKey_LossRecord
 
 static Int cmp_LossRecords(const void* va, const void* vb)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    const LossRecord* lr_a = *(const LossRecord *const *)va;
    const LossRecord* lr_b = *(const LossRecord *const *)vb;
    SizeT total_szB_a = lr_a->szB + lr_a->indirect_szB;
@@ -1243,6 +1264,7 @@ static Int cmp_LossRecords(const void* v
 // allocates or reallocates lr_array, and set its elements to the loss records
 // contains in lr_table.
 static UInt get_lr_array_from_lr_table(void) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt         i, n_lossrecords;
    LossRecord*  lr;
 
@@ -1268,6 +1290,7 @@ static void get_printing_rules(LeakCheck
                                Bool* count_as_error,
                                Bool* print_record)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    // Rules for printing:
    // - We don't show suppressed loss records ever (and that's controlled
    //   within the error manager).
@@ -1341,10 +1364,12 @@ typedef
 
 static void MC_(XT_Leak_init)(void* xtl)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    VG_(memset) (xtl, 0, sizeof(XT_Leak));
 }
 static void MC_(XT_Leak_add) (void* to, const void* xtleak)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    XT_Leak* xto = to;
    const XT_Leak* xtl = xtleak;
 
@@ -1357,6 +1382,7 @@ static void MC_(XT_Leak_add) (void* to, 
 }
 static void XT_insert_lr (LossRecord* lr)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    XT_Leak xtl;
    Reachedness i = lr->key.state;
 
@@ -1388,10 +1414,12 @@ static void XT_insert_lr (LossRecord* lr
 
 static void MC_(XT_Leak_sub) (void* from, const void* xtleak)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(0); // Should not be called.
 }
 static const HChar* MC_(XT_Leak_img) (const void* xtleak)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    static XT_Leak zero;
    static HChar buf[600];
    UInt off = 0;
@@ -1490,6 +1518,7 @@ static const HChar* XT_Leak_events = 
 
 static void print_results(ThreadId tid, LeakCheckParams* lcp)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int          i, n_lossrecords, start_lr_output_scan;
    LossRecord*  lr;
    Bool         is_suppressed;
@@ -1782,6 +1811,7 @@ static void print_results(ThreadId tid, 
 // Printing stops when *remaining reaches 0.
 static void print_clique (Int clique, UInt level, UInt *remaining)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int ind;
    UInt i,  n_lossrecords;
 
@@ -1821,6 +1851,7 @@ Bool MC_(print_block_list) ( UInt loss_r
                              UInt max_blocks,
                              UInt heuristics)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt loss_record_nr;
    UInt         i,  n_lossrecords;
    LossRecord*  lr;
@@ -1918,6 +1949,7 @@ Bool MC_(print_block_list) ( UInt loss_r
 // pointing inside [searched, searched+szB[.
 static void scan_memory_root_set(Addr searched, SizeT szB)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int   i;
    Int   n_seg_starts;
    Addr* seg_starts = VG_(get_segment_starts)( SkFileC | SkAnonC | SkShmC,
@@ -1973,6 +2005,7 @@ static void scan_memory_root_set(Addr se
 
 static MC_Mempool *find_mp_of_chunk (MC_Chunk* mc_search)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Mempool* mp;
 
    tl_assert( MC_(mempool_list) );
@@ -1996,8 +2029,9 @@ static MC_Mempool *find_mp_of_chunk (MC_
 
 void MC_(detect_memory_leaks) ( ThreadId tid, LeakCheckParams* lcp)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int i, j;
-   
+
    tl_assert(lcp->mode != LC_Off);
 
    // Verify some assertions which are used in lc_scan_memory.
@@ -2234,6 +2268,7 @@ static SizeT searched_szB;
 static void
 search_address_in_GP_reg(ThreadId tid, const HChar* regname, Addr addr_in_reg)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (addr_in_reg >= searched_wpa 
        && addr_in_reg < searched_wpa + searched_szB) {
       if (addr_in_reg == searched_wpa)
@@ -2250,6 +2285,7 @@ search_address_in_GP_reg(ThreadId tid, c
 
 void MC_(who_points_at) ( Addr address, SizeT szB)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Chunk** chunks;
    Int        n_chunks;
    Int        i;
@@ -2284,4 +2320,3 @@ void MC_(who_points_at) ( Addr address, 
 /*--------------------------------------------------------------------*/
 /*--- end                                                          ---*/
 /*--------------------------------------------------------------------*/
-
