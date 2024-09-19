$NetBSD$

--- memcheck/mc_main.c.orig	2018-09-30 04:41:00.000000000 +0000
+++ memcheck/mc_main.c
@@ -55,7 +55,24 @@
 #include "memcheck.h"   /* for client requests */
 
 /* Set to 1 to do a little more sanity checking */
-#define VG_DEBUG_MEMORY 0
+#define VG_DEBUG_MEMORY 1
+
+void __sanitizer_cov_trace_pc(void);
+
+void
+__sanitizer_cov_trace_pc(void)
+{
+   static int recursive = 0;
+
+   if (recursive > 0)
+      return;
+
+   recursive++;
+
+   VG_(debugLog)(2, "KR", "%s() %s:%d addr=%lx\n", __func__, __FILE__, __LINE__, __builtin_return_address(0));
+
+   recursive--;
+}
 
 #define DEBUG(fmt, args...) //VG_(printf)(fmt, ## args)
 
@@ -266,9 +283,11 @@ static void ocache_sarp_Clear_Origins ( 
 #define INLINE    inline __attribute__((always_inline))
 
 static INLINE Addr start_of_this_sm ( Addr a ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return (a & (~SM_MASK));
 }
 static INLINE Bool is_start_of_sm ( Addr a ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return (start_of_this_sm(a) == a);
 }
 
@@ -302,6 +321,7 @@ static void update_SM_counts(SecMap* old
 */
 static SecMap* copy_for_writing ( SecMap* dist_sm )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SecMap* new_sm;
    tl_assert(dist_sm == &sm_distinguished[0]
           || dist_sm == &sm_distinguished[1]
@@ -345,6 +365,7 @@ static Int   max_secVBit_nodes = 0;
 
 static void update_SM_counts(SecMap* oldSM, SecMap* newSM)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if      (oldSM == &sm_distinguished[SM_DIST_NOACCESS ]) n_noaccess_SMs --;
    else if (oldSM == &sm_distinguished[SM_DIST_UNDEFINED]) n_undefined_SMs--;
    else if (oldSM == &sm_distinguished[SM_DIST_DEFINED  ]) n_defined_SMs  --;
@@ -412,6 +433,7 @@ static OSet* auxmap_L2 = NULL;
 
 static void init_auxmap_L1_L2 ( void )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int i;
    for (i = 0; i < N_AUXMAP_L1; i++) {
       auxmap_L1[i].base = 0;
@@ -432,6 +454,7 @@ static void init_auxmap_L1_L2 ( void )
 
 static const HChar* check_auxmap_L1_L2_sanity ( Word* n_secmaps_found )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Word i, j;
    /* On a 32-bit platform, the L2 and L1 tables should
       both remain empty forever.
@@ -514,6 +537,7 @@ static const HChar* check_auxmap_L1_L2_s
 
 static void insert_into_auxmap_L1_at ( Word rank, AuxMapEnt* ent )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Word i;
    tl_assert(ent);
    tl_assert(rank >= 0 && rank < N_AUXMAP_L1);
@@ -525,6 +549,7 @@ static void insert_into_auxmap_L1_at ( W
 
 static INLINE AuxMapEnt* maybe_find_in_auxmap ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    AuxMapEnt  key;
    AuxMapEnt* res;
    Word       i;
@@ -585,6 +610,7 @@ static INLINE AuxMapEnt* maybe_find_in_a
 
 static AuxMapEnt* find_or_alloc_in_auxmap ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    AuxMapEnt *nyu, *res;
 
    /* First see if we already have it. */
@@ -612,12 +638,14 @@ static AuxMapEnt* find_or_alloc_in_auxma
 
 static INLINE UWord get_primary_map_low_offset ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
   UWord pm_off = a >> 16;
   return pm_off;
 }
 
 static INLINE SecMap** get_secmap_low_ptr ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UWord pm_off = a >> 16;
 #  if VG_DEBUG_MEMORY >= 1
    tl_assert(pm_off < N_PRIMARY_MAP);
@@ -627,12 +655,14 @@ static INLINE SecMap** get_secmap_low_pt
 
 static INLINE SecMap** get_secmap_high_ptr ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    AuxMapEnt* am = find_or_alloc_in_auxmap(a);
    return &am->sm;
 }
 
 static INLINE SecMap** get_secmap_ptr ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return ( a <= MAX_PRIMARY_ADDRESS 
           ? get_secmap_low_ptr(a) 
           : get_secmap_high_ptr(a));
@@ -640,16 +670,19 @@ static INLINE SecMap** get_secmap_ptr ( 
 
 static INLINE SecMap* get_secmap_for_reading_low ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return *get_secmap_low_ptr(a);
 }
 
 static INLINE SecMap* get_secmap_for_reading_high ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return *get_secmap_high_ptr(a);
 }
 
 static INLINE SecMap* get_secmap_for_writing_low(Addr a)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SecMap** p = get_secmap_low_ptr(a);
    if (UNLIKELY(is_distinguished_sm(*p)))
       *p = copy_for_writing(*p);
@@ -671,6 +704,7 @@ static INLINE SecMap* get_secmap_for_wri
 */
 static INLINE SecMap* get_secmap_for_reading ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return ( a <= MAX_PRIMARY_ADDRESS
           ? get_secmap_for_reading_low (a)
           : get_secmap_for_reading_high(a) );
@@ -685,6 +719,7 @@ static INLINE SecMap* get_secmap_for_rea
 */
 static INLINE SecMap* get_secmap_for_writing ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return ( a <= MAX_PRIMARY_ADDRESS
           ? get_secmap_for_writing_low (a)
           : get_secmap_for_writing_high(a) );
@@ -696,6 +731,7 @@ static INLINE SecMap* get_secmap_for_wri
 */
 static SecMap* maybe_get_secmap_for ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (a <= MAX_PRIMARY_ADDRESS) {
       return get_secmap_for_reading_low(a);
    } else {
@@ -709,6 +745,7 @@ static SecMap* maybe_get_secmap_for ( Ad
 static INLINE
 void insert_vabits2_into_vabits8 ( Addr a, UChar vabits2, UChar* vabits8 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt shift =  (a & 3)  << 1;        // shift by 0, 2, 4, or 6
    *vabits8  &= ~(0x3     << shift);   // mask out the two old bits
    *vabits8  |=  (vabits2 << shift);   // mask  in the two new bits
@@ -717,6 +754,7 @@ void insert_vabits2_into_vabits8 ( Addr 
 static INLINE
 void insert_vabits4_into_vabits8 ( Addr a, UChar vabits4, UChar* vabits8 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt shift;
    tl_assert(VG_IS_2_ALIGNED(a));      // Must be 2-aligned
    shift     =  (a & 2)   << 1;        // shift by 0 or 4
@@ -727,6 +765,7 @@ void insert_vabits4_into_vabits8 ( Addr 
 static INLINE
 UChar extract_vabits2_from_vabits8 ( Addr a, UChar vabits8 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt shift = (a & 3) << 1;          // shift by 0, 2, 4, or 6
    vabits8 >>= shift;                  // shift the two bits to the bottom
    return 0x3 & vabits8;               // mask out the rest
@@ -735,6 +774,7 @@ UChar extract_vabits2_from_vabits8 ( Add
 static INLINE
 UChar extract_vabits4_from_vabits8 ( Addr a, UChar vabits8 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt shift;
    tl_assert(VG_IS_2_ALIGNED(a));      // Must be 2-aligned
    shift = (a & 2) << 1;               // shift by 0 or 4
@@ -753,6 +793,7 @@ UChar extract_vabits4_from_vabits8 ( Add
 static INLINE
 void set_vabits2 ( Addr a, UChar vabits2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SecMap* sm       = get_secmap_for_writing(a);
    UWord   sm_off   = SM_OFF(a);
    insert_vabits2_into_vabits8( a, vabits2, &(sm->vabits8[sm_off]) );
@@ -761,6 +802,7 @@ void set_vabits2 ( Addr a, UChar vabits2
 static INLINE
 UChar get_vabits2 ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SecMap* sm       = get_secmap_for_reading(a);
    UWord   sm_off   = SM_OFF(a);
    UChar   vabits8  = sm->vabits8[sm_off];
@@ -774,6 +816,7 @@ UChar get_vabits2 ( Addr a )
 static INLINE
 UChar get_vabits8_for_aligned_word32 ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SecMap* sm       = get_secmap_for_reading(a);
    UWord   sm_off   = SM_OFF(a);
    UChar   vabits8  = sm->vabits8[sm_off];
@@ -783,6 +826,7 @@ UChar get_vabits8_for_aligned_word32 ( A
 static INLINE
 void set_vabits8_for_aligned_word32 ( Addr a, UChar vabits8 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SecMap* sm       = get_secmap_for_writing(a);
    UWord   sm_off   = SM_OFF(a);
    sm->vabits8[sm_off] = vabits8;
@@ -797,6 +841,7 @@ static void  set_sec_vbits8(Addr a, UWor
 static INLINE
 Bool set_vbits8 ( Addr a, UChar vbits8 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Bool  ok      = True;
    UChar vabits2 = get_vabits2(a);
    if ( VA_BITS2_NOACCESS != vabits2 ) {
@@ -823,6 +868,7 @@ Bool set_vbits8 ( Addr a, UChar vbits8 )
 static INLINE
 Bool get_vbits8 ( Addr a, UChar* vbits8 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Bool  ok      = True;
    UChar vabits2 = get_vabits2(a);
 
@@ -941,6 +987,7 @@ typedef 
 
 static OSet* createSecVBitTable(void)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    OSet* newSecVBitTable;
    newSecVBitTable = VG_(OSetGen_Create_With_Pool)
       ( offsetof(SecVBitNode, a), 
@@ -954,6 +1001,7 @@ static OSet* createSecVBitTable(void)
 
 static void gcSecVBitTable(void)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    OSet*        secVBitTable2;
    SecVBitNode* n;
    Int          i, n_nodes = 0, n_survivors = 0;
@@ -1018,6 +1066,7 @@ static void gcSecVBitTable(void)
 
 static UWord get_sec_vbits8(Addr a)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Addr         aAligned = VG_ROUNDDN(a, BYTES_PER_SEC_VBIT_NODE);
    Int          amod     = a % BYTES_PER_SEC_VBIT_NODE;
    SecVBitNode* n        = VG_(OSetGen_Lookup)(secVBitTable, &aAligned);
@@ -1032,6 +1081,7 @@ static UWord get_sec_vbits8(Addr a)
 
 static void set_sec_vbits8(Addr a, UWord vbits8)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Addr         aAligned = VG_ROUNDDN(a, BYTES_PER_SEC_VBIT_NODE);
    Int          i, amod  = a % BYTES_PER_SEC_VBIT_NODE;
    SecVBitNode* n        = VG_(OSetGen_Lookup)(secVBitTable, &aAligned);
@@ -1073,6 +1123,7 @@ static void set_sec_vbits8(Addr a, UWord
    in a wordszB-sized word, given the specified endianness. */
 static INLINE UWord byte_offset_w ( UWord wordszB, Bool bigendian, 
                                     UWord byteno ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return bigendian ? (wordszB-1-byteno) : byteno;
 }
 
@@ -1093,6 +1144,7 @@ typedef
 
 static const HChar* showIARKind ( IARKind iark )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    switch (iark) {
       case IAR_INVALID:     return "INVALID";
       case IAR_NotIgnored:  return "NotIgnored";
@@ -1107,6 +1159,7 @@ static RangeMap* gIgnoredAddressRanges =
 
 static void init_gIgnoredAddressRanges ( void )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (LIKELY(gIgnoredAddressRanges != NULL))
       return;
    gIgnoredAddressRanges = VG_(newRangeMap)( VG_(malloc), "mc.igIAR.1",
@@ -1115,6 +1168,7 @@ static void init_gIgnoredAddressRanges (
 
 Bool MC_(in_ignored_range) ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (LIKELY(gIgnoredAddressRanges == NULL))
       return False;
    UWord how     = IAR_INVALID;
@@ -1134,6 +1188,7 @@ Bool MC_(in_ignored_range) ( Addr a )
 
 Bool MC_(in_ignored_range_below_sp) ( Addr sp, Addr a, UInt szB )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (LIKELY(!MC_(clo_ignore_range_below_sp)))
        return False;
    tl_assert(szB >= 1 && szB <= 32);
@@ -1159,6 +1214,7 @@ Bool MC_(in_ignored_range_below_sp) ( Ad
 
 static Bool parse_Addr_pair ( const HChar** ppc, Addr* result1, Addr* result2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Bool ok = VG_(parse_Addr) (ppc, result1);
    if (!ok)
       return False;
@@ -1176,6 +1232,7 @@ static Bool parse_Addr_pair ( const HCha
 
 static Bool parse_UInt_pair ( const HChar** ppc, UInt* result1, UInt* result2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Bool ok = VG_(parse_UInt) (ppc, result1);
    if (!ok)
       return False;
@@ -1193,6 +1250,7 @@ static Bool parse_UInt_pair ( const HCha
    ranges. */
 static Bool parse_ignore_ranges ( const HChar* str0 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    init_gIgnoredAddressRanges();
    const HChar*  str = str0;
    const HChar** ppc = &str;
@@ -1218,6 +1276,7 @@ static Bool parse_ignore_ranges ( const 
 /* Add or remove [start, +len) from the set of ignored ranges. */
 static Bool modify_ignore_ranges ( Bool addRange, Addr start, Addr len )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    init_gIgnoredAddressRanges();
    const Bool verbose = (VG_(clo_verbosity) > 1);
    if (len == 0) {
@@ -1261,6 +1320,7 @@ __attribute__((noinline))
 void mc_LOADV_128_or_256_slow ( /*OUT*/ULong* res,
                                 Addr a, SizeT nBits, Bool bigendian )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    ULong  pessim[4];     /* only used when p-l-ok=yes */
    SSizeT szB            = nBits / 8;
    SSizeT szL            = szB / 8;  /* Size in Longs (64-bit units) */
@@ -1391,6 +1451,8 @@ VG_REGPARM(3) /* make sure we're using a
                  this function may get called from hand written assembly. */
 ULong mc_LOADVn_slow ( Addr a, SizeT nBits, Bool bigendian )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
+VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_LOADVN_SLOW);
 
    /* ------------ BEGIN semi-fast cases ------------ */
@@ -1474,7 +1536,9 @@ ULong mc_LOADVn_slow ( Addr a, SizeT nBi
    /* If there's no possibility of getting a partial-loads-ok
       exemption, report the error and quit. */
    if (!MC_(clo_partial_loads_ok)) {
+VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
       MC_(record_address_error)( VG_(get_running_tid)(), a, szB, False );
+VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
       return vbits64;
    }
 
@@ -1550,7 +1614,9 @@ ULong mc_LOADVn_slow ( Addr a, SizeT nBi
 
    /* Exemption doesn't apply.  Flag an addressing error in the normal
       way. */
+VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(record_address_error)( VG_(get_running_tid)(), a, szB, False );
+VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 
    return vbits64;
 }
@@ -1560,6 +1626,7 @@ static
 __attribute__((noinline))
 void mc_STOREVn_slow ( Addr a, SizeT nBits, ULong vbytes, Bool bigendian )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SizeT szB = nBits / 8;
    SizeT i, n_addrs_bad = 0;
    UChar vbits8;
@@ -1658,6 +1725,7 @@ void mc_STOREVn_slow ( Addr a, SizeT nBi
 static void set_address_range_perms ( Addr a, SizeT lenT, UWord vabits16,
                                       UWord dsm_num )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UWord    sm_off, sm_off16;
    UWord    vabits2 = vabits16 & 0x3;
    SizeT    lenA, lenB, len_to_next_secmap;
@@ -1891,6 +1959,7 @@ static void set_address_range_perms ( Ad
 
 void MC_(make_mem_noaccess) ( Addr a, SizeT len )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_MAKE_MEM_NOACCESS);
    DEBUG("MC_(make_mem_noaccess)(%p, %lu)\n", a, len);
    set_address_range_perms ( a, len, VA_BITS16_NOACCESS, SM_DIST_NOACCESS );
@@ -1900,6 +1969,7 @@ void MC_(make_mem_noaccess) ( Addr a, Si
 
 static void make_mem_undefined ( Addr a, SizeT len )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_MAKE_MEM_UNDEFINED);
    DEBUG("make_mem_undefined(%p, %lu)\n", a, len);
    set_address_range_perms ( a, len, VA_BITS16_UNDEFINED, SM_DIST_UNDEFINED );
@@ -1907,6 +1977,7 @@ static void make_mem_undefined ( Addr a,
 
 void MC_(make_mem_undefined_w_otag) ( Addr a, SizeT len, UInt otag )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_MAKE_MEM_UNDEFINED_W_OTAG);
    DEBUG("MC_(make_mem_undefined)(%p, %lu)\n", a, len);
    set_address_range_perms ( a, len, VA_BITS16_UNDEFINED, SM_DIST_UNDEFINED );
@@ -1918,6 +1989,7 @@ static
 void make_mem_undefined_w_tid_and_okind ( Addr a, SizeT len,
                                           ThreadId tid, UInt okind )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt        ecu;
    ExeContext* here;
    /* VG_(record_ExeContext) checks for validity of tid, and asserts
@@ -1933,17 +2005,20 @@ void make_mem_undefined_w_tid_and_okind 
 static
 void mc_new_mem_w_tid_make_ECU  ( Addr a, SizeT len, ThreadId tid )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    make_mem_undefined_w_tid_and_okind ( a, len, tid, MC_OKIND_UNKNOWN );
 }
 
 static
 void mc_new_mem_w_tid_no_ECU  ( Addr a, SizeT len, ThreadId tid )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(make_mem_undefined_w_otag) ( a, len, MC_OKIND_UNKNOWN );
 }
 
 void MC_(make_mem_defined) ( Addr a, SizeT len )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_MAKE_MEM_DEFINED);
    DEBUG("MC_(make_mem_defined)(%p, %lu)\n", a, len);
    set_address_range_perms ( a, len, VA_BITS16_DEFINED, SM_DIST_DEFINED );
@@ -1954,6 +2029,7 @@ void MC_(make_mem_defined) ( Addr a, Siz
 __attribute__((unused))
 static void make_mem_defined_w_tid ( Addr a, SizeT len, ThreadId tid )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(make_mem_defined)(a, len);
 }
 
@@ -1963,6 +2039,7 @@ static void make_mem_defined_w_tid ( Add
    addressibility.  Low-performance implementation. */
 static void make_mem_defined_if_addressable ( Addr a, SizeT len )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SizeT i;
    UChar vabits2;
    DEBUG("make_mem_defined_if_addressable(%p, %llu)\n", a, (ULong)len);
@@ -1980,6 +2057,7 @@ static void make_mem_defined_if_addressa
 /* Similarly (needed for mprotect handling ..) */
 static void make_mem_defined_if_noaccess ( Addr a, SizeT len )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SizeT i;
    UChar vabits2;
    DEBUG("make_mem_defined_if_noaccess(%p, %llu)\n", a, (ULong)len);
@@ -1999,6 +2077,7 @@ static void make_mem_defined_if_noaccess
 
 void MC_(copy_address_range_state) ( Addr src, Addr dst, SizeT len )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SizeT i, j;
    UChar vabits2, vabits8;
    Bool  aligned, nooverlap;
@@ -2408,9 +2487,11 @@ static UWord stats__ocacheL2_n_nodes_max
 #define OC_W32S_PER_LINE (1 << (OC_BITS_PER_LINE - 2))
 
 static INLINE UWord oc_line_offset ( Addr a ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return (a >> 2) & (OC_W32S_PER_LINE - 1);
 }
 static INLINE Bool is_valid_oc_tag ( Addr tag ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return 0 == (tag & ((1 << OC_BITS_PER_LINE) - 1));
 }
 
@@ -2440,6 +2521,7 @@ typedef
    and 'z' if all the represented tags are zero. */
 static UChar classify_OCacheLine ( OCacheLine* line )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UWord i;
    if (line->tag == 1/*invalid*/)
       return 'e'; /* EMPTY */
@@ -2470,6 +2552,7 @@ static UWord   ocacheL1_event_ctr = 0;
 static void init_ocacheL2 ( void ); /* fwds */
 static void init_OCache ( void )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UWord line, set;
    tl_assert(MC_(clo_mc_level) >= 3);
    tl_assert(ocacheL1 == NULL);
@@ -2489,6 +2572,7 @@ static void init_OCache ( void )
 
 static void moveLineForwards ( OCacheSet* set, UWord lineno )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    OCacheLine tmp;
    stats_ocacheL1_movefwds++;
    tl_assert(lineno > 0 && lineno < OC_LINES_PER_SET);
@@ -2498,6 +2582,7 @@ static void moveLineForwards ( OCacheSet
 }
 
 static void zeroise_OCacheLine ( OCacheLine* line, Addr tag ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UWord i;
    for (i = 0; i < OC_W32S_PER_LINE; i++) {
       line->w32[i] = 0; /* NO ORIGIN */
@@ -2512,9 +2597,11 @@ static void zeroise_OCacheLine ( OCacheL
 static OSet* ocacheL2 = NULL;
 
 static void* ocacheL2_malloc ( const HChar* cc, SizeT szB ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return VG_(malloc)(cc, szB);
 }
 static void ocacheL2_free ( void* v ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    VG_(free)( v );
 }
 
@@ -2523,6 +2610,7 @@ static UWord stats__ocacheL2_n_nodes = 0
 
 static void init_ocacheL2 ( void )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(!ocacheL2);
    tl_assert(sizeof(Word) == sizeof(Addr)); /* since OCacheLine.tag :: Addr */
    tl_assert(0 == offsetof(OCacheLine,tag));
@@ -2536,6 +2624,7 @@ static void init_ocacheL2 ( void )
 /* Find line with the given tag in the tree, or NULL if not found. */
 static OCacheLine* ocacheL2_find_tag ( Addr tag )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    OCacheLine* line;
    tl_assert(is_valid_oc_tag(tag));
    stats__ocacheL2_refs++;
@@ -2547,6 +2636,7 @@ static OCacheLine* ocacheL2_find_tag ( A
    free up the associated memory. */
 static void ocacheL2_del_tag ( Addr tag )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    OCacheLine* line;
    tl_assert(is_valid_oc_tag(tag));
    stats__ocacheL2_refs++;
@@ -2562,6 +2652,7 @@ static void ocacheL2_del_tag ( Addr tag 
    present. */
 static void ocacheL2_add_line ( OCacheLine* line )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    OCacheLine* copy;
    tl_assert(is_valid_oc_tag(line->tag));
    copy = VG_(OSetGen_AllocNode)( ocacheL2, sizeof(OCacheLine) );
@@ -2579,6 +2670,7 @@ static void ocacheL2_add_line ( OCacheLi
 __attribute__((noinline))
 static OCacheLine* find_OCacheLine_SLOW ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    OCacheLine *victim, *inL2;
    UChar c;
    UWord line;
@@ -2664,6 +2756,7 @@ static OCacheLine* find_OCacheLine_SLOW 
 
 static INLINE OCacheLine* find_OCacheLine ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UWord setno   = (a >> OC_BITS_PER_LINE) & (OC_N_SETS - 1);
    UWord tagmask = ~((1 << OC_BITS_PER_LINE) - 1);
    UWord tag     = a & tagmask;
@@ -2684,6 +2777,7 @@ static INLINE OCacheLine* find_OCacheLin
 
 static INLINE void set_aligned_word64_Origin_to_undef ( Addr a, UInt otag )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    //// BEGIN inlined, specialised version of MC_(helperc_b_store8)
    //// Set the origins for a+0 .. a+7
    { OCacheLine* line;
@@ -2713,6 +2807,7 @@ static INLINE void set_aligned_word64_Or
 
 static INLINE void make_aligned_word32_undefined ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
   PROF_EVENT(MCPE_MAKE_ALIGNED_WORD32_UNDEFINED);
 
 #ifndef PERF_FAST_STACK2
@@ -2738,6 +2833,7 @@ static INLINE void make_aligned_word32_u
 static INLINE
 void make_aligned_word32_undefined_w_otag ( Addr a, UInt otag )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    make_aligned_word32_undefined(a);
    //// BEGIN inlined, specialised version of MC_(helperc_b_store4)
    //// Set the origins for a+0 .. a+3
@@ -2756,6 +2852,7 @@ void make_aligned_word32_undefined_w_ota
 static INLINE
 void make_aligned_word32_noaccess ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_MAKE_ALIGNED_WORD32_NOACCESS);
 
 #ifndef PERF_FAST_STACK2
@@ -2797,6 +2894,7 @@ void make_aligned_word32_noaccess ( Addr
 
 static INLINE void make_aligned_word64_undefined ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_MAKE_ALIGNED_WORD64_UNDEFINED);
 
 #ifndef PERF_FAST_STACK2
@@ -2822,6 +2920,7 @@ static INLINE void make_aligned_word64_u
 static INLINE
 void make_aligned_word64_undefined_w_otag ( Addr a, UInt otag )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    make_aligned_word64_undefined(a);
    //// BEGIN inlined, specialised version of MC_(helperc_b_store8)
    //// Set the origins for a+0 .. a+7
@@ -2841,6 +2940,7 @@ void make_aligned_word64_undefined_w_ota
 static INLINE
 void make_aligned_word64_noaccess ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_MAKE_ALIGNED_WORD64_NOACCESS);
 
 #ifndef PERF_FAST_STACK2
@@ -2892,6 +2992,7 @@ void make_aligned_word64_noaccess ( Addr
 MAYBE_USED
 static void VG_REGPARM(2) mc_new_mem_stack_4_w_ECU(Addr new_SP, UInt ecu)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt otag = ecu | MC_OKIND_STACK;
    PROF_EVENT(MCPE_NEW_MEM_STACK_4);
    if (VG_IS_4_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
@@ -2904,6 +3005,7 @@ static void VG_REGPARM(2) mc_new_mem_sta
 MAYBE_USED
 static void VG_REGPARM(1) mc_new_mem_stack_4(Addr new_SP)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_NEW_MEM_STACK_4);
    if (VG_IS_4_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
       make_aligned_word32_undefined ( -VG_STACK_REDZONE_SZB + new_SP );
@@ -2915,6 +3017,7 @@ static void VG_REGPARM(1) mc_new_mem_sta
 MAYBE_USED
 static void VG_REGPARM(1) mc_die_mem_stack_4(Addr new_SP)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_DIE_MEM_STACK_4);
    if (VG_IS_4_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
       make_aligned_word32_noaccess ( -VG_STACK_REDZONE_SZB + new_SP-4 );
@@ -2928,6 +3031,7 @@ static void VG_REGPARM(1) mc_die_mem_sta
 MAYBE_USED
 static void VG_REGPARM(2) mc_new_mem_stack_8_w_ECU(Addr new_SP, UInt ecu)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt otag = ecu | MC_OKIND_STACK;
    PROF_EVENT(MCPE_NEW_MEM_STACK_8);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
@@ -2943,6 +3047,7 @@ static void VG_REGPARM(2) mc_new_mem_sta
 MAYBE_USED
 static void VG_REGPARM(1) mc_new_mem_stack_8(Addr new_SP)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_NEW_MEM_STACK_8);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
       make_aligned_word64_undefined ( -VG_STACK_REDZONE_SZB + new_SP );
@@ -2957,6 +3062,7 @@ static void VG_REGPARM(1) mc_new_mem_sta
 MAYBE_USED
 static void VG_REGPARM(1) mc_die_mem_stack_8(Addr new_SP)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_DIE_MEM_STACK_8);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
       make_aligned_word64_noaccess ( -VG_STACK_REDZONE_SZB + new_SP-8 );
@@ -2973,6 +3079,7 @@ static void VG_REGPARM(1) mc_die_mem_sta
 MAYBE_USED
 static void VG_REGPARM(2) mc_new_mem_stack_12_w_ECU(Addr new_SP, UInt ecu)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt otag = ecu | MC_OKIND_STACK;
    PROF_EVENT(MCPE_NEW_MEM_STACK_12);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
@@ -2992,6 +3099,7 @@ static void VG_REGPARM(2) mc_new_mem_sta
 MAYBE_USED
 static void VG_REGPARM(1) mc_new_mem_stack_12(Addr new_SP)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_NEW_MEM_STACK_12);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
       make_aligned_word64_undefined ( -VG_STACK_REDZONE_SZB + new_SP );
@@ -3010,6 +3118,7 @@ static void VG_REGPARM(1) mc_new_mem_sta
 MAYBE_USED
 static void VG_REGPARM(1) mc_die_mem_stack_12(Addr new_SP)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_DIE_MEM_STACK_12);
    /* Note the -12 in the test */
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP-12 )) {
@@ -3033,6 +3142,7 @@ static void VG_REGPARM(1) mc_die_mem_sta
 MAYBE_USED
 static void VG_REGPARM(2) mc_new_mem_stack_16_w_ECU(Addr new_SP, UInt ecu)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt otag = ecu | MC_OKIND_STACK;
    PROF_EVENT(MCPE_NEW_MEM_STACK_16);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
@@ -3053,6 +3163,7 @@ static void VG_REGPARM(2) mc_new_mem_sta
 MAYBE_USED
 static void VG_REGPARM(1) mc_new_mem_stack_16(Addr new_SP)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_NEW_MEM_STACK_16);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
       /* Have 8-alignment at +0, hence do 8 at +0 and 8 at +8. */
@@ -3072,6 +3183,7 @@ static void VG_REGPARM(1) mc_new_mem_sta
 MAYBE_USED
 static void VG_REGPARM(1) mc_die_mem_stack_16(Addr new_SP)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_DIE_MEM_STACK_16);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
       /* Have 8-alignment at +0, hence do 8 at -16 and 8 at -8. */
@@ -3092,6 +3204,7 @@ static void VG_REGPARM(1) mc_die_mem_sta
 MAYBE_USED
 static void VG_REGPARM(2) mc_new_mem_stack_32_w_ECU(Addr new_SP, UInt ecu)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt otag = ecu | MC_OKIND_STACK;
    PROF_EVENT(MCPE_NEW_MEM_STACK_32);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
@@ -3116,6 +3229,7 @@ static void VG_REGPARM(2) mc_new_mem_sta
 MAYBE_USED
 static void VG_REGPARM(1) mc_new_mem_stack_32(Addr new_SP)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_NEW_MEM_STACK_32);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
       /* Straightforward */
@@ -3139,6 +3253,7 @@ static void VG_REGPARM(1) mc_new_mem_sta
 MAYBE_USED
 static void VG_REGPARM(1) mc_die_mem_stack_32(Addr new_SP)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_DIE_MEM_STACK_32);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
       /* Straightforward */
@@ -3164,6 +3279,7 @@ static void VG_REGPARM(1) mc_die_mem_sta
 MAYBE_USED
 static void VG_REGPARM(2) mc_new_mem_stack_112_w_ECU(Addr new_SP, UInt ecu)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt otag = ecu | MC_OKIND_STACK;
    PROF_EVENT(MCPE_NEW_MEM_STACK_112);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
@@ -3189,6 +3305,7 @@ static void VG_REGPARM(2) mc_new_mem_sta
 MAYBE_USED
 static void VG_REGPARM(1) mc_new_mem_stack_112(Addr new_SP)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_NEW_MEM_STACK_112);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
       make_aligned_word64_undefined ( -VG_STACK_REDZONE_SZB + new_SP );
@@ -3213,6 +3330,7 @@ static void VG_REGPARM(1) mc_new_mem_sta
 MAYBE_USED
 static void VG_REGPARM(1) mc_die_mem_stack_112(Addr new_SP)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_DIE_MEM_STACK_112);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
       make_aligned_word64_noaccess ( -VG_STACK_REDZONE_SZB + new_SP-112);
@@ -3239,6 +3357,7 @@ static void VG_REGPARM(1) mc_die_mem_sta
 MAYBE_USED
 static void VG_REGPARM(2) mc_new_mem_stack_128_w_ECU(Addr new_SP, UInt ecu)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt otag = ecu | MC_OKIND_STACK;
    PROF_EVENT(MCPE_NEW_MEM_STACK_128);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
@@ -3266,6 +3385,7 @@ static void VG_REGPARM(2) mc_new_mem_sta
 MAYBE_USED
 static void VG_REGPARM(1) mc_new_mem_stack_128(Addr new_SP)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_NEW_MEM_STACK_128);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
       make_aligned_word64_undefined ( -VG_STACK_REDZONE_SZB + new_SP );
@@ -3292,6 +3412,7 @@ static void VG_REGPARM(1) mc_new_mem_sta
 MAYBE_USED
 static void VG_REGPARM(1) mc_die_mem_stack_128(Addr new_SP)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_DIE_MEM_STACK_128);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
       make_aligned_word64_noaccess ( -VG_STACK_REDZONE_SZB + new_SP-128);
@@ -3320,6 +3441,7 @@ static void VG_REGPARM(1) mc_die_mem_sta
 MAYBE_USED
 static void VG_REGPARM(2) mc_new_mem_stack_144_w_ECU(Addr new_SP, UInt ecu)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt otag = ecu | MC_OKIND_STACK;
    PROF_EVENT(MCPE_NEW_MEM_STACK_144);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
@@ -3349,6 +3471,7 @@ static void VG_REGPARM(2) mc_new_mem_sta
 MAYBE_USED
 static void VG_REGPARM(1) mc_new_mem_stack_144(Addr new_SP)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_NEW_MEM_STACK_144);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
       make_aligned_word64_undefined ( -VG_STACK_REDZONE_SZB + new_SP );
@@ -3377,6 +3500,7 @@ static void VG_REGPARM(1) mc_new_mem_sta
 MAYBE_USED
 static void VG_REGPARM(1) mc_die_mem_stack_144(Addr new_SP)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_DIE_MEM_STACK_144);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
       make_aligned_word64_noaccess ( -VG_STACK_REDZONE_SZB + new_SP-144);
@@ -3407,6 +3531,7 @@ static void VG_REGPARM(1) mc_die_mem_sta
 MAYBE_USED
 static void VG_REGPARM(2) mc_new_mem_stack_160_w_ECU(Addr new_SP, UInt ecu)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt otag = ecu | MC_OKIND_STACK;
    PROF_EVENT(MCPE_NEW_MEM_STACK_160);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
@@ -3438,6 +3563,7 @@ static void VG_REGPARM(2) mc_new_mem_sta
 MAYBE_USED
 static void VG_REGPARM(1) mc_new_mem_stack_160(Addr new_SP)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_NEW_MEM_STACK_160);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
       make_aligned_word64_undefined ( -VG_STACK_REDZONE_SZB + new_SP );
@@ -3468,6 +3594,7 @@ static void VG_REGPARM(1) mc_new_mem_sta
 MAYBE_USED
 static void VG_REGPARM(1) mc_die_mem_stack_160(Addr new_SP)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_DIE_MEM_STACK_160);
    if (VG_IS_8_ALIGNED( -VG_STACK_REDZONE_SZB + new_SP )) {
       make_aligned_word64_noaccess ( -VG_STACK_REDZONE_SZB + new_SP-160);
@@ -3499,6 +3626,7 @@ static void VG_REGPARM(1) mc_die_mem_sta
 
 static void mc_new_mem_stack_w_ECU ( Addr a, SizeT len, UInt ecu )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt otag = ecu | MC_OKIND_STACK;
    PROF_EVENT(MCPE_NEW_MEM_STACK);
    MC_(make_mem_undefined_w_otag) ( -VG_STACK_REDZONE_SZB + a, len, otag );
@@ -3506,12 +3634,14 @@ static void mc_new_mem_stack_w_ECU ( Add
 
 static void mc_new_mem_stack ( Addr a, SizeT len )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_NEW_MEM_STACK);
    make_mem_undefined ( -VG_STACK_REDZONE_SZB + a, len );
 }
 
 static void mc_die_mem_stack ( Addr a, SizeT len )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_DIE_MEM_STACK);
    MC_(make_mem_noaccess) ( -VG_STACK_REDZONE_SZB + a, len );
 }
@@ -3564,6 +3694,7 @@ static WCacheEnt nia_to_ecu_cache[N_NIA_
 
 static void init_nia_to_ecu_cache ( void )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UWord       i;
    Addr        zero_addr = 0;
    ExeContext* zero_ec;
@@ -3585,6 +3716,7 @@ static void init_nia_to_ecu_cache ( void
 
 static inline UInt convert_nia_to_ecu ( Addr nia )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UWord i;
    UInt        ecu;
    ExeContext* ec;
@@ -3628,6 +3760,7 @@ static inline UInt convert_nia_to_ecu ( 
 VG_REGPARM(3)
 void MC_(helperc_MAKE_STACK_UNINIT_w_o) ( Addr base, UWord len, Addr nia )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_MAKE_STACK_UNINIT_W_O);
    if (0)
       VG_(printf)("helperc_MAKE_STACK_UNINIT_w_o (%#lx,%lu,nia=%#lx)\n",
@@ -3830,6 +3963,7 @@ void MC_(helperc_MAKE_STACK_UNINIT_w_o) 
 VG_REGPARM(2)
 void MC_(helperc_MAKE_STACK_UNINIT_no_o) ( Addr base, UWord len )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_MAKE_STACK_UNINIT_NO_O);
    if (0)
       VG_(printf)("helperc_MAKE_STACK_UNINIT_no_o (%#lx,%lu)\n",
@@ -3975,6 +4109,7 @@ void MC_(helperc_MAKE_STACK_UNINIT_no_o)
 VG_REGPARM(1)
 void MC_(helperc_MAKE_STACK_UNINIT_128_no_o) ( Addr base )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_MAKE_STACK_UNINIT_128_NO_O);
    if (0)
       VG_(printf)("helperc_MAKE_STACK_UNINIT_128_no_o (%#lx)\n", base );
@@ -4120,6 +4255,7 @@ typedef 
    similar. */
 Bool MC_(check_mem_is_noaccess) ( Addr a, SizeT len, Addr* bad_addr )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SizeT i;
    UWord vabits2;
 
@@ -4139,6 +4275,7 @@ Bool MC_(check_mem_is_noaccess) ( Addr a
 static Bool is_mem_addressable ( Addr a, SizeT len, 
                                  /*OUT*/Addr* bad_addr )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SizeT i;
    UWord vabits2;
 
@@ -4159,6 +4296,7 @@ static MC_ReadResult is_mem_defined ( Ad
                                       /*OUT*/Addr* bad_addr,
                                       /*OUT*/UInt* otag )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SizeT i;
    UWord vabits2;
 
@@ -4211,6 +4349,7 @@ static void is_mem_defined_comprehensive
                /*OUT*/Addr* bad_addrA  /* if so where? */
             )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SizeT i;
    UWord vabits2;
    Bool  already_saw_errV = False;
@@ -4258,6 +4397,7 @@ static void is_mem_defined_comprehensive
 
 static Bool mc_is_defined_asciiz ( Addr a, Addr* bad_addr, UInt* otag )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UWord vabits2;
 
    PROF_EVENT(MCPE_IS_DEFINED_ASCIIZ);
@@ -4302,6 +4442,7 @@ static
 void check_mem_is_addressable ( CorePart part, ThreadId tid, const HChar* s,
                                 Addr base, SizeT size )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Addr bad_addr;
    Bool ok = is_mem_addressable ( base, size, &bad_addr );
 
@@ -4326,6 +4467,7 @@ static
 void check_mem_is_defined ( CorePart part, ThreadId tid, const HChar* s,
                             Addr base, SizeT size )
 {     
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt otag = 0;
    Addr bad_addr;
    MC_ReadResult res = is_mem_defined ( base, size, &bad_addr, &otag );
@@ -4359,6 +4501,7 @@ static
 void check_mem_is_defined_asciiz ( CorePart part, ThreadId tid,
                                    const HChar* s, Addr str )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_ReadResult res;
    Addr bad_addr = 0;   // shut GCC up
    UInt otag = 0;
@@ -4430,6 +4573,7 @@ static
 void mc_new_mem_mmap ( Addr a, SizeT len, Bool rr, Bool ww, Bool xx,
                        ULong di_handle )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (rr || ww || xx) {
       /* (2) mmap/mprotect other -> defined */
       MC_(make_mem_defined)(a, len);
@@ -4442,6 +4586,7 @@ void mc_new_mem_mmap ( Addr a, SizeT len
 static
 void mc_new_mem_mprotect ( Addr a, SizeT len, Bool rr, Bool ww, Bool xx )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (rr || ww || xx) {
       /* (4) mprotect other  ->  change any "noaccess" to "defined" */
       make_mem_defined_if_noaccess(a, len);
@@ -4456,6 +4601,7 @@ static
 void mc_new_mem_startup( Addr a, SizeT len,
                          Bool rr, Bool ww, Bool xx, ULong di_handle )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    // Because code is defined, initialised variables get put in the data
    // segment and are defined, and uninitialised variables get put in the
    // bss segment and are auto-zeroed (and so defined).  
@@ -4479,6 +4625,7 @@ void mc_new_mem_startup( Addr a, SizeT l
 static
 void mc_post_mem_write(CorePart part, ThreadId tid, Addr a, SizeT len)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(make_mem_defined)(a, len);
 }
 
@@ -4493,6 +4640,7 @@ void mc_post_mem_write(CorePart part, Th
 static UInt mb_get_origin_for_guest_offset ( ThreadId tid,
                                              Int offset, SizeT size )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int   sh2off;
    UInt  area[3];
    UInt  otag;
@@ -4519,6 +4667,7 @@ static UInt mb_get_origin_for_guest_offs
 static void mc_post_reg_write ( CorePart part, ThreadId tid, 
                                 PtrdiffT offset, SizeT size)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 #  define MAX_REG_WRITE_SIZE 1744
    UChar area[MAX_REG_WRITE_SIZE];
    tl_assert(size <= MAX_REG_WRITE_SIZE);
@@ -4531,6 +4680,7 @@ static 
 void mc_post_reg_write_clientcall ( ThreadId tid, 
                                     PtrdiffT offset, SizeT size, Addr f)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    mc_post_reg_write(/*dummy*/0, tid, offset, size);
 }
 
@@ -4541,6 +4691,7 @@ void mc_post_reg_write_clientcall ( Thre
 static void mc_pre_reg_read ( CorePart part, ThreadId tid, const HChar* s, 
                               PtrdiffT offset, SizeT size)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int   i;
    Bool  bad;
    UInt  otag;
@@ -4575,6 +4726,7 @@ static void mc_pre_reg_read ( CorePart p
 static void mc_copy_mem_to_reg ( CorePart part, ThreadId tid, Addr a,
                                  PtrdiffT guest_state_offset, SizeT size )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SizeT i;
    UChar vbits8;
    Int offset;
@@ -4625,6 +4777,7 @@ static void mc_copy_reg_to_mem ( CorePar
                                  PtrdiffT guest_state_offset, Addr a,
                                  SizeT size )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SizeT i;
    UChar vbits8;
    Int offset;
@@ -4800,6 +4953,7 @@ static INLINE
 void mc_LOADV_128_or_256 ( /*OUT*/ULong* res,
                            Addr a, SizeT nBits, Bool isBigEndian )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_LOADV_128_OR_256);
 
 #ifndef PERF_FAST_LOADV
@@ -4846,19 +5000,23 @@ void mc_LOADV_128_or_256 ( /*OUT*/ULong*
 
 VG_REGPARM(2) void MC_(helperc_LOADV256be) ( /*OUT*/V256* res, Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    mc_LOADV_128_or_256(&res->w64[0], a, 256, True);
 }
 VG_REGPARM(2) void MC_(helperc_LOADV256le) ( /*OUT*/V256* res, Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    mc_LOADV_128_or_256(&res->w64[0], a, 256, False);
 }
 
 VG_REGPARM(2) void MC_(helperc_LOADV128be) ( /*OUT*/V128* res, Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    mc_LOADV_128_or_256(&res->w64[0], a, 128, True);
 }
 VG_REGPARM(2) void MC_(helperc_LOADV128le) ( /*OUT*/V128* res, Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    mc_LOADV_128_or_256(&res->w64[0], a, 128, False);
 }
 
@@ -4869,6 +5027,7 @@ VG_REGPARM(2) void MC_(helperc_LOADV128l
 static INLINE
 ULong mc_LOADV64 ( Addr a, Bool isBigEndian )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_LOADV64);
 
 #ifndef PERF_FAST_LOADV
@@ -4906,6 +5065,7 @@ ULong mc_LOADV64 ( Addr a, Bool isBigEnd
 // Generic for all platforms
 VG_REGPARM(1) ULong MC_(helperc_LOADV64be) ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return mc_LOADV64(a, True);
 }
 
@@ -4922,6 +5082,7 @@ VG_REGPARM(1) ULong MC_(helperc_LOADV64b
 // Generic for all platforms except {arm32,x86}-linux and x86-solaris
 VG_REGPARM(1) ULong MC_(helperc_LOADV64le) ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return mc_LOADV64(a, False);
 }
 #endif
@@ -4933,6 +5094,7 @@ VG_REGPARM(1) ULong MC_(helperc_LOADV64l
 static INLINE
 void mc_STOREV64 ( Addr a, ULong vbits64, Bool isBigEndian )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_STOREV64);
 
 #ifndef PERF_FAST_STOREV
@@ -4989,10 +5151,12 @@ void mc_STOREV64 ( Addr a, ULong vbits64
 
 VG_REGPARM(1) void MC_(helperc_STOREV64be) ( Addr a, ULong vbits64 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    mc_STOREV64(a, vbits64, True);
 }
 VG_REGPARM(1) void MC_(helperc_STOREV64le) ( Addr a, ULong vbits64 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    mc_STOREV64(a, vbits64, False);
 }
 
@@ -5003,6 +5167,7 @@ VG_REGPARM(1) void MC_(helperc_STOREV64l
 static INLINE
 UWord mc_LOADV32 ( Addr a, Bool isBigEndian )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_LOADV32);
 
 #ifndef PERF_FAST_LOADV
@@ -5042,6 +5207,7 @@ UWord mc_LOADV32 ( Addr a, Bool isBigEnd
 // Generic for all platforms
 VG_REGPARM(1) UWord MC_(helperc_LOADV32be) ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return mc_LOADV32(a, True);
 }
 
@@ -5058,7 +5224,10 @@ VG_REGPARM(1) UWord MC_(helperc_LOADV32b
 // Generic for all platforms except {arm32,x86}-linux and x86-solaris
 VG_REGPARM(1) UWord MC_(helperc_LOADV32le) ( Addr a )
 {
-   return mc_LOADV32(a, False);
+VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
+   UWord return1 =  mc_LOADV32(a, False);
+VG_(debugLog)(2, "initimg", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
+   return return1;
 }
 #endif
 
@@ -5069,6 +5238,7 @@ VG_REGPARM(1) UWord MC_(helperc_LOADV32l
 static INLINE
 void mc_STOREV32 ( Addr a, UWord vbits32, Bool isBigEndian )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_STOREV32);
 
 #ifndef PERF_FAST_STOREV
@@ -5119,15 +5289,20 @@ void mc_STOREV32 ( Addr a, UWord vbits32
       mc_STOREVn_slow( a, 32, (ULong)vbits32, isBigEndian );
    }
 #endif
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 VG_REGPARM(2) void MC_(helperc_STOREV32be) ( Addr a, UWord vbits32 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    mc_STOREV32(a, vbits32, True);
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 VG_REGPARM(2) void MC_(helperc_STOREV32le) ( Addr a, UWord vbits32 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    mc_STOREV32(a, vbits32, False);
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 /*------------------------------------------------------------*/
@@ -5137,6 +5312,7 @@ VG_REGPARM(2) void MC_(helperc_STOREV32l
 static INLINE
 UWord mc_LOADV16 ( Addr a, Bool isBigEndian )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_LOADV16);
 
 #ifndef PERF_FAST_LOADV
@@ -5173,11 +5349,13 @@ UWord mc_LOADV16 ( Addr a, Bool isBigEnd
       }
    }
 #endif
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 // Generic for all platforms
 VG_REGPARM(1) UWord MC_(helperc_LOADV16be) ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return mc_LOADV16(a, True);
 }
 
@@ -5295,6 +5473,7 @@ VG_REGPARM(1) UWord MC_(helperc_LOADV16l
 static INLINE
 Bool accessible_vabits4_in_vabits8 ( Addr a, UChar vabits8 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt shift;
    tl_assert(VG_IS_2_ALIGNED(a));      // Must be 2-aligned
    shift = (a & 2) << 1;               // shift by 0 or 4
@@ -5307,6 +5486,7 @@ Bool accessible_vabits4_in_vabits8 ( Add
 static INLINE
 void mc_STOREV16 ( Addr a, UWord vbits16, Bool isBigEndian )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_STOREV16);
 
 #ifndef PERF_FAST_STOREV
@@ -5365,10 +5545,12 @@ void mc_STOREV16 ( Addr a, UWord vbits16
 
 VG_REGPARM(2) void MC_(helperc_STOREV16be) ( Addr a, UWord vbits16 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    mc_STOREV16(a, vbits16, True);
 }
 VG_REGPARM(2) void MC_(helperc_STOREV16le) ( Addr a, UWord vbits16 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    mc_STOREV16(a, vbits16, False);
 }
 
@@ -5475,6 +5657,7 @@ __asm__(
 VG_REGPARM(1)
 UWord MC_(helperc_LOADV8) ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_LOADV8);
 
 #ifndef PERF_FAST_LOADV
@@ -5521,6 +5704,7 @@ UWord MC_(helperc_LOADV8) ( Addr a )
 VG_REGPARM(2)
 void MC_(helperc_STOREV8) ( Addr a, UWord vbits8 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    PROF_EVENT(MCPE_STOREV8);
 
 #ifndef PERF_FAST_STOREV
@@ -5624,54 +5808,74 @@ void MC_(helperc_STOREV8) ( Addr a, UWor
 /* Call these ones when an origin is available ... */
 VG_REGPARM(1)
 void MC_(helperc_value_check0_fail_w_o) ( UWord origin ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(record_cond_error) ( VG_(get_running_tid)(), (UInt)origin );
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 VG_REGPARM(1)
 void MC_(helperc_value_check1_fail_w_o) ( UWord origin ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(record_value_error) ( VG_(get_running_tid)(), 1, (UInt)origin );
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 VG_REGPARM(1)
 void MC_(helperc_value_check4_fail_w_o) ( UWord origin ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(record_value_error) ( VG_(get_running_tid)(), 4, (UInt)origin );
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 VG_REGPARM(1)
 void MC_(helperc_value_check8_fail_w_o) ( UWord origin ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(record_value_error) ( VG_(get_running_tid)(), 8, (UInt)origin );
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 VG_REGPARM(2) 
 void MC_(helperc_value_checkN_fail_w_o) ( HWord sz, UWord origin ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(record_value_error) ( VG_(get_running_tid)(), (Int)sz, (UInt)origin );
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 /* ... and these when an origin isn't available. */
 
 VG_REGPARM(0)
 void MC_(helperc_value_check0_fail_no_o) ( void ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(record_cond_error) ( VG_(get_running_tid)(), 0/*origin*/ );
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 VG_REGPARM(0)
 void MC_(helperc_value_check1_fail_no_o) ( void ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(record_value_error) ( VG_(get_running_tid)(), 1, 0/*origin*/ );
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 VG_REGPARM(0)
 void MC_(helperc_value_check4_fail_no_o) ( void ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(record_value_error) ( VG_(get_running_tid)(), 4, 0/*origin*/ );
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 VG_REGPARM(0)
 void MC_(helperc_value_check8_fail_no_o) ( void ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(record_value_error) ( VG_(get_running_tid)(), 8, 0/*origin*/ );
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 VG_REGPARM(1) 
 void MC_(helperc_value_checkN_fail_no_o) ( HWord sz ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(record_value_error) ( VG_(get_running_tid)(), (Int)sz, 0/*origin*/ );
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
 }
 
 
@@ -5697,6 +5901,7 @@ static Int mc_get_or_set_vbits_for_clien
                              False <=> internal call from gdbserver */ 
 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SizeT i;
    Bool  ok;
    UChar vbits8;
@@ -5743,6 +5948,7 @@ static Int mc_get_or_set_vbits_for_clien
 */
 Bool MC_(is_within_valid_secondary) ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SecMap* sm = maybe_get_secmap_for ( a );
    if (sm == NULL || sm == &sm_distinguished[SM_DIST_NOACCESS]) {
       /* Definitely not in use. */
@@ -5757,6 +5963,7 @@ Bool MC_(is_within_valid_secondary) ( Ad
    address is to be regarded as valid. */
 Bool MC_(is_valid_aligned_word) ( Addr a )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(sizeof(UWord) == 4 || sizeof(UWord) == 8);
    tl_assert(VG_IS_WORD_ALIGNED(a));
    if (get_vabits8_for_aligned_word32 (a) != VA_BITS8_DEFINED)
@@ -5778,6 +5985,7 @@ Bool MC_(is_valid_aligned_word) ( Addr a
 
 static void init_shadow_memory ( void )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int     i;
    SecMap* sm;
 
@@ -5819,6 +6027,7 @@ static void init_shadow_memory ( void )
 
 static Bool mc_cheap_sanity_check ( void )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    n_sanity_cheap++;
    PROF_EVENT(MCPE_CHEAP_SANITY_CHECK);
    /* Check for sane operating level */
@@ -5830,6 +6039,7 @@ static Bool mc_cheap_sanity_check ( void
 
 static Bool mc_expensive_sanity_check ( void )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int     i;
    Word    n_secmaps_found;
    SecMap* sm;
@@ -5963,6 +6173,7 @@ static const HChar * MC_(parse_leak_heur
 
 static Bool mc_process_cmd_line_options(const HChar* arg)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    const HChar* tmp_str;
    Int   tmp_show;
 
@@ -6168,6 +6379,7 @@ static Bool mc_process_cmd_line_options(
 
 static void mc_print_usage(void)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    VG_(printf)(
 "    --leak-check=no|summary|full     search for memory leaks at exit?  [summary]\n"
 "    --leak-resolution=low|med|high   differentiation of leak stack traces [high]\n"
@@ -6210,6 +6422,7 @@ static void mc_print_usage(void)
 
 static void mc_print_debug_usage(void)
 {  
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    VG_(printf)(
 "    (none)\n"
    );
@@ -6250,6 +6463,7 @@ static ULong cgb_search   = 0;   /* Numb
 void MC_(get_ClientBlock_array)( /*OUT*/CGenBlock** blocks,
                                  /*OUT*/UWord* nBlocks )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    *blocks  = cgbs;
    *nBlocks = cgb_used;
 }
@@ -6258,6 +6472,7 @@ void MC_(get_ClientBlock_array)( /*OUT*/
 static
 Int alloc_client_block ( void )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UWord      i, sz_new;
    CGenBlock* cgbs_new;
 
@@ -6297,6 +6512,7 @@ Int alloc_client_block ( void )
 
 static void show_client_block_stats ( void )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    VG_(message)(Vg_DebugMsg, 
       "general CBs: %llu allocs, %llu discards, %llu maxinuse, %llu search\n",
       cgb_allocs, cgb_discards, cgb_used_MAX, cgb_search 
@@ -6304,6 +6520,7 @@ static void show_client_block_stats ( vo
 }
 static void print_monitor_help ( void )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    VG_(gdb_printf) 
       (
 "\n"
@@ -6358,6 +6575,7 @@ static void print_monitor_help ( void )
    res[i] == 1 indicates the corresponding byte is addressable. */
 static void gdb_xb (Addr address, SizeT szB, Int res[])
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt i;
 
    for (i = 0; i < szB; i++) {
@@ -6380,6 +6598,7 @@ static void gdb_xb (Addr address, SizeT 
    or address of the string terminator. */
 static HChar* next_non_space (HChar *s)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    while (*s && *s == ' ')
       s++;
    return s;
@@ -6393,6 +6612,7 @@ static HChar* next_non_space (HChar *s)
 static Bool VG_(parse_slice) (HChar* s, HChar** saveptr,
                               UInt *from, UInt *to)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    HChar* wl;
    HChar *endptr;
    endptr = NULL;////
@@ -6453,6 +6673,7 @@ static Bool VG_(parse_slice) (HChar* s, 
 /* return True if request recognised, False otherwise */
 static Bool handle_gdb_monitor_command (ThreadId tid, HChar *req)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    HChar* wcmd;
    HChar s[VG_(strlen)(req) + 1]; /* copy for strtok_r */
    HChar *ssaveptr;
@@ -6856,6 +7077,7 @@ static Bool handle_gdb_monitor_command (
 
 static Bool mc_handle_client_request ( ThreadId tid, UWord* arg, UWord* ret )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int   i;
    Addr  bad_addr;
 
@@ -7334,6 +7556,7 @@ static const HChar* MC_(event_ctr_name)[
 
 static void init_prof_mem ( void )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int i, name_count = 0;
 
    for (i = 0; i < MCPE_LAST; i++) {
@@ -7348,6 +7571,7 @@ static void init_prof_mem ( void )
 
 static void done_prof_mem ( void )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int  i, n;
    Bool spaced = False;
    for (i = n = 0; i < MCPE_LAST; i++) {
@@ -7367,8 +7591,8 @@ static void done_prof_mem ( void )
 
 #else
 
-static void init_prof_mem ( void ) { }
-static void done_prof_mem ( void ) { }
+static void init_prof_mem ( void ) { VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);}
+static void done_prof_mem ( void ) { VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);}
 
 #endif
 
@@ -7382,10 +7606,12 @@ static void done_prof_mem ( void ) { }
 /*--------------------------------------------*/
 
 static INLINE UInt merge_origins ( UInt or1, UInt or2 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return or1 > or2 ? or1 : or2;
 }
 
 UWord VG_REGPARM(1) MC_(helperc_b_load1)( Addr a ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    OCacheLine* line;
    UChar descr;
    UWord lineoff = oc_line_offset(a);
@@ -7410,6 +7636,7 @@ UWord VG_REGPARM(1) MC_(helperc_b_load1)
 }
 
 UWord VG_REGPARM(1) MC_(helperc_b_load2)( Addr a ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    OCacheLine* line;
    UChar descr;
    UWord lineoff, byteoff;
@@ -7442,6 +7669,7 @@ UWord VG_REGPARM(1) MC_(helperc_b_load2)
 }
 
 UWord VG_REGPARM(1) MC_(helperc_b_load4)( Addr a ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    OCacheLine* line;
    UChar descr;
    UWord lineoff;
@@ -7473,6 +7701,7 @@ UWord VG_REGPARM(1) MC_(helperc_b_load4)
 }
 
 UWord VG_REGPARM(1) MC_(helperc_b_load8)( Addr a ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    OCacheLine* line;
    UChar descrLo, descrHi, descr;
    UWord lineoff;
@@ -7508,6 +7737,7 @@ UWord VG_REGPARM(1) MC_(helperc_b_load8)
 }
 
 UWord VG_REGPARM(1) MC_(helperc_b_load16)( Addr a ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt oLo   = (UInt)MC_(helperc_b_load8)( a + 0 );
    UInt oHi   = (UInt)MC_(helperc_b_load8)( a + 8 );
    UInt oBoth = merge_origins(oLo, oHi);
@@ -7515,6 +7745,7 @@ UWord VG_REGPARM(1) MC_(helperc_b_load16
 }
 
 UWord VG_REGPARM(1) MC_(helperc_b_load32)( Addr a ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt oQ0   = (UInt)MC_(helperc_b_load8)( a + 0 );
    UInt oQ1   = (UInt)MC_(helperc_b_load8)( a + 8 );
    UInt oQ2   = (UInt)MC_(helperc_b_load8)( a + 16 );
@@ -7530,6 +7761,7 @@ UWord VG_REGPARM(1) MC_(helperc_b_load32
 /*--------------------------------------------*/
 
 void VG_REGPARM(2) MC_(helperc_b_store1)( Addr a, UWord d32 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    OCacheLine* line;
    UWord lineoff = oc_line_offset(a);
    UWord byteoff = a & 3; /* 0, 1, 2 or 3 */
@@ -7549,6 +7781,7 @@ void VG_REGPARM(2) MC_(helperc_b_store1)
 }
 
 void VG_REGPARM(2) MC_(helperc_b_store2)( Addr a, UWord d32 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    OCacheLine* line;
    UWord lineoff, byteoff;
 
@@ -7577,6 +7810,7 @@ void VG_REGPARM(2) MC_(helperc_b_store2)
 }
 
 void VG_REGPARM(2) MC_(helperc_b_store4)( Addr a, UWord d32 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    OCacheLine* line;
    UWord lineoff;
 
@@ -7603,6 +7837,7 @@ void VG_REGPARM(2) MC_(helperc_b_store4)
 }
 
 void VG_REGPARM(2) MC_(helperc_b_store8)( Addr a, UWord d32 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    OCacheLine* line;
    UWord lineoff;
 
@@ -7632,11 +7867,13 @@ void VG_REGPARM(2) MC_(helperc_b_store8)
 }
 
 void VG_REGPARM(2) MC_(helperc_b_store16)( Addr a, UWord d32 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(helperc_b_store8)( a + 0, d32 );
    MC_(helperc_b_store8)( a + 8, d32 );
 }
 
 void VG_REGPARM(2) MC_(helperc_b_store32)( Addr a, UWord d32 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(helperc_b_store8)( a +  0, d32 );
    MC_(helperc_b_store8)( a +  8, d32 );
    MC_(helperc_b_store8)( a + 16, d32 );
@@ -7650,6 +7887,7 @@ void VG_REGPARM(2) MC_(helperc_b_store32
 
 __attribute__((noinline))
 static void ocache_sarp_Set_Origins ( Addr a, UWord len, UInt otag ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if ((a & 1) && len >= 1) {
       MC_(helperc_b_store1)( a, otag );
       a++;
@@ -7682,6 +7920,7 @@ static void ocache_sarp_Set_Origins ( Ad
 
 __attribute__((noinline))
 static void ocache_sarp_Clear_Origins ( Addr a, UWord len ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if ((a & 1) && len >= 1) {
       MC_(helperc_b_store1)( a, 0 );
       a++;
@@ -7719,6 +7958,7 @@ static void ocache_sarp_Clear_Origins ( 
 
 static void mc_post_clo_init ( void )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    /* If we've been asked to emit XML, mash around various other
       options so as to constrain the output somewhat. */
    if (VG_(clo_xml)) {
@@ -7875,6 +8115,7 @@ static void mc_post_clo_init ( void )
 
 static void print_SM_info(const HChar* type, Int n_SMs)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    VG_(message)(Vg_DebugMsg,
       " memcheck: SMs: %s = %d (%luk, %luM)\n",
       type,
@@ -7885,6 +8126,7 @@ static void print_SM_info(const HChar* t
 
 static void mc_print_stats (void)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    SizeT max_secVBit_szB, max_SMs_szB, max_shmem_szB;
 
    VG_(message)(Vg_DebugMsg, " memcheck: freelist: vol %lld length %lld\n",
@@ -7979,6 +8221,7 @@ static void mc_print_stats (void)
 
 static void mc_fini ( Int exitcode )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    MC_(xtmemory_report) (VG_(clo_xtree_memory_file), True);
    MC_(print_malloc_stats)();
 
@@ -8076,6 +8319,7 @@ static void mc_fini ( Int exitcode )
 static Bool mc_mark_unaddressable_for_watchpoint (PointKind kind, Bool insert,
                                                   Addr addr, SizeT len)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    /* GDBTD this is somewhat fishy. We might rather have to save the previous
       accessibility and definedness in gdbserver so as to allow restoring it
       properly. Currently, we assume that the user only watches things
@@ -8089,6 +8333,7 @@ static Bool mc_mark_unaddressable_for_wa
 
 static void mc_pre_clo_init(void)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    VG_(details_name)            ("Memcheck");
    VG_(details_version)         (NULL);
    VG_(details_description)     ("a memory error detector");
