$NetBSD$

--- src/nxt_service.c.orig	2020-11-19 18:12:30.000000000 +0000
+++ src/nxt_service.c
@@ -13,17 +13,17 @@ static const nxt_service_t  nxt_services
     { "engine", "kqueue", &nxt_kqueue_engine },
 #endif
 
-#if (NXT_HAVE_EPOLL_EDGE)
+#if (NXT_HAVE_EPOLL_EDGE) && !(NXT_SOLARIS)
     { "engine", "epoll", &nxt_epoll_edge_engine },
     { "engine", "epoll_edge", &nxt_epoll_edge_engine },
     { "engine", "epoll_level", &nxt_epoll_level_engine },
 
-#elif (NXT_HAVE_EPOLL)
+#elif (NXT_HAVE_EPOLL) && !(NXT_SOLARIS)
     { "engine", "epoll", &nxt_epoll_level_engine },
     { "engine", "epoll_level", &nxt_epoll_level_engine },
 #endif
 
-#if (NXT_HAVE_EVENTPORT)
+#if (NXT_HAVE_EVENTPORT) || (NXT_SOLARIS)
     { "engine", "eventport", &nxt_eventport_engine },
 #endif
 
