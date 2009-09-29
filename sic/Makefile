# $NetBSD: Makefile,v 1.7 2009/09/29 00:04:10 smoppy Exp $

DISTNAME=		sic-1.0
CATEGORIES=		chat
MASTER_SITES=		http://suckless.org/download/


MAINTAINER=		smoppy@gmail.com
HOMEPAGE=		http://tools.suckless.org/sic
COMMENT=		Simple IRC client

NO_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sic ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sic.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
