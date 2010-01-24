# $NetBSD: Makefile,v 1.3 2010/01/24 03:12:27 phonohawk Exp $
#

DISTNAME=	terminfo-0.3.1.1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell bindings to the terminfo library
LICENSE=	modified-bsd

CONFIGURE_ARGS+= --extra-include-dirs=${PREFIX}/include/ncurses --extra-lib-dirs=${PREFIX}/lib

.include "../../wip/mk/haskell.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
