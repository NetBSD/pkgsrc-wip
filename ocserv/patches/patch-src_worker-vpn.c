$NetBSD$

--- src/worker-vpn.c.orig	2016-04-25 20:55:23.000000000 +0000
+++ src/worker-vpn.c
@@ -865,6 +865,7 @@ int periodic_check(worker_st * ws, unsig
 		}
 	}
 
+#if 0
 	if (ws->conn_type != SOCK_TYPE_UNIX) {
 		sl = sizeof(max);
 		ret = getsockopt(ws->conn_fd, IPPROTO_TCP, TCP_MAXSEG, &max, &sl);
@@ -882,6 +883,7 @@ int periodic_check(worker_st * ws, unsig
 			}
 		}
 	}
+#endif
 
  cleanup:
 	ws->last_periodic_check = now;
@@ -1443,6 +1445,7 @@ static int connect_handler(worker_st * w
 		ws->vinfo.mtu = MIN(ws->vinfo.mtu, req->base_mtu);
 	}
 
+#if 0
 	if (ws->conn_type != SOCK_TYPE_UNIX) {
 		sl = sizeof(max);
 		ret = getsockopt(ws->conn_fd, IPPROTO_TCP, TCP_MAXSEG, &max, &sl);
@@ -1459,6 +1462,7 @@ static int connect_handler(worker_st * w
 			}
 		}
 	}
+#endif
 
 	ret = cstp_printf(ws, "X-CSTP-Base-MTU: %u\r\n", ws->vinfo.mtu);
 	SEND_ERR(ret);
