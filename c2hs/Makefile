# $NetBSD: Makefile,v 1.3 2006/09/01 10:56:25 emil_s Exp $
#

DISTNAME=	c2hs-0.14.5
CATEGORIES=	devel
MASTER_SITES=	http://www.cse.unsw.edu.au/~chak/haskell/c2hs/

MAINTAINER=	emil@math.su.se
HOMEPAGE=	http://www.cse.unsw.edu.au/~chak/haskell/c2hs/
COMMENT=	C->Haskell, an Interface Generator for Haskell

BUILD_DEPENDS+=	cabal>=1.0.1:../../wip/cabal

EGDIR=		${PREFIX}/share/examples/${PKGBASE}

do-configure:
	cd ${WRKSRC:Q} &&						\
	runhaskell Setup.hs configure					\
	  --ghc								\
	  --prefix=${PREFIX:Q}						\
	  --with-compiler=${PREFIX:Q}/bin/ghc				\
	  --with-hc-pkg=${PREFIX:Q}/bin/ghc-pkg

do-build:
	cd ${WRKSRC:Q} && runhaskell Setup.hs build

do-install:
	cd ${WRKSRC:Q} && runhaskell Setup.hs install

post-install:
	${INSTALL_DATA_DIR} ${EGDIR:Q}
	cd ${WRKSRC:Q}/c2hs/tests && ${INSTALL_DATA} * ${EGDIR:Q}

.include "../../lang/ghc/buildlink3.mk"
.include "../../wip/cabal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
