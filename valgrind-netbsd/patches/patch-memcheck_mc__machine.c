$NetBSD$

--- memcheck/mc_machine.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ memcheck/mc_machine.c
@@ -49,12 +49,14 @@
 
 __attribute__((unused))
 static inline Bool host_is_big_endian ( void ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt x = 0x11223344;
    return 0x1122 == *(UShort*)(&x);
 }
 
 __attribute__((unused))
 static inline Bool host_is_little_endian ( void ) {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    UInt x = 0x11223344;
    return 0x3344 == *(UShort*)(&x);
 }
@@ -96,6 +98,7 @@ static Int get_otrack_shadow_offset_wrk 
 
 Int MC_(get_otrack_shadow_offset) ( Int offset, Int szB )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    Int cand = get_otrack_shadow_offset_wrk( offset, szB );
    if (cand == -1) 
       return cand;
@@ -107,6 +110,7 @@ Int MC_(get_otrack_shadow_offset) ( Int 
 
 static Int get_otrack_shadow_offset_wrk ( Int offset, Int szB )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    /* -------------------- ppc64 -------------------- */
 
 #  if defined(VGA_ppc64be) || defined(VGA_ppc64le)
@@ -1342,6 +1346,7 @@ static Int get_otrack_shadow_offset_wrk 
 */
 IRType MC_(get_otrack_reg_array_equiv_int_type) ( IRRegArray* arr )
 {
+VG_(debugLog)(2, "KR", "%s() %s:%d\n", __func__, __FILE__, __LINE__);
    /* -------------------- ppc64 -------------------- */
 #  if defined(VGA_ppc64be) || defined(VGA_ppc64le)
    /* The redir stack. */
