# $NetBSD: Makefile,v 1.4 2006/11/11 17:21:39 kh-p Exp $

DISTNAME=		sic-0.6
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
