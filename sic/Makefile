# $NetBSD: Makefile,v 1.3 2006/10/26 10:53:40 kh-p Exp $

DISTNAME=		sic-0.5
CATEGORIES=		chat
MASTER_SITES=		http://suckless.org/download/


MAINTAINER=		kh.p@no-log.org
HOMEPAGE=		http://irc.suckless.org/
COMMENT=		Simple IRC client

NO_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sic ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sic.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
