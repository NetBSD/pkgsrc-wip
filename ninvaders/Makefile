# $NetBSD: Makefile,v 1.4 2006/08/25 21:33:04 dhowland Exp $
#

DISTNAME=		ninvaders-0.1.1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ninvaders/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://ninvaders.sourceforge.net/
COMMENT=		ncurses based invaders game

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nInvaders ${PREFIX}/bin/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
