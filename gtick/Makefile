# $NetBSD: Makefile,v 1.1.1.1 2003/06/16 18:48:52 bencollver Exp $
#

DISTNAME=		gtick-0.2.0
CATEGORIES=		audio
MASTER_SITES=		http://www.antcom.de/download/gtick/

MAINTAINER=		collver1@attbi.com
HOMEPAGE=		http://www.antcom.de/gtick/
COMMENT=		GTK+ metronome

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtick ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/gtick.1x ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
