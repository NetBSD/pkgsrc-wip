# $NetBSD: Makefile,v 1.1.1.1 2006/10/06 14:02:50 kh-p Exp $

DISTNAME=		sic-0.3
CATEGORIES=		chat
MASTER_SITES=		http://www.shortest.de/download/


MAINTAINER=		kh.p@no-log.org
HOMEPAGE=		http://www.shortest.de/view/simple+irc+client
COMMENT=		Simple IRC client

NO_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sic ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sic.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
