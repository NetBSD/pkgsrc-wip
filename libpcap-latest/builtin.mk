# $NetBSD: builtin.mk,v 1.1 2004/08/29 13:25:18 ppostma Exp $

.if !defined(IS_BUILTIN.libpcap)
IS_BUILTIN.libpcap=	no
.  if exists(/usr/include/pcap.h)
IS_BUILTIN.libpcap=	yes
.  endif
.endif	# IS_BUILTIN.libpcap

USE_BUILTIN.libpcap?=	${IS_BUILTIN.libpcap}
