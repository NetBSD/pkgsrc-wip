# $NetBSD: Makefile,v 1.5 2012/03/04 07:40:02 phonohawk Exp $
#

DISTNAME=	terminfo-0.3.2.3
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell bindings to the terminfo library
LICENSE=	modified-bsd

CONFIGURE_ARGS+= --extra-include-dirs=${PREFIX}/include/ncurses --extra-lib-dirs=${PREFIX}/lib

USE_NCURSES=    yes
.include "../../wip/mk/haskell.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
