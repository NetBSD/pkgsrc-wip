# $NetBSD: Makefile,v 1.4 2004/10/25 13:21:43 ppostma Exp $

DISTNAME=	pftop-0.4
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.eee.metu.edu.tr/~canacar/

MAINTAINER=	peter@pointless.nl
HOMEPAGE=	http://www.eee.metu.edu.tr/~canacar/pftop/
COMMENT=	Utility for real-time display of statistics for PF

USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes

MAKE_ENV+=	OSLEVEL=34
CFLAGS+=	-I${PREFIX}/include
PATCHDIR=	${.CURDIR}/patches

PF_VERSION=	3.6	# XXX FIXME

.if !empty(PF_VERSION:M3.6)
OPTIONAL_PATCHFILES+=	${PATCHDIR}/patch-optional-3.6
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pftop ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pftop.8 ${PREFIX}/man/man8

.include "../../wip/pflkm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
