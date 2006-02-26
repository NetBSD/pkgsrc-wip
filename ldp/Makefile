# $NetBSD: Makefile,v 1.4 2006/02/26 18:30:14 koifren Exp $

DISTNAME=	ldp-0.0.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ldp/}

MAINTAINER=	kefren@NetBSD.ro
HOMEPAGE=	http://www.ietf.org/rfc/rfc3036.txt
COMMENT=	Label Distribution Protocol

WRKSRC=		${WRKDIR}/ldp

BUILD_TARGET=	# empty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ldp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ldp.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
