# $NetBSD: Makefile,v 1.2 2009/09/24 09:26:52 phonohawk Exp $
#

DISTNAME=	terminfo-0.3.1.1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell bindings to the terminfo library
LICENSE=	modified-bsd

CONFIGURE_ARGS+= --extra-include-dirs=${PREFIX}/include/ncurses --extra-lib-dirs=${PREFIX}/lib

.include "../../wip/mk/haskell.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../wip/hs-extensible-exceptions/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
