# $NetBSD: Makefile,v 1.6 2007/01/07 09:16:00 rillig Exp $

DISTNAME=		sic-0.6
CATEGORIES=		chat
MASTER_SITES=		http://suckless.org/download/


MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://irc.suckless.org/
COMMENT=		Simple IRC client

NO_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sic ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sic.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
