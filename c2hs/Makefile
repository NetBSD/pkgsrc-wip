# $NetBSD: Makefile,v 1.1.1.1 2005/11/15 13:57:36 emil_s Exp $
#

DISTNAME=	c2hs-0.14.3
CATEGORIES=	devel
MASTER_SITES=	http://www.cse.unsw.edu.au/~chak/haskell/c2hs/

MAINTAINER=	emil@math.su.se
HOMEPAGE=	http://www.cse.unsw.edu.au/~chak/haskell/c2hs/
COMMENT=	C->Haskell, an Interface Generator for Haskell

BUILD_DEPENDS+=	cabal>=1.0.1:../../wip/cabal

EGDIR=		${PREFIX}/share/examples/${PKGBASE}

do-configure:
	@cd ${WRKSRC} &&                                       \
	runhaskell Setup.hs configure                          \
	  --ghc                                                \
	  --prefix=${PREFIX} --with-compiler=${PREFIX}/bin/ghc \
	  --with-hc-pkg=${PREFIX}/bin/ghc-pkg

do-build:
	@cd ${WRKSRC} && runhaskell Setup.hs build

do-install:
	@cd ${WRKSRC} && runhaskell Setup.hs install

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	@cd ${WRKSRC}/c2hs/tests && ${INSTALL_DATA} * ${EGDIR}

.include "../../lang/ghc/buildlink3.mk"
.include "../../wip/cabal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
