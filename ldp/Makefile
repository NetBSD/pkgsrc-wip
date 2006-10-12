# $NetBSD: Makefile,v 1.7 2006/10/12 21:13:41 shattered Exp $

DISTNAME=	ldp-0.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ldp/}

MAINTAINER=	kefren@NetBSD.ro
HOMEPAGE=	http://ldp.sourceforge.net/
COMMENT=	Label Distribution Protocol Daemon

WRKSRC=		${WRKDIR}/ldp

BUILD_TARGET=	# empty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ldpd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ldpd.8 ${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
