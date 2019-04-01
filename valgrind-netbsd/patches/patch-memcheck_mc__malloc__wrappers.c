$NetBSD$

--- memcheck/mc_malloc_wrappers.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ memcheck/mc_malloc_wrappers.c
@@ -102,6 +102,7 @@ static MC_Chunk* freed_list_end[2]    = 
    some of the oldest blocks in the queue at the same time. */
 static void add_to_freed_queue ( MC_Chunk* mc )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    const Bool show = False;
    const int l = (mc->szB >= MC_(clo_freelist_big_blocks) ? 0 : 1);
 
@@ -137,6 +138,7 @@ static void add_to_freed_queue ( MC_Chun
    On exit, VG_(free_queue_volume) will be <= MC_(clo_freelist_vol). */
 static void release_oldest_block(void)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    const Bool show = False;
    int i;
    tl_assert (VG_(free_queue_volume) > MC_(clo_freelist_vol));
@@ -174,6 +176,7 @@ static void release_oldest_block(void)
 
 MC_Chunk* MC_(get_freed_block_bracketting) (Addr a)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    int i;
    for (i = 0; i < 2; i++) {
       MC_Chunk*  mc;
@@ -194,6 +197,7 @@ static
 MC_Chunk* create_MC_Chunk ( ThreadId tid, Addr p, SizeT szB,
                             MC_AllocKind kind)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Chunk* mc  = VG_(allocEltPA)(MC_(chunk_poolalloc));
    mc->data      = p;
    mc->szB       = szB;
@@ -224,12 +228,14 @@ MC_Chunk* create_MC_Chunk ( ThreadId tid
 static inline
 void delete_MC_Chunk (MC_Chunk* mc)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    VG_(freeEltPA) (MC_(chunk_poolalloc), mc);
 }
 
 // True if mc is in the given block list.
 static Bool in_block_list (const VgHashTable *block_list, MC_Chunk* mc)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Chunk* found_mc = VG_(HT_lookup) ( block_list, (UWord)mc->data );
    if (found_mc) {
       tl_assert (found_mc->data == mc->data);
@@ -254,6 +260,7 @@ static Bool in_block_list (const VgHashT
 // True if mc is a live block (not yet freed).
 static Bool live_block (MC_Chunk* mc)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (mc->allockind == MC_AllocCustom) {
       MC_Mempool* mp;
       VG_(HT_ResetIter)(MC_(mempool_list));
@@ -270,6 +277,7 @@ static Bool live_block (MC_Chunk* mc)
 
 ExeContext* MC_(allocated_at) (MC_Chunk* mc)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    switch (MC_(clo_keep_stacktraces)) {
       case KS_none:            return VG_(null_ExeContext) ();
       case KS_alloc:           return mc->where[0];
@@ -283,6 +291,7 @@ ExeContext* MC_(allocated_at) (MC_Chunk*
 
 ExeContext* MC_(freed_at) (MC_Chunk* mc)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    switch (MC_(clo_keep_stacktraces)) {
       case KS_none:            return VG_(null_ExeContext) ();
       case KS_alloc:           return VG_(null_ExeContext) ();
@@ -298,6 +307,7 @@ ExeContext* MC_(freed_at) (MC_Chunk* mc)
 
 void  MC_(set_allocated_at) (ThreadId tid, MC_Chunk* mc)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    switch (MC_(clo_keep_stacktraces)) {
       case KS_none:            return;
       case KS_alloc:           break;
@@ -313,6 +323,7 @@ void  MC_(set_allocated_at) (ThreadId ti
 
 void  MC_(set_freed_at) (ThreadId tid, MC_Chunk* mc)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int pos;
    ExeContext* ec_free;
 
@@ -342,6 +353,7 @@ void  MC_(set_freed_at) (ThreadId tid, M
 
 UInt MC_(n_where_pointers) (void)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    switch (MC_(clo_keep_stacktraces)) {
       case KS_none:            return 0;
       case KS_alloc:
@@ -362,6 +374,7 @@ void* MC_(new_block) ( ThreadId tid,
                        Bool is_zeroed, MC_AllocKind kind,
                        VgHashTable *table)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Chunk* mc;
 
    // Allocate and zero if necessary
@@ -401,6 +414,7 @@ void* MC_(new_block) ( ThreadId tid,
 
 void* MC_(malloc) ( ThreadId tid, SizeT n )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (MC_(record_fishy_value_error)(tid, "malloc", "size", n)) {
       return NULL;
    } else {
@@ -411,6 +425,7 @@ void* MC_(malloc) ( ThreadId tid, SizeT 
 
 void* MC_(__builtin_new) ( ThreadId tid, SizeT n )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (MC_(record_fishy_value_error)(tid, "__builtin_new", "size", n)) {
       return NULL;
    } else {
@@ -421,6 +436,7 @@ void* MC_(__builtin_new) ( ThreadId tid,
 
 void* MC_(__builtin_vec_new) ( ThreadId tid, SizeT n )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (MC_(record_fishy_value_error)(tid, "__builtin_vec_new", "size", n)) {
       return NULL;
    } else {
@@ -431,6 +447,7 @@ void* MC_(__builtin_vec_new) ( ThreadId 
 
 void* MC_(memalign) ( ThreadId tid, SizeT alignB, SizeT n )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (MC_(record_fishy_value_error)(tid, "memalign", "size", n)) {
       return NULL;
    } else {
@@ -441,6 +458,7 @@ void* MC_(memalign) ( ThreadId tid, Size
 
 void* MC_(calloc) ( ThreadId tid, SizeT nmemb, SizeT size1 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (MC_(record_fishy_value_error)(tid, "calloc", "nmemb", nmemb) ||
        MC_(record_fishy_value_error)(tid, "calloc", "size", size1)) {
       return NULL;
@@ -453,6 +471,7 @@ void* MC_(calloc) ( ThreadId tid, SizeT 
 static
 void die_and_free_mem ( ThreadId tid, MC_Chunk* mc, SizeT rzB )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    /* Note: we do not free fill the custom allocs produced
       by MEMPOOL or by MALLOC/FREELIKE_BLOCK requests. */
    if (MC_(clo_free_fill) != -1 && MC_AllocCustom != mc->allockind ) {
@@ -478,6 +497,7 @@ void die_and_free_mem ( ThreadId tid, MC
 static
 void record_freemismatch_error (ThreadId tid, MC_Chunk* mc)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    /* Only show such an error if the user hasn't disabled doing so. */
    if (!MC_(clo_show_mismatched_frees))
       return;
@@ -496,6 +516,7 @@ void record_freemismatch_error (ThreadId
 
 void MC_(handle_free) ( ThreadId tid, Addr p, UInt rzB, MC_AllocKind kind )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Chunk* mc;
 
    cmalloc_n_frees++;
@@ -515,24 +536,28 @@ void MC_(handle_free) ( ThreadId tid, Ad
 
 void MC_(free) ( ThreadId tid, void* p )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(handle_free)( 
       tid, (Addr)p, MC_(Malloc_Redzone_SzB), MC_AllocMalloc );
 }
 
 void MC_(__builtin_delete) ( ThreadId tid, void* p )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(handle_free)(
       tid, (Addr)p, MC_(Malloc_Redzone_SzB), MC_AllocNew);
 }
 
 void MC_(__builtin_vec_delete) ( ThreadId tid, void* p )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(handle_free)(
       tid, (Addr)p, MC_(Malloc_Redzone_SzB), MC_AllocNewVec);
 }
 
 void* MC_(realloc) ( ThreadId tid, void* p_old, SizeT new_szB )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Chunk* old_mc;
    MC_Chunk* new_mc;
    Addr      a_new; 
@@ -647,6 +672,7 @@ void* MC_(realloc) ( ThreadId tid, void*
 
 SizeT MC_(malloc_usable_size) ( ThreadId tid, void* p )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Chunk* mc = VG_(HT_lookup) ( MC_(malloc_list), (UWord)p );
 
    // There may be slop, but pretend there isn't because only the asked-for
@@ -661,6 +687,7 @@ SizeT MC_(malloc_usable_size) ( ThreadId
 void MC_(handle_resizeInPlace)(ThreadId tid, Addr p,
                                SizeT oldSizeB, SizeT newSizeB, SizeT rzB)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Chunk* mc = VG_(HT_lookup) ( MC_(malloc_list), (UWord)p );
    if (!mc || mc->szB != oldSizeB || newSizeB == 0) {
       /* Reject if: p is not found, or oldSizeB is wrong,
@@ -703,6 +730,7 @@ static void free_mallocs_in_mempool_bloc
                                            Addr StartAddr,
                                            Addr EndAddr)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Chunk *mc;
    ThreadId tid;
 
@@ -733,6 +761,7 @@ static void free_mallocs_in_mempool_bloc
 void MC_(create_mempool)(Addr pool, UInt rzB, Bool is_zeroed,
                          Bool auto_free, Bool metapool)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Mempool* mp;
 
    if (VG_(clo_verbosity) > 2 || (auto_free && !metapool)) {
@@ -776,6 +805,7 @@ void MC_(create_mempool)(Addr pool, UInt
 
 void MC_(destroy_mempool)(Addr pool)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Chunk*   mc;
    MC_Mempool* mp;
 
@@ -810,6 +840,7 @@ void MC_(destroy_mempool)(Addr pool)
 static Int 
 mp_compar(const void* n1, const void* n2)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    const MC_Chunk* mc1 = *(const MC_Chunk *const *)n1;
    const MC_Chunk* mc2 = *(const MC_Chunk *const *)n2;
    if (mc1->data < mc2->data) return -1;
@@ -820,6 +851,7 @@ mp_compar(const void* n1, const void* n2
 static void 
 check_mempool_sane(MC_Mempool* mp)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt n_chunks, i, bad = 0;   
    static UInt tick = 0;
 
@@ -895,6 +927,7 @@ check_mempool_sane(MC_Mempool* mp)
 
 void MC_(mempool_alloc)(ThreadId tid, Addr pool, Addr addr, SizeT szB)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Mempool* mp;
 
    if (VG_(clo_verbosity) > 2) {     
@@ -924,6 +957,7 @@ void MC_(mempool_alloc)(ThreadId tid, Ad
 
 void MC_(mempool_free)(Addr pool, Addr addr)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Mempool*  mp;
    MC_Chunk*    mc;
    ThreadId     tid = VG_(get_running_tid)();
@@ -963,6 +997,7 @@ void MC_(mempool_free)(Addr pool, Addr a
 
 void MC_(mempool_trim)(Addr pool, Addr addr, SizeT szB)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Mempool*  mp;
    MC_Chunk*    mc;
    ThreadId     tid = VG_(get_running_tid)();
@@ -1077,6 +1112,7 @@ void MC_(mempool_trim)(Addr pool, Addr a
 
 void MC_(move_mempool)(Addr poolA, Addr poolB)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Mempool* mp;
 
    if (VG_(clo_verbosity) > 2) {
@@ -1099,6 +1135,7 @@ void MC_(move_mempool)(Addr poolA, Addr 
 
 void MC_(mempool_change)(Addr pool, Addr addrA, Addr addrB, SizeT szB)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Mempool*  mp;
    MC_Chunk*    mc;
    ThreadId     tid = VG_(get_running_tid)();
@@ -1132,6 +1169,7 @@ void MC_(mempool_change)(Addr pool, Addr
 
 Bool MC_(mempool_exists)(Addr pool)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Mempool*  mp;
 
    mp = VG_(HT_lookup)(MC_(mempool_list), (UWord)pool);
@@ -1143,6 +1181,7 @@ Bool MC_(mempool_exists)(Addr pool)
 
 static void xtmemory_report_next_block(XT_Allocs* xta, ExeContext** ec_alloc)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Chunk* mc = VG_(HT_Next)(MC_(malloc_list));
    if (mc) {
       xta->nbytes = mc->szB;
@@ -1154,6 +1193,7 @@ static void xtmemory_report_next_block(X
 
 void MC_(xtmemory_report) ( const HChar* filename, Bool fini )
 { 
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    // Make xtmemory_report_next_block ready to be called.
    VG_(HT_ResetIter)(MC_(malloc_list));
 
@@ -1167,6 +1207,7 @@ void MC_(xtmemory_report) ( const HChar*
 
 void MC_(print_malloc_stats) ( void )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_Chunk* mc;
    SizeT     nblocks = 0;
    ULong     nbytes  = 0;
@@ -1196,6 +1237,7 @@ void MC_(print_malloc_stats) ( void )
 
 SizeT MC_(get_cmalloc_n_frees) ( void )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return cmalloc_n_frees;
 }
 
