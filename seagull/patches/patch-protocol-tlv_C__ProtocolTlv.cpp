$NetBSD: patch-protocol-tlv_C__ProtocolTlv.cpp,v 1.1 2013/09/02 19:08:25 thomasklausner Exp $

Code wants to assign T_UnsignedInteger32* to it later.

--- protocol-tlv/C_ProtocolTlv.cpp.orig	2010-10-27 12:30:16.000000000 +0000
+++ protocol-tlv/C_ProtocolTlv.cpp
@@ -6472,7 +6472,7 @@ void  C_ProtocolTlv::propagate_ctxt_loca
                                           T_pHeaderField             P_field_table,
                                           T_pProtocolCounterData     P_ctxt_table) {
   int              L_i               ;
-  unsigned long   *L_size_to_update  ;
+  T_UnsignedInteger32 *L_size_to_update  ;
   unsigned char   *L_position = NULL ;
   int              L_field_id        ;
 
