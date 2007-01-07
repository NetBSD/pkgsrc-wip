# $NetBSD: Makefile,v 1.8 2007/01/07 11:18:24 koifren Exp $

DISTNAME=	ldp-0.1.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ldp/}

MAINTAINER=	kefren@NetBSD.ro
HOMEPAGE=	http://ldp.sourceforge.net/
COMMENT=	Label Distribution Protocol Daemon

WRKSRC=		${WRKDIR}/ldp

BUILD_TARGET=	# empty

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ldpd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ldpd.8 ${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
