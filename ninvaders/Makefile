# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:31 tvierling Exp $
#

DISTNAME=		ninvaders-0.1.1
CATEGORIES=		wip games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ninvaders/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://ninvaders.sourceforge.net/
COMMENT=		ncurses based invaders game

WRKSRC=		${WRKDIR}/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nInvaders ${PREFIX}/bin/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
