# $NetBSD: Makefile,v 1.9 2007/04/17 17:50:48 koifren Exp $

DISTNAME=	ldp-0.1.2
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
