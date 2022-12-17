$NetBSD$

--- src/zabbix_server/lld/lld_host.c.orig	2022-12-17 06:40:38.036946574 +0000
+++ src/zabbix_server/lld/lld_host.c
@@ -3882,7 +3882,7 @@ static int	lld_if_update_compare(const v
 	return u1->diff_num - u2->diff_num;
 }
 
-static zbx_uint64_t	popcount64(zbx_uint64_t mask)
+static zbx_uint64_t	zbx_popcount64(zbx_uint64_t mask)
 {
 	mask -= (mask >> 1) & __UINT64_C(0x5555555555555555);
 	mask = (mask & __UINT64_C(0x3333333333333333)) + (mask >> 2 & __UINT64_C(0x3333333333333333));
@@ -3985,7 +3985,7 @@ static void	lld_host_interfaces_make(zbx
 			update->ifnew = ifnew;
 			update->ifold = interfaces->values[j];
 			update->flags = lld_interface_compare(update->ifold, update->ifnew);
-			update->diff_num = popcount64(update->flags);
+			update->diff_num = zbx_popcount64(update->flags);
 
 			zbx_vector_if_update_append(&updates, update);
 		}
