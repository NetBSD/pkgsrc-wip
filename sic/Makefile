# $NetBSD: Makefile,v 1.8 2012/10/07 15:14:13 asau Exp $

DISTNAME=		sic-1.0
CATEGORIES=		chat
MASTER_SITES=		http://suckless.org/download/


MAINTAINER=		smoppy@gmail.com
HOMEPAGE=		http://tools.suckless.org/sic
COMMENT=		Simple IRC client

NO_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sic ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sic.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
