--- programs/pluto/kernel_pfkeyv2.c
+++ programs/pluto/kernel_pfkeyv2.c
@@ -25,6 +25,7 @@
 #include "ip_encap.h"
 #include "chunk.h"
 #include "hunk.h"
+#include "ike_alg_integ.h"	/* for ike_alg_integ_none; */
 
 #include "kernel.h"
 #include "kernel_alg.h"
@@ -265,8 +266,10 @@ static struct sadb_sa *put_sadb_sa(struct outbuf *msg,
 				   const struct encrypt_desc *encrypt,
 				   const struct ipcomp_desc *ipcomp)
 {
-	unsigned aalg = (integ != NULL ? integ->integ_sadb_aalg_id :
+	unsigned aalg = (integ == &ike_alg_integ_none && encrypt_desc_is_aead(encrypt) ? SADB_AALG_NONE :
+			 integ != NULL ? integ->integ_sadb_aalg_id :
 			 0);
+
 	unsigned ealg = (encrypt != NULL ? encrypt->encrypt_sadb_ealg_id :
 			 /* XXX: NetBSD treats IPCOMP like ENCRYPT */
 			 ipcomp != NULL ? ipcomp->ipcomp_sadb_calg_id : 0);
