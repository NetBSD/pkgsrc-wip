# $NetBSD: Makefile,v 1.1.1.1 2004/06/08 12:40:26 ppostma Exp $

DISTNAME=	pftop-0.4
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.eee.metu.edu.tr/~canacar/

MAINTAINER=	peter@pointless.nl
HOMEPAGE=	http://www.eee.metu.edu.tr/~canacar/
COMMENT=	Utility for real-time display of statistics for PF

BUILD_DEPENDS+=	pf-lkm-[0-9]*:../../wip/pflkm

NO_CONFIGURE=	yes

MAKE_ENV+=	OSLEVEL=34
CFLAGS+=	-I${PREFIX}/include

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pftop ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pftop.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
