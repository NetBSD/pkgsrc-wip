# $NetBSD: Makefile,v 1.7 2007/08/12 16:10:50 rillig Exp $
#

DISTNAME=		vche-1.7.2
CATEGORIES=		editors
MASTER_SITES=		http://www.grigna.com/diego/linux/vche/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.grigna.com/diego/linux/vche/
COMMENT=		Hex Editor for console

USE_TOOLS+=		gmake
BUILD_DIRS=		src
MAKE_FILE=		Rules.make
MAKE_FLAGS=		VCHE_NC=1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/vche-nc ${PREFIX}/bin/vche

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
