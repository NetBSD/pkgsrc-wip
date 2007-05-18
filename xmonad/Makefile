# $NetBSD: Makefile,v 1.1.1.1 2007/05/18 12:31:55 emil_s Exp $
#

DISTNAME=	xmonad-${VERSION}
CATEGORIES=	wm
MASTER_SITES=	http://hackage.haskell.org/packages/archive/xmonad/

MAINTAINER=	emil@math.su.se
HOMEPAGE=	http://xmonad.org/
COMMENT=	Minimalist tiling window manager for X

USE_LANGUAGES+=	c

VERSION=		0.1

do-configure:
	cd ${WRKSRC:Q} &&						\
        runhaskell -cpp Setup.lhs configure				\
          --ghc								\
          --prefix=${PREFIX:Q}						\
          --with-compiler=${PREFIX:Q}/bin/ghc				\
          --with-hc-pkg=${PREFIX:Q}/bin/ghc-pkg

do-build:
	cd ${WRKSRC:Q} && runhaskell -cpp Setup.lhs build

do-install:
	cd ${WRKSRC:Q} && runhaskell -cpp Setup.lhs install


.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-x11-extras/buildlink3.mk"
.include "../../wip/hs-x11/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
