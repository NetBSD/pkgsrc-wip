# $NetBSD: Makefile,v 1.2 2003/06/07 14:52:38 cjep Exp $
#

DISTNAME=	cdpr-1.0.8
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cdpr/}

MAINTAINER=	adam@monkeybyte.org
HOMEPAGE=	http://www.monkeymental.com/
COMMENT=	Cisco Discovery Protocol Reporter

CFLAGS= -DZAURUS -Wall -I. -I${LOCALBASE}/include
LDFLAGS= -L${LOCALBASE}/lib -ggdb -lpcap
USE_BUILDLINK2=         yes

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} cdpr.c ${LDFLAGS} -o cdpr

do-install:
	cd ${WRKSRC} && ${CP} cdpr ${LOCALBASE}/bin

.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
