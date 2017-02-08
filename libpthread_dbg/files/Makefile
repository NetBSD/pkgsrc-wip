#	$NetBSD: Makefile,v 1.16 2016/11/22 03:52:01 kamil Exp $
#

#.include <bsd.own.mk>

SRCS=	pthread_dbg.c 

CPPFLAGS+=	-D__LIBPTHREAD_SOURCE__

INCS=	pthread_dbg.h

MAN+=	pthread_dbg.3
MAN+=	td_open.3
MAN+=	td_map_pth2thr.3
MAN+=	td_thr_getname.3
MAN+=	td_thr_info.3
MAN+=	td_thr_iter.3

MLINKS+=	td_open.3 td_close.3

.include <bsd.lib.mk>
