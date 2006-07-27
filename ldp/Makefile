# $NetBSD: Makefile,v 1.6 2006/07/27 08:53:49 koifren Exp $

DISTNAME=	ldp-0.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ldp/}

MAINTAINER=	kefren@NetBSD.ro
HOMEPAGE=	http://ldp.sf.net/
COMMENT=	Label Distribution Protocol Daemon

WRKSRC=		${WRKDIR}/ldp

BUILD_TARGET=	# empty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ldpd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ldpd.8 ${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
