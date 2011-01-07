# $NetBSD: Makefile,v 1.4 2011/01/07 09:48:12 phonohawk Exp $
#

DISTNAME=	terminfo-0.3.1.3
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell bindings to the terminfo library
LICENSE=	modified-bsd

CONFIGURE_ARGS+= --extra-include-dirs=${PREFIX}/include/ncurses --extra-lib-dirs=${PREFIX}/lib

USE_NCURSES=    yes
.include "../../wip/mk/haskell.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
