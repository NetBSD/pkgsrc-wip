# $NetBSD: Makefile,v 1.2 2004/01/29 14:25:09 ora8_ Exp $

DISTNAME= 	tcpick-0.1.19
CATEGORIES=	net
MASTER_SITES=   http://switch.dl.sourceforge.net/sourceforge/tcpick/

MAINTAINER=	josediazfer@yahoo.es
HOMEPAGE=       http://tcpick.sourceforge.net	
COMMENT= 	Simple tcp sniffer with tcpdump-style rules and with captures of traffic colored

USE_BUILDLINK2= YES
GNU_CONFIGURE=  YES

CONFIGURE_ARGS+=--prefix=${LOCALBASE}

.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
