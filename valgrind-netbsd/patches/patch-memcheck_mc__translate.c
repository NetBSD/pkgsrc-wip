$NetBSD$

--- memcheck/mc_translate.c.orig	2018-09-30 04:41:00.000000000 +0000
+++ memcheck/mc_translate.c
@@ -196,6 +196,7 @@ typedef
 static void DetailLevelByOp__set_all ( /*OUT*/DetailLevelByOp* dlbo,
                                        DetailLevel dl )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    dlbo->dl_Add32           = dl;
    dlbo->dl_Add64           = dl;
    dlbo->dl_Sub32           = dl;
@@ -208,6 +209,7 @@ static void DetailLevelByOp__set_all ( /
 
 static void DetailLevelByOp__check_sanity ( const DetailLevelByOp* dlbo )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(dlbo->dl_Add32 >= DLcheap && dlbo->dl_Add32 <= DLexpensive);
    tl_assert(dlbo->dl_Add64 >= DLcheap && dlbo->dl_Add64 <= DLexpensive);
    tl_assert(dlbo->dl_Sub32 >= DLcheap && dlbo->dl_Sub32 <= DLexpensive);
@@ -225,6 +227,7 @@ static void DetailLevelByOp__check_sanit
 static UInt DetailLevelByOp__count ( const DetailLevelByOp* dlbo,
                                      DetailLevel dl )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt n = 0;
    n += (dlbo->dl_Add32 == dl            ? 1 : 0);
    n += (dlbo->dl_Add64 == dl            ? 1 : 0);
@@ -366,6 +369,7 @@ typedef
    from VG_(indexXA)(mce->tmpMap) are invalidated. */
 static IRTemp newTemp ( MCEnv* mce, IRType ty, TempKind kind )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Word       newIx;
    TempMapEnt ent;
    IRTemp     tmp = newIRTemp(mce->sb->tyenv, ty);
@@ -382,6 +386,7 @@ static IRTemp newTemp ( MCEnv* mce, IRTy
    so far exists, allocate one.  */
 static IRTemp findShadowTmpV ( MCEnv* mce, IRTemp orig )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    TempMapEnt* ent;
    /* VG_(indexXA) range-checks 'orig', hence no need to check
       here. */
@@ -412,6 +417,7 @@ static IRTemp findShadowTmpV ( MCEnv* mc
    regardless. */
 static void newShadowTmpV ( MCEnv* mce, IRTemp orig )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    TempMapEnt* ent;
    /* VG_(indexXA) range-checks 'orig', hence no need to check
       here. */
@@ -446,6 +452,7 @@ typedef  IRExpr  IRAtom;
    like it's from original code? */
 static Bool isOriginalAtom ( MCEnv* mce, IRAtom* a1 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (a1->tag == Iex_Const)
       return True;
    if (a1->tag == Iex_RdTmp) {
@@ -459,6 +466,7 @@ static Bool isOriginalAtom ( MCEnv* mce,
    like it's from shadow code? */
 static Bool isShadowAtom ( MCEnv* mce, IRAtom* a1 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (a1->tag == Iex_Const)
       return True;
    if (a1->tag == Iex_RdTmp) {
@@ -472,6 +480,7 @@ static Bool isShadowAtom ( MCEnv* mce, I
    are identically-kinded. */
 static Bool sameKindedAtoms ( IRAtom* a1, IRAtom* a2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (a1->tag == Iex_RdTmp && a2->tag == Iex_RdTmp)
       return True;
    if (a1->tag == Iex_Const && a2->tag == Iex_Const)
@@ -491,6 +500,7 @@ static Bool sameKindedAtoms ( IRAtom* a1
 
 static IRType shadowTypeV ( IRType ty )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    switch (ty) {
       case Ity_I1:
       case Ity_I8:
@@ -515,6 +525,7 @@ static IRType shadowTypeV ( IRType ty )
 /* Produce a 'defined' value of the given shadow type.  Should only be
    supplied shadow types (Bit/I8/I16/I32/UI64). */
 static IRExpr* definedOfType ( IRType ty ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    switch (ty) {
       case Ity_I1:   return IRExpr_Const(IRConst_U1(False));
       case Ity_I8:   return IRExpr_Const(IRConst_U8(0));
@@ -535,6 +546,7 @@ static IRExpr* definedOfType ( IRType ty
 
 /* add stmt to a bb */
 static inline void stmt ( HChar cat, MCEnv* mce, IRStmt* st ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (mce->trace) {
       VG_(printf)("  %c: ", cat);
       ppIRStmt(st);
@@ -546,6 +558,7 @@ static inline void stmt ( HChar cat, MCE
 /* assign value to tmp */
 static inline 
 void assign ( HChar cat, MCEnv* mce, IRTemp tmp, IRExpr* expr ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    stmt(cat, mce, IRStmt_WrTmp(tmp,expr));
 }
 
@@ -572,6 +585,7 @@ void assign ( HChar cat, MCEnv* mce, IRT
    assert that the two types agree. */
 static IRAtom* assignNew ( HChar cat, MCEnv* mce, IRType ty, IRExpr* e )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    TempKind k;
    IRTemp   t;
    IRType   tyE = typeOfIRExpr(mce->sb->tyenv, e);
@@ -597,6 +611,7 @@ static IRAtom* assignNew ( HChar cat, MC
 
 static IRExpr *i128_const_zero(void)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* z64 = IRExpr_Const(IRConst_U64(0));
    return binop(Iop_64HLto128, z64, z64);
 }
@@ -613,36 +628,42 @@ static IRExpr *i128_const_zero(void)
 /* --------- Defined-if-either-defined --------- */
 
 static IRAtom* mkDifD8 ( MCEnv* mce, IRAtom* a1, IRAtom* a2 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isShadowAtom(mce,a1));
    tl_assert(isShadowAtom(mce,a2));
    return assignNew('V', mce, Ity_I8, binop(Iop_And8, a1, a2));
 }
 
 static IRAtom* mkDifD16 ( MCEnv* mce, IRAtom* a1, IRAtom* a2 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isShadowAtom(mce,a1));
    tl_assert(isShadowAtom(mce,a2));
    return assignNew('V', mce, Ity_I16, binop(Iop_And16, a1, a2));
 }
 
 static IRAtom* mkDifD32 ( MCEnv* mce, IRAtom* a1, IRAtom* a2 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isShadowAtom(mce,a1));
    tl_assert(isShadowAtom(mce,a2));
    return assignNew('V', mce, Ity_I32, binop(Iop_And32, a1, a2));
 }
 
 static IRAtom* mkDifD64 ( MCEnv* mce, IRAtom* a1, IRAtom* a2 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isShadowAtom(mce,a1));
    tl_assert(isShadowAtom(mce,a2));
    return assignNew('V', mce, Ity_I64, binop(Iop_And64, a1, a2));
 }
 
 static IRAtom* mkDifDV128 ( MCEnv* mce, IRAtom* a1, IRAtom* a2 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isShadowAtom(mce,a1));
    tl_assert(isShadowAtom(mce,a2));
    return assignNew('V', mce, Ity_V128, binop(Iop_AndV128, a1, a2));
 }
 
 static IRAtom* mkDifDV256 ( MCEnv* mce, IRAtom* a1, IRAtom* a2 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isShadowAtom(mce,a1));
    tl_assert(isShadowAtom(mce,a2));
    return assignNew('V', mce, Ity_V256, binop(Iop_AndV256, a1, a2));
@@ -651,30 +672,35 @@ static IRAtom* mkDifDV256 ( MCEnv* mce, 
 /* --------- Undefined-if-either-undefined --------- */
 
 static IRAtom* mkUifU8 ( MCEnv* mce, IRAtom* a1, IRAtom* a2 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isShadowAtom(mce,a1));
    tl_assert(isShadowAtom(mce,a2));
    return assignNew('V', mce, Ity_I8, binop(Iop_Or8, a1, a2));
 }
 
 static IRAtom* mkUifU16 ( MCEnv* mce, IRAtom* a1, IRAtom* a2 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isShadowAtom(mce,a1));
    tl_assert(isShadowAtom(mce,a2));
    return assignNew('V', mce, Ity_I16, binop(Iop_Or16, a1, a2));
 }
 
 static IRAtom* mkUifU32 ( MCEnv* mce, IRAtom* a1, IRAtom* a2 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isShadowAtom(mce,a1));
    tl_assert(isShadowAtom(mce,a2));
    return assignNew('V', mce, Ity_I32, binop(Iop_Or32, a1, a2));
 }
 
 static IRAtom* mkUifU64 ( MCEnv* mce, IRAtom* a1, IRAtom* a2 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isShadowAtom(mce,a1));
    tl_assert(isShadowAtom(mce,a2));
    return assignNew('V', mce, Ity_I64, binop(Iop_Or64, a1, a2));
 }
 
 static IRAtom* mkUifU128 ( MCEnv* mce, IRAtom* a1, IRAtom* a2 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom *tmp1, *tmp2, *tmp3, *tmp4, *tmp5, *tmp6;
    tl_assert(isShadowAtom(mce,a1));
    tl_assert(isShadowAtom(mce,a2));
@@ -689,18 +715,21 @@ static IRAtom* mkUifU128 ( MCEnv* mce, I
 }
 
 static IRAtom* mkUifUV128 ( MCEnv* mce, IRAtom* a1, IRAtom* a2 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isShadowAtom(mce,a1));
    tl_assert(isShadowAtom(mce,a2));
    return assignNew('V', mce, Ity_V128, binop(Iop_OrV128, a1, a2));
 }
 
 static IRAtom* mkUifUV256 ( MCEnv* mce, IRAtom* a1, IRAtom* a2 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isShadowAtom(mce,a1));
    tl_assert(isShadowAtom(mce,a2));
    return assignNew('V', mce, Ity_V256, binop(Iop_OrV256, a1, a2));
 }
 
 static IRAtom* mkUifU ( MCEnv* mce, IRType vty, IRAtom* a1, IRAtom* a2 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    switch (vty) {
       case Ity_I8:   return mkUifU8(mce, a1, a2);
       case Ity_I16:  return mkUifU16(mce, a1, a2);
@@ -718,21 +747,25 @@ static IRAtom* mkUifU ( MCEnv* mce, IRTy
 /* --------- The Left-family of operations. --------- */
 
 static IRAtom* mkLeft8 ( MCEnv* mce, IRAtom* a1 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isShadowAtom(mce,a1));
    return assignNew('V', mce, Ity_I8, unop(Iop_Left8, a1));
 }
 
 static IRAtom* mkLeft16 ( MCEnv* mce, IRAtom* a1 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isShadowAtom(mce,a1));
    return assignNew('V', mce, Ity_I16, unop(Iop_Left16, a1));
 }
 
 static IRAtom* mkLeft32 ( MCEnv* mce, IRAtom* a1 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isShadowAtom(mce,a1));
    return assignNew('V', mce, Ity_I32, unop(Iop_Left32, a1));
 }
 
 static IRAtom* mkLeft64 ( MCEnv* mce, IRAtom* a1 ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isShadowAtom(mce,a1));
    return assignNew('V', mce, Ity_I64, unop(Iop_Left64, a1));
 }
@@ -744,6 +777,7 @@ static IRAtom* mkLeft64 ( MCEnv* mce, IR
 */
 static IRAtom* mkImproveAND8 ( MCEnv* mce, IRAtom* data, IRAtom* vbits )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isOriginalAtom(mce, data));
    tl_assert(isShadowAtom(mce, vbits));
    tl_assert(sameKindedAtoms(data, vbits));
@@ -752,6 +786,7 @@ static IRAtom* mkImproveAND8 ( MCEnv* mc
 
 static IRAtom* mkImproveAND16 ( MCEnv* mce, IRAtom* data, IRAtom* vbits )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isOriginalAtom(mce, data));
    tl_assert(isShadowAtom(mce, vbits));
    tl_assert(sameKindedAtoms(data, vbits));
@@ -760,6 +795,7 @@ static IRAtom* mkImproveAND16 ( MCEnv* m
 
 static IRAtom* mkImproveAND32 ( MCEnv* mce, IRAtom* data, IRAtom* vbits )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isOriginalAtom(mce, data));
    tl_assert(isShadowAtom(mce, vbits));
    tl_assert(sameKindedAtoms(data, vbits));
@@ -768,6 +804,7 @@ static IRAtom* mkImproveAND32 ( MCEnv* m
 
 static IRAtom* mkImproveAND64 ( MCEnv* mce, IRAtom* data, IRAtom* vbits )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isOriginalAtom(mce, data));
    tl_assert(isShadowAtom(mce, vbits));
    tl_assert(sameKindedAtoms(data, vbits));
@@ -776,6 +813,7 @@ static IRAtom* mkImproveAND64 ( MCEnv* m
 
 static IRAtom* mkImproveANDV128 ( MCEnv* mce, IRAtom* data, IRAtom* vbits )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isOriginalAtom(mce, data));
    tl_assert(isShadowAtom(mce, vbits));
    tl_assert(sameKindedAtoms(data, vbits));
@@ -784,6 +822,7 @@ static IRAtom* mkImproveANDV128 ( MCEnv*
 
 static IRAtom* mkImproveANDV256 ( MCEnv* mce, IRAtom* data, IRAtom* vbits )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isOriginalAtom(mce, data));
    tl_assert(isShadowAtom(mce, vbits));
    tl_assert(sameKindedAtoms(data, vbits));
@@ -795,6 +834,7 @@ static IRAtom* mkImproveANDV256 ( MCEnv*
 */
 static IRAtom* mkImproveOR8 ( MCEnv* mce, IRAtom* data, IRAtom* vbits )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isOriginalAtom(mce, data));
    tl_assert(isShadowAtom(mce, vbits));
    tl_assert(sameKindedAtoms(data, vbits));
@@ -807,6 +847,7 @@ static IRAtom* mkImproveOR8 ( MCEnv* mce
 
 static IRAtom* mkImproveOR16 ( MCEnv* mce, IRAtom* data, IRAtom* vbits )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isOriginalAtom(mce, data));
    tl_assert(isShadowAtom(mce, vbits));
    tl_assert(sameKindedAtoms(data, vbits));
@@ -819,6 +860,7 @@ static IRAtom* mkImproveOR16 ( MCEnv* mc
 
 static IRAtom* mkImproveOR32 ( MCEnv* mce, IRAtom* data, IRAtom* vbits )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isOriginalAtom(mce, data));
    tl_assert(isShadowAtom(mce, vbits));
    tl_assert(sameKindedAtoms(data, vbits));
@@ -831,6 +873,7 @@ static IRAtom* mkImproveOR32 ( MCEnv* mc
 
 static IRAtom* mkImproveOR64 ( MCEnv* mce, IRAtom* data, IRAtom* vbits )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isOriginalAtom(mce, data));
    tl_assert(isShadowAtom(mce, vbits));
    tl_assert(sameKindedAtoms(data, vbits));
@@ -843,6 +886,7 @@ static IRAtom* mkImproveOR64 ( MCEnv* mc
 
 static IRAtom* mkImproveORV128 ( MCEnv* mce, IRAtom* data, IRAtom* vbits )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isOriginalAtom(mce, data));
    tl_assert(isShadowAtom(mce, vbits));
    tl_assert(sameKindedAtoms(data, vbits));
@@ -855,6 +899,7 @@ static IRAtom* mkImproveORV128 ( MCEnv* 
 
 static IRAtom* mkImproveORV256 ( MCEnv* mce, IRAtom* data, IRAtom* vbits )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isOriginalAtom(mce, data));
    tl_assert(isShadowAtom(mce, vbits));
    tl_assert(sameKindedAtoms(data, vbits));
@@ -873,6 +918,7 @@ static IRAtom* mkImproveORV256 ( MCEnv* 
 
 static IRAtom* mkPCastTo( MCEnv* mce, IRType dst_ty, IRAtom* vbits ) 
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRType  src_ty;
    IRAtom* tmp1;
 
@@ -1024,6 +1070,7 @@ static IRAtom* mkPCastTo( MCEnv* mce, IR
    the entire argument down to a single bit. */
 static IRAtom* mkPCastXXtoXXlsb ( MCEnv* mce, IRAtom* varg, IRType ty )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (ty == Ity_V128) {
       /* --- Case for V128 --- */
       IRAtom* varg128 = varg;
@@ -1065,6 +1112,7 @@ static IRAtom* mkPCastXXtoXXlsb ( MCEnv*
 */
 static IRAtom* mkOCastAt( MCEnv* mce, IRType ty, IRAtom* vbits )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IROp opSUB, opSHR, opSAR;
    UInt sh;
 
@@ -1163,6 +1211,7 @@ static IRAtom* expensiveCmpEQorNE ( MCEn
                                     IRAtom* vxx, IRAtom* vyy, 
                                     IRAtom* xx,  IRAtom* yy )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom *naive, *vec, *improved, *final_cast;
    IROp   opDIFD, opUIFU, opOR, opXOR, opNOT;
 
@@ -1261,6 +1310,7 @@ static IRAtom* expensiveCmpEQorNE ( MCEn
 */
 static Bool isZeroU32 ( IRAtom* e )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return
       toBool( e->tag == Iex_Const
               && e->Iex.Const.con->tag == Ico_U32
@@ -1269,6 +1319,7 @@ static Bool isZeroU32 ( IRAtom* e )
 
 static Bool isZeroU64 ( IRAtom* e )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return
       toBool( e->tag == Iex_Const
               && e->Iex.Const.con->tag == Ico_U64
@@ -1280,6 +1331,7 @@ static IRAtom* doCmpORD ( MCEnv*  mce,
                           IRAtom* xxhash, IRAtom* yyhash, 
                           IRAtom* xx,     IRAtom* yy )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Bool   m64    = cmp_op == Iop_CmpORD64S || cmp_op == Iop_CmpORD64U;
    Bool   syned  = cmp_op == Iop_CmpORD64S || cmp_op == Iop_CmpORD32S;
    IROp   opOR   = m64 ? Iop_Or64  : Iop_Or32;
@@ -1360,6 +1412,7 @@ static IRAtom* schemeE ( MCEnv* mce, IRE
    call. */
 
 static void setHelperAnns ( MCEnv* mce, IRDirty* di ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    di->nFxState = 2;
    di->fxState[0].fx        = Ifx_Read;
    di->fxState[0].offset    = mce->layout->offset_SP;
@@ -1395,6 +1448,7 @@ static void setHelperAnns ( MCEnv* mce, 
 */
 static void complainIfUndefined ( MCEnv* mce, IRAtom* atom, IRExpr *guard )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom*  vatom;
    IRType   ty;
    Int      sz;
@@ -1582,6 +1636,7 @@ static void complainIfUndefined ( MCEnv*
 */
 static Bool isAlwaysDefd ( MCEnv* mce, Int offset, Int size )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int minoffD, maxoffD, i;
    Int minoff = offset;
    Int maxoff = minoff + size - 1;
@@ -1616,6 +1671,7 @@ static
 void do_shadow_PUT ( MCEnv* mce,  Int offset, 
                      IRAtom* atom, IRAtom* vatom, IRExpr *guard )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRType ty;
 
    // Don't do shadow PUTs if we're not doing undefined value checking.
@@ -1662,6 +1718,7 @@ void do_shadow_PUT ( MCEnv* mce,  Int of
 static
 void do_shadow_PUTI ( MCEnv* mce, IRPutI *puti)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* vatom;
    IRType  ty, tyS;
    Int     arrSize;;
@@ -1706,6 +1763,7 @@ void do_shadow_PUTI ( MCEnv* mce, IRPutI
 static 
 IRExpr* shadow_GET ( MCEnv* mce, Int offset, IRType ty )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRType tyS = shadowTypeV(ty);
    tl_assert(ty != Ity_I1);
    tl_assert(ty != Ity_I128);
@@ -1728,6 +1786,7 @@ static
 IRExpr* shadow_GETI ( MCEnv* mce, 
                       IRRegArray* descr, IRAtom* ix, Int bias )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRType ty   = descr->elemTy;
    IRType tyS  = shadowTypeV(ty);
    Int arrSize = descr->nElems * sizeofIRType(ty);
@@ -1759,6 +1818,7 @@ IRExpr* shadow_GETI ( MCEnv* mce, 
 static
 IRAtom* mkLazy2 ( MCEnv* mce, IRType finalVty, IRAtom* va1, IRAtom* va2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    IRType t1 = typeOfIRExpr(mce->sb->tyenv, va1);
    IRType t2 = typeOfIRExpr(mce->sb->tyenv, va2);
@@ -1816,6 +1876,7 @@ static
 IRAtom* mkLazy3 ( MCEnv* mce, IRType finalVty, 
                   IRAtom* va1, IRAtom* va2, IRAtom* va3 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    IRType t1 = typeOfIRExpr(mce->sb->tyenv, va1);
    IRType t2 = typeOfIRExpr(mce->sb->tyenv, va2);
@@ -1950,6 +2011,7 @@ static
 IRAtom* mkLazy4 ( MCEnv* mce, IRType finalVty, 
                   IRAtom* va1, IRAtom* va2, IRAtom* va3, IRAtom* va4 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    IRType t1 = typeOfIRExpr(mce->sb->tyenv, va1);
    IRType t2 = typeOfIRExpr(mce->sb->tyenv, va2);
@@ -2063,6 +2125,7 @@ static
 IRAtom* mkLazyN ( MCEnv* mce, 
                   IRAtom** exprvec, IRType finalVtype, IRCallee* cee )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int     i;
    IRAtom* here;
    IRAtom* curr;
@@ -2118,6 +2181,7 @@ IRAtom* expensiveAddSub ( MCEnv*  mce,
                           IRAtom* qaa, IRAtom* qbb, 
                           IRAtom* aa,  IRAtom* bb )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom *a_min, *b_min, *a_max, *b_max;
    IROp   opAND, opOR, opXOR, opNOT, opADD, opSUB;
 
@@ -2202,6 +2266,7 @@ static
 IRAtom* expensiveCountTrailingZeroes ( MCEnv* mce, IROp czop,
                                        IRAtom* atom, IRAtom* vatom )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRType ty;
    IROp xorOp, subOp, andOp;
    IRExpr *one;
@@ -2281,6 +2346,7 @@ static IRAtom* scalarShift ( MCEnv*  mce
                              IRAtom* qaa, IRAtom* qbb, 
                              IRAtom* aa,  IRAtom* bb )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isShadowAtom(mce,qaa));
    tl_assert(isShadowAtom(mce,qbb));
    tl_assert(isOriginalAtom(mce,aa));
@@ -2306,71 +2372,85 @@ static IRAtom* scalarShift ( MCEnv*  mce
 
 static IRAtom* mkPCast8x16 ( MCEnv* mce, IRAtom* at )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return assignNew('V', mce, Ity_V128, unop(Iop_CmpNEZ8x16, at));
 }
 
 static IRAtom* mkPCast16x8 ( MCEnv* mce, IRAtom* at )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return assignNew('V', mce, Ity_V128, unop(Iop_CmpNEZ16x8, at));
 }
 
 static IRAtom* mkPCast32x4 ( MCEnv* mce, IRAtom* at )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return assignNew('V', mce, Ity_V128, unop(Iop_CmpNEZ32x4, at));
 }
 
 static IRAtom* mkPCast64x2 ( MCEnv* mce, IRAtom* at )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return assignNew('V', mce, Ity_V128, unop(Iop_CmpNEZ64x2, at));
 }
 
 static IRAtom* mkPCast128x1 ( MCEnv* mce, IRAtom* at )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return assignNew('V', mce, Ity_V128, unop(Iop_CmpNEZ128x1, at));
 }
 
 static IRAtom* mkPCast64x4 ( MCEnv* mce, IRAtom* at )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return assignNew('V', mce, Ity_V256, unop(Iop_CmpNEZ64x4, at));
 }
 
 static IRAtom* mkPCast32x8 ( MCEnv* mce, IRAtom* at )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return assignNew('V', mce, Ity_V256, unop(Iop_CmpNEZ32x8, at));
 }
 
 static IRAtom* mkPCast32x2 ( MCEnv* mce, IRAtom* at )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return assignNew('V', mce, Ity_I64, unop(Iop_CmpNEZ32x2, at));
 }
 
 static IRAtom* mkPCast16x16 ( MCEnv* mce, IRAtom* at )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return assignNew('V', mce, Ity_V256, unop(Iop_CmpNEZ16x16, at));
 }
 
 static IRAtom* mkPCast16x4 ( MCEnv* mce, IRAtom* at )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return assignNew('V', mce, Ity_I64, unop(Iop_CmpNEZ16x4, at));
 }
 
 static IRAtom* mkPCast8x32 ( MCEnv* mce, IRAtom* at )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return assignNew('V', mce, Ity_V256, unop(Iop_CmpNEZ8x32, at));
 }
 
 static IRAtom* mkPCast8x8 ( MCEnv* mce, IRAtom* at )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return assignNew('V', mce, Ity_I64, unop(Iop_CmpNEZ8x8, at));
 }
 
 static IRAtom* mkPCast16x2 ( MCEnv* mce, IRAtom* at )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return assignNew('V', mce, Ity_I32, unop(Iop_CmpNEZ16x2, at));
 }
 
 static IRAtom* mkPCast8x4 ( MCEnv* mce, IRAtom* at )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return assignNew('V', mce, Ity_I32, unop(Iop_CmpNEZ8x4, at));
 }
 
@@ -2414,6 +2494,7 @@ static IRAtom* mkPCast8x4 ( MCEnv* mce, 
 static
 IRAtom* binary32Fx4 ( MCEnv* mce, IRAtom* vatomX, IRAtom* vatomY )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    tl_assert(isShadowAtom(mce, vatomX));
    tl_assert(isShadowAtom(mce, vatomY));
@@ -2425,6 +2506,7 @@ IRAtom* binary32Fx4 ( MCEnv* mce, IRAtom
 static
 IRAtom* unary32Fx4 ( MCEnv* mce, IRAtom* vatomX )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    tl_assert(isShadowAtom(mce, vatomX));
    at = assignNew('V', mce, Ity_V128, mkPCast32x4(mce, vatomX));
@@ -2434,6 +2516,7 @@ IRAtom* unary32Fx4 ( MCEnv* mce, IRAtom*
 static
 IRAtom* binary32F0x4 ( MCEnv* mce, IRAtom* vatomX, IRAtom* vatomY )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    tl_assert(isShadowAtom(mce, vatomX));
    tl_assert(isShadowAtom(mce, vatomY));
@@ -2447,6 +2530,7 @@ IRAtom* binary32F0x4 ( MCEnv* mce, IRAto
 static
 IRAtom* unary32F0x4 ( MCEnv* mce, IRAtom* vatomX )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    tl_assert(isShadowAtom(mce, vatomX));
    at = assignNew('V', mce, Ity_I32, unop(Iop_V128to32, vatomX));
@@ -2460,6 +2544,7 @@ IRAtom* unary32F0x4 ( MCEnv* mce, IRAtom
 static
 IRAtom* binary64Fx2 ( MCEnv* mce, IRAtom* vatomX, IRAtom* vatomY )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    tl_assert(isShadowAtom(mce, vatomX));
    tl_assert(isShadowAtom(mce, vatomY));
@@ -2471,6 +2556,7 @@ IRAtom* binary64Fx2 ( MCEnv* mce, IRAtom
 static
 IRAtom* unary64Fx2 ( MCEnv* mce, IRAtom* vatomX )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    tl_assert(isShadowAtom(mce, vatomX));
    at = assignNew('V', mce, Ity_V128, mkPCast64x2(mce, vatomX));
@@ -2480,6 +2566,7 @@ IRAtom* unary64Fx2 ( MCEnv* mce, IRAtom*
 static
 IRAtom* binary64F0x2 ( MCEnv* mce, IRAtom* vatomX, IRAtom* vatomY )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    tl_assert(isShadowAtom(mce, vatomX));
    tl_assert(isShadowAtom(mce, vatomY));
@@ -2493,6 +2580,7 @@ IRAtom* binary64F0x2 ( MCEnv* mce, IRAto
 static
 IRAtom* unary64F0x2 ( MCEnv* mce, IRAtom* vatomX )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    tl_assert(isShadowAtom(mce, vatomX));
    at = assignNew('V', mce, Ity_I64, unop(Iop_V128to64, vatomX));
@@ -2506,6 +2594,7 @@ IRAtom* unary64F0x2 ( MCEnv* mce, IRAtom
 static
 IRAtom* binary32Fx2 ( MCEnv* mce, IRAtom* vatomX, IRAtom* vatomY )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    tl_assert(isShadowAtom(mce, vatomX));
    tl_assert(isShadowAtom(mce, vatomY));
@@ -2517,6 +2606,7 @@ IRAtom* binary32Fx2 ( MCEnv* mce, IRAtom
 static
 IRAtom* unary32Fx2 ( MCEnv* mce, IRAtom* vatomX )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    tl_assert(isShadowAtom(mce, vatomX));
    at = assignNew('V', mce, Ity_I64, mkPCast32x2(mce, vatomX));
@@ -2528,6 +2618,7 @@ IRAtom* unary32Fx2 ( MCEnv* mce, IRAtom*
 static
 IRAtom* binary64Fx4 ( MCEnv* mce, IRAtom* vatomX, IRAtom* vatomY )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    tl_assert(isShadowAtom(mce, vatomX));
    tl_assert(isShadowAtom(mce, vatomY));
@@ -2539,6 +2630,7 @@ IRAtom* binary64Fx4 ( MCEnv* mce, IRAtom
 static
 IRAtom* unary64Fx4 ( MCEnv* mce, IRAtom* vatomX )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    tl_assert(isShadowAtom(mce, vatomX));
    at = assignNew('V', mce, Ity_V256, mkPCast64x4(mce, vatomX));
@@ -2550,6 +2642,7 @@ IRAtom* unary64Fx4 ( MCEnv* mce, IRAtom*
 static
 IRAtom* binary32Fx8 ( MCEnv* mce, IRAtom* vatomX, IRAtom* vatomY )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    tl_assert(isShadowAtom(mce, vatomX));
    tl_assert(isShadowAtom(mce, vatomY));
@@ -2561,6 +2654,7 @@ IRAtom* binary32Fx8 ( MCEnv* mce, IRAtom
 static
 IRAtom* unary32Fx8 ( MCEnv* mce, IRAtom* vatomX )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    tl_assert(isShadowAtom(mce, vatomX));
    at = assignNew('V', mce, Ity_V256, mkPCast32x8(mce, vatomX));
@@ -2573,6 +2667,7 @@ static
 IRAtom* binary64Fx2_w_rm ( MCEnv* mce, IRAtom* vRM,
                                        IRAtom* vatomX, IRAtom* vatomY )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    /* This is the same as binary64Fx2, except that we subsequently
       pessimise vRM (definedness of the rounding mode), widen to 128
       bits and UifU it into the result.  As with the scalar cases, if
@@ -2593,6 +2688,7 @@ static
 IRAtom* binary32Fx4_w_rm ( MCEnv* mce, IRAtom* vRM,
                                        IRAtom* vatomX, IRAtom* vatomY )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* t1 = binary32Fx4(mce, vatomX, vatomY);
    // PCast the RM, and widen it to 128 bits
    IRAtom* t2 = mkPCastTo(mce, Ity_V128, vRM);
@@ -2607,6 +2703,7 @@ static
 IRAtom* binary64Fx4_w_rm ( MCEnv* mce, IRAtom* vRM,
                                        IRAtom* vatomX, IRAtom* vatomY )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* t1 = binary64Fx4(mce, vatomX, vatomY);
    // PCast the RM, and widen it to 256 bits
    IRAtom* t2 = mkPCastTo(mce, Ity_V256, vRM);
@@ -2621,6 +2718,7 @@ static
 IRAtom* binary32Fx8_w_rm ( MCEnv* mce, IRAtom* vRM,
                                        IRAtom* vatomX, IRAtom* vatomY )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* t1 = binary32Fx8(mce, vatomX, vatomY);
    // PCast the RM, and widen it to 256 bits
    IRAtom* t2 = mkPCastTo(mce, Ity_V256, vRM);
@@ -2634,6 +2732,7 @@ IRAtom* binary32Fx8_w_rm ( MCEnv* mce, I
 static
 IRAtom* unary64Fx2_w_rm ( MCEnv* mce, IRAtom* vRM, IRAtom* vatomX )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    /* Same scheme as binary64Fx2_w_rm. */
    // "do" the vector arg
    IRAtom* t1 = unary64Fx2(mce, vatomX);
@@ -2649,6 +2748,7 @@ IRAtom* unary64Fx2_w_rm ( MCEnv* mce, IR
 static
 IRAtom* unary32Fx4_w_rm ( MCEnv* mce, IRAtom* vRM, IRAtom* vatomX )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    /* Same scheme as unary32Fx4_w_rm. */
    IRAtom* t1 = unary32Fx4(mce, vatomX);
    // PCast the RM, and widen it to 128 bits
@@ -2711,6 +2811,7 @@ IRAtom* unary32Fx4_w_rm ( MCEnv* mce, IR
 static
 IROp vanillaNarrowingOpOfShape ( IROp qnarrowOp )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    switch (qnarrowOp) {
       /* Binary: (128, 128) -> 128 */
       case Iop_QNarrowBin16Sto8Ux16:
@@ -2753,6 +2854,7 @@ static
 IRAtom* vectorNarrowBinV128 ( MCEnv* mce, IROp narrow_op, 
                               IRAtom* vatom1, IRAtom* vatom2)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom *at1, *at2, *at3;
    IRAtom* (*pcast)( MCEnv*, IRAtom* );
    switch (narrow_op) {
@@ -2779,6 +2881,7 @@ static
 IRAtom* vectorNarrowBin64 ( MCEnv* mce, IROp narrow_op, 
                             IRAtom* vatom1, IRAtom* vatom2)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom *at1, *at2, *at3;
    IRAtom* (*pcast)( MCEnv*, IRAtom* );
    switch (narrow_op) {
@@ -2800,6 +2903,7 @@ static
 IRAtom* vectorNarrowUnV128 ( MCEnv* mce, IROp narrow_op,
                              IRAtom* vatom1)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom *at1, *at2;
    IRAtom* (*pcast)( MCEnv*, IRAtom* );
    tl_assert(isShadowAtom(mce,vatom1));
@@ -2839,6 +2943,7 @@ static
 IRAtom* vectorWidenI64 ( MCEnv* mce, IROp longen_op,
                          IRAtom* vatom1)
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom *at1, *at2;
    IRAtom* (*pcast)( MCEnv*, IRAtom* );
    switch (longen_op) {
@@ -2867,6 +2972,7 @@ IRAtom* vectorWidenI64 ( MCEnv* mce, IRO
 static
 IRAtom* binary8Ix32 ( MCEnv* mce, IRAtom* vatom1, IRAtom* vatom2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    at = mkUifUV256(mce, vatom1, vatom2);
    at = mkPCast8x32(mce, at);
@@ -2876,6 +2982,7 @@ IRAtom* binary8Ix32 ( MCEnv* mce, IRAtom
 static
 IRAtom* binary16Ix16 ( MCEnv* mce, IRAtom* vatom1, IRAtom* vatom2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    at = mkUifUV256(mce, vatom1, vatom2);
    at = mkPCast16x16(mce, at);
@@ -2885,6 +2992,7 @@ IRAtom* binary16Ix16 ( MCEnv* mce, IRAto
 static
 IRAtom* binary32Ix8 ( MCEnv* mce, IRAtom* vatom1, IRAtom* vatom2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    at = mkUifUV256(mce, vatom1, vatom2);
    at = mkPCast32x8(mce, at);
@@ -2894,6 +3002,7 @@ IRAtom* binary32Ix8 ( MCEnv* mce, IRAtom
 static
 IRAtom* binary64Ix4 ( MCEnv* mce, IRAtom* vatom1, IRAtom* vatom2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    at = mkUifUV256(mce, vatom1, vatom2);
    at = mkPCast64x4(mce, at);
@@ -2905,6 +3014,7 @@ IRAtom* binary64Ix4 ( MCEnv* mce, IRAtom
 static
 IRAtom* binary8Ix16 ( MCEnv* mce, IRAtom* vatom1, IRAtom* vatom2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    at = mkUifUV128(mce, vatom1, vatom2);
    at = mkPCast8x16(mce, at);
@@ -2914,6 +3024,7 @@ IRAtom* binary8Ix16 ( MCEnv* mce, IRAtom
 static
 IRAtom* binary16Ix8 ( MCEnv* mce, IRAtom* vatom1, IRAtom* vatom2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    at = mkUifUV128(mce, vatom1, vatom2);
    at = mkPCast16x8(mce, at);
@@ -2923,6 +3034,7 @@ IRAtom* binary16Ix8 ( MCEnv* mce, IRAtom
 static
 IRAtom* binary32Ix4 ( MCEnv* mce, IRAtom* vatom1, IRAtom* vatom2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    at = mkUifUV128(mce, vatom1, vatom2);
    at = mkPCast32x4(mce, at);
@@ -2932,6 +3044,7 @@ IRAtom* binary32Ix4 ( MCEnv* mce, IRAtom
 static
 IRAtom* binary64Ix2 ( MCEnv* mce, IRAtom* vatom1, IRAtom* vatom2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    at = mkUifUV128(mce, vatom1, vatom2);
    at = mkPCast64x2(mce, at);
@@ -2941,6 +3054,7 @@ IRAtom* binary64Ix2 ( MCEnv* mce, IRAtom
 static
 IRAtom* binary128Ix1 ( MCEnv* mce, IRAtom* vatom1, IRAtom* vatom2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    at = mkUifUV128(mce, vatom1, vatom2);
    at = mkPCast128x1(mce, at);
@@ -2952,6 +3066,7 @@ IRAtom* binary128Ix1 ( MCEnv* mce, IRAto
 static
 IRAtom* binary8Ix8 ( MCEnv* mce, IRAtom* vatom1, IRAtom* vatom2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    at = mkUifU64(mce, vatom1, vatom2);
    at = mkPCast8x8(mce, at);
@@ -2961,6 +3076,7 @@ IRAtom* binary8Ix8 ( MCEnv* mce, IRAtom*
 static
 IRAtom* binary16Ix4 ( MCEnv* mce, IRAtom* vatom1, IRAtom* vatom2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    at = mkUifU64(mce, vatom1, vatom2);
    at = mkPCast16x4(mce, at);
@@ -2970,6 +3086,7 @@ IRAtom* binary16Ix4 ( MCEnv* mce, IRAtom
 static
 IRAtom* binary32Ix2 ( MCEnv* mce, IRAtom* vatom1, IRAtom* vatom2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    at = mkUifU64(mce, vatom1, vatom2);
    at = mkPCast32x2(mce, at);
@@ -2979,6 +3096,7 @@ IRAtom* binary32Ix2 ( MCEnv* mce, IRAtom
 static
 IRAtom* binary64Ix1 ( MCEnv* mce, IRAtom* vatom1, IRAtom* vatom2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    at = mkUifU64(mce, vatom1, vatom2);
    at = mkPCastTo(mce, Ity_I64, at);
@@ -2990,6 +3108,7 @@ IRAtom* binary64Ix1 ( MCEnv* mce, IRAtom
 static
 IRAtom* binary8Ix4 ( MCEnv* mce, IRAtom* vatom1, IRAtom* vatom2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    at = mkUifU32(mce, vatom1, vatom2);
    at = mkPCast8x4(mce, at);
@@ -2999,6 +3118,7 @@ IRAtom* binary8Ix4 ( MCEnv* mce, IRAtom*
 static
 IRAtom* binary16Ix2 ( MCEnv* mce, IRAtom* vatom1, IRAtom* vatom2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* at;
    at = mkUifU32(mce, vatom1, vatom2);
    at = mkPCast16x2(mce, at);
@@ -3016,6 +3136,7 @@ IRAtom* expr2vbits_Qop ( MCEnv* mce,
                          IRAtom* atom1, IRAtom* atom2, 
                          IRAtom* atom3, IRAtom* atom4 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* vatom1 = expr2vbits( mce, atom1, HuOth );
    IRAtom* vatom2 = expr2vbits( mce, atom2, HuOth );
    IRAtom* vatom3 = expr2vbits( mce, atom3, HuOth );
@@ -3075,6 +3196,7 @@ IRAtom* expr2vbits_Triop ( MCEnv* mce,
                            IROp op,
                            IRAtom* atom1, IRAtom* atom2, IRAtom* atom3 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom* vatom1 = expr2vbits( mce, atom1, HuOth );
    IRAtom* vatom2 = expr2vbits( mce, atom2, HuOth );
    IRAtom* vatom3 = expr2vbits( mce, atom3, HuOth );
@@ -3219,6 +3341,7 @@ IRAtom* expr2vbits_Binop ( MCEnv* mce,
                            IRAtom* atom1, IRAtom* atom2,
                            HowUsed hu/*use HuOth if unknown*/ )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRType  and_or_ty;
    IRAtom* (*uifu)    (MCEnv*, IRAtom*, IRAtom*);
    IRAtom* (*difd)    (MCEnv*, IRAtom*, IRAtom*);
@@ -4648,6 +4771,7 @@ IRAtom* expr2vbits_Binop ( MCEnv* mce,
 static 
 IRExpr* expr2vbits_Unop ( MCEnv* mce, IROp op, IRAtom* atom )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    /* For the widening operations {8,16,32}{U,S}to{16,32,64}, the
       selection of shadow operation implicitly duplicates the logic in
       do_shadow_LoadG and should be kept in sync (in the very unlikely
@@ -5017,6 +5141,7 @@ IRAtom* expr2vbits_Load_WRK ( MCEnv* mce
                               IREndness end, IRType ty,
                               IRAtom* addr, UInt bias, IRAtom* guard )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isOriginalAtom(mce,addr));
    tl_assert(end == Iend_LE || end == Iend_BE);
 
@@ -5152,6 +5277,7 @@ IRAtom* expr2vbits_Load ( MCEnv* mce,
                           IRAtom* addr, UInt bias,
                           IRAtom* guard )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(end == Iend_LE || end == Iend_BE);
    switch (shadowTypeV(ty)) {
       case Ity_I8:
@@ -5186,6 +5312,7 @@ IRAtom* expr2vbits_Load_guarded_General 
                                           IRAtom* guard,
                                           IROp vwiden, IRAtom* valt )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    /* Sanity check the conversion operation, and also set TYWIDE. */
    IRType tyWide = Ity_INVALID;
    switch (vwiden) {
@@ -5243,6 +5370,7 @@ IRAtom* expr2vbits_Load_guarded_Simple (
                                          IRAtom* addr, UInt bias,
                                          IRAtom *guard )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return expr2vbits_Load_guarded_General(
              mce, end, ty, addr, bias, guard, Iop_INVALID, definedOfType(ty)
           );
@@ -5253,6 +5381,7 @@ static
 IRAtom* expr2vbits_ITE ( MCEnv* mce, 
                          IRAtom* cond, IRAtom* iftrue, IRAtom* iffalse )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom *vbitsC, *vbits0, *vbits1;
    IRType ty;
    /* Given ITE(cond, iftrue,  iffalse),  generate
@@ -5281,6 +5410,7 @@ static
 IRExpr* expr2vbits ( MCEnv* mce, IRExpr* e,
                      HowUsed hu/*use HuOth if unknown*/ )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    switch (e->tag) {
 
       case Iex_Get:
@@ -5356,6 +5486,7 @@ IRExpr* expr2vbits ( MCEnv* mce, IRExpr*
 static
 IRExpr* zwidenToHostWord ( MCEnv* mce, IRAtom* vatom )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRType ty, tyH;
 
    /* vatom is vbits-value and as such can only have a shadow type. */
@@ -5416,6 +5547,7 @@ void do_shadow_Store ( MCEnv* mce, 
                        IRAtom* data, IRAtom* vdata,
                        IRAtom* guard )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IROp     mkAdd;
    IRType   ty, tyAddr;
    void*    helper = NULL;
@@ -5666,6 +5798,7 @@ void do_shadow_Store ( MCEnv* mce, 
 
 static IRType szToITy ( Int n )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    switch (n) {
       case 1: return Ity_I8;
       case 2: return Ity_I16;
@@ -5678,6 +5811,7 @@ static IRType szToITy ( Int n )
 static
 void do_shadow_Dirty ( MCEnv* mce, IRDirty* d )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int       i, k, n, toDo, gSz, gOff;
    IRAtom    *src, *here, *curr;
    IRType    tySrc, tyDst;
@@ -5906,6 +6040,7 @@ void do_shadow_Dirty ( MCEnv* mce, IRDir
 static
 void do_AbiHint ( MCEnv* mce, IRExpr* base, Int len, IRExpr* nia )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRDirty* di;
 
    if (MC_(clo_mc_level) == 3) {
@@ -5982,6 +6117,7 @@ static void bind_shadow_tmp_to_orig ( UC
                                       MCEnv* mce,
                                       IRAtom* orig, IRAtom* shadow )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(isOriginalAtom(mce, orig));
    tl_assert(isShadowAtom(mce, shadow));
    switch (orig->tag) {
@@ -6008,6 +6144,7 @@ static void bind_shadow_tmp_to_orig ( UC
 static
 void do_shadow_CAS ( MCEnv* mce, IRCAS* cas )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    /* Scheme is (both single- and double- cases):
 
       1. fetch data#,dataB (the proposed new value)
@@ -6141,6 +6278,7 @@ void do_shadow_CAS ( MCEnv* mce, IRCAS* 
 
 static void do_shadow_CAS_single ( MCEnv* mce, IRCAS* cas )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom *vdataLo = NULL, *bdataLo = NULL;
    IRAtom *vexpdLo = NULL, *bexpdLo = NULL;
    IRAtom *voldLo  = NULL, *boldLo  = NULL;
@@ -6231,6 +6369,7 @@ static void do_shadow_CAS_single ( MCEnv
 
 static void do_shadow_CAS_double ( MCEnv* mce, IRCAS* cas )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRAtom *vdataHi = NULL, *bdataHi = NULL;
    IRAtom *vdataLo = NULL, *bdataLo = NULL;
    IRAtom *vexpdHi = NULL, *bexpdHi = NULL;
@@ -6399,6 +6538,7 @@ static void do_shadow_LLSC ( MCEnv*    m
                              IRExpr*   stAddr,
                              IRExpr*   stStoredata )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    /* In short: treat a load-linked like a normal load followed by an
       assignment of the loaded (shadow) data to the result temporary.
       Treat a store-conditional like a normal store, and mark the
@@ -6458,6 +6598,7 @@ static void do_shadow_LLSC ( MCEnv*    m
 
 static void do_shadow_StoreG ( MCEnv* mce, IRStoreG* sg )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    complainIfUndefined(mce, sg->guard, NULL);
    /* do_shadow_Store will generate code to check the definedness and
       validity of sg->addr, in the case where sg->guard evaluates to
@@ -6471,6 +6612,7 @@ static void do_shadow_StoreG ( MCEnv* mc
 
 static void do_shadow_LoadG ( MCEnv* mce, IRLoadG* lg )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    complainIfUndefined(mce, lg->guard, NULL);
    /* expr2vbits_Load_guarded_General will generate code to check the
       definedness and validity of lg->addr, in the case where
@@ -6516,6 +6658,7 @@ static void do_shadow_LoadG ( MCEnv* mce
 /* Almost identical to findShadowTmpV. */
 static IRTemp findShadowTmpB ( MCEnv* mce, IRTemp orig )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    TempMapEnt* ent;
    /* VG_(indexXA) range-checks 'orig', hence no need to check
       here. */
@@ -6536,6 +6679,7 @@ static IRTemp findShadowTmpB ( MCEnv* mc
 
 static IRAtom* gen_maxU32 ( MCEnv* mce, IRAtom* b1, IRAtom* b2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return assignNew( 'B', mce, Ity_I32, binop(Iop_Max32U, b1, b2) );
 }
 
@@ -6552,6 +6696,7 @@ static IRAtom* gen_guarded_load_b ( MCEn
                                     IRAtom* baseaddr, 
                                     Int offset, IRExpr* guard )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    void*    hFun;
    const HChar* hName;
    IRTemp   bTmp;
@@ -6624,6 +6769,7 @@ static IRAtom* gen_guarded_load_b ( MCEn
 static IRAtom* gen_load_b ( MCEnv* mce, Int szB, IRAtom* baseaddr,
                             Int offset )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    return gen_guarded_load_b(mce, szB, baseaddr, offset, NULL/*guard*/);
 }
 
@@ -6641,6 +6787,7 @@ IRAtom* expr2ori_Load_guarded_General ( 
                                         IRAtom* addr, UInt bias,
                                         IRAtom* guard, IRAtom* balt )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    /* If the guard evaluates to True, this will hold the loaded
       origin.  If the guard evaluates to False, this will be zero,
       meaning "unknown origin", in which case we will have to replace
@@ -6668,6 +6815,7 @@ static void gen_store_b ( MCEnv* mce, In
                           IRAtom* baseaddr, Int offset, IRAtom* dataB,
                           IRAtom* guard )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    void*    hFun;
    const HChar* hName;
    IRDirty* di;
@@ -6719,6 +6867,7 @@ static void gen_store_b ( MCEnv* mce, In
 }
 
 static IRAtom* narrowTo32 ( MCEnv* mce, IRAtom* e ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRType eTy = typeOfIRExpr(mce->sb->tyenv, e);
    if (eTy == Ity_I64)
       return assignNew( 'B', mce, Ity_I32, unop(Iop_64to32, e) );
@@ -6728,6 +6877,7 @@ static IRAtom* narrowTo32 ( MCEnv* mce, 
 }
 
 static IRAtom* zWidenFrom32 ( MCEnv* mce, IRType dstTy, IRAtom* e ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRType eTy = typeOfIRExpr(mce->sb->tyenv, e);
    tl_assert(eTy == Ity_I32);
    if (dstTy == Ity_I64)
@@ -6738,6 +6888,7 @@ static IRAtom* zWidenFrom32 ( MCEnv* mce
 
 static IRAtom* schemeE ( MCEnv* mce, IRExpr* e )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(MC_(clo_mc_level) == 3);
 
    switch (e->tag) {
@@ -6874,6 +7025,7 @@ static IRAtom* schemeE ( MCEnv* mce, IRE
 
 static void do_origins_Dirty ( MCEnv* mce, IRDirty* d )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    // This is a hacked version of do_shadow_Dirty
    Int       i, k, n, toDo, gSz, gOff;
    IRAtom    *here, *curr;
@@ -7084,6 +7236,7 @@ static void do_origins_Store_guarded ( M
                                        IRExpr* stData,
                                        IRExpr* guard )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int     dszB;
    IRAtom* dataB;
    /* assert that the B value for the address is already available
@@ -7103,6 +7256,7 @@ static void do_origins_Store_plain ( MCE
                                      IRExpr* stAddr,
                                      IRExpr* stData )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    do_origins_Store_guarded ( mce, stEnd, stAddr, stData,
                               NULL/*guard*/ );
 }
@@ -7112,12 +7266,14 @@ static void do_origins_Store_plain ( MCE
 
 static void do_origins_StoreG ( MCEnv* mce, IRStoreG* sg )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    do_origins_Store_guarded( mce, sg->end, sg->addr,
                              sg->data, sg->guard );
 }
 
 static void do_origins_LoadG ( MCEnv* mce, IRLoadG* lg )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    IRType loadedTy = Ity_INVALID;
    switch (lg->cvt) {
       case ILGop_IdentV128: loadedTy = Ity_V128; break;
@@ -7142,6 +7298,7 @@ static void do_origins_LoadG ( MCEnv* mc
 
 static void schemeS ( MCEnv* mce, IRStmt* st )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    tl_assert(MC_(clo_mc_level) == 3);
 
    switch (st->tag) {
@@ -7347,6 +7504,7 @@ typedef
 
 static Bool sameIRValue ( IRExpr* e1, IRExpr* e2 )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (e1->tag != e2->tag)
       return False;
    switch (e1->tag) {
@@ -7394,6 +7552,7 @@ static Bool sameIRValue ( IRExpr* e1, IR
 static 
 Bool check_or_add ( Pairs* tidyingEnv, IRExpr* guard, void* entry )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt i, n = tidyingEnv->pairsUsed;
    tl_assert(n <= N_TIDYING_PAIRS);
    for (i = 0; i < n; i++) {
@@ -7428,6 +7587,7 @@ Bool check_or_add ( Pairs* tidyingEnv, I
 
 static Bool is_helperc_value_checkN_fail ( const HChar* name )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    /* This is expensive because it happens a lot.  We are checking to
       see whether |name| is one of the following 8 strings:
 
@@ -7471,6 +7631,7 @@ static Bool is_helperc_value_checkN_fail
 
 IRSB* MC_(final_tidy) ( IRSB* sb_in )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int       i;
    IRStmt*   st;
    IRDirty*  di;
@@ -7526,6 +7687,7 @@ IRSB* MC_(final_tidy) ( IRSB* sb_in )
 
 void MC_(do_instrumentation_startup_checks)( void )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    /* Make a best-effort check to see that is_helperc_value_checkN_fail
       is working as we expect. */
 
@@ -7582,6 +7744,7 @@ void MC_(do_instrumentation_startup_chec
 
 static Bool isBogusAtom ( IRAtom* at )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    if (at->tag == Iex_RdTmp)
       return False;
    tl_assert(at->tag == Iex_Const);
@@ -7625,6 +7788,7 @@ static Bool isBogusAtom ( IRAtom* at )
    isBogusAtom()? */
 static inline Bool containsBogusLiterals ( /*FLAT*/ IRStmt* st )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int      i;
    IRExpr*  e;
    IRDirty* d;
@@ -7834,6 +7998,7 @@ static inline void noteTmpUsesIn ( /*MOD
                                    UInt tyenvUsed,
                                    HowUsed newUse, IRAtom* at )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    /* For the atom |at|, declare that for any tmp |t| in |at|, we will have
       seen a use of |newUse|.  So, merge that info into |t|'s accumulated
       use info. */
@@ -7862,6 +8027,7 @@ static void preInstrumentationAnalysis (
                                          /*OUT*/Bool* hasBogusLiteralsP,
                                          const IRSB* sb_in )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    const UInt nOrigTmps = (UInt)sb_in->tyenv->types_used;
 
    // We've seen no bogus literals so far.
@@ -8065,6 +8231,7 @@ IRSB* MC_(instrument) ( VgCallbackClosur
                         const VexArchInfo* archinfo_host,
                         IRType gWordTy, IRType hWordTy )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Bool    verboze = 0||False;
    Int     i, j, first_stmt;
    IRStmt* st;
