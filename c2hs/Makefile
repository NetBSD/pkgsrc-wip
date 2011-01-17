# $NetBSD: Makefile,v 1.6 2011/01/17 10:48:03 emil_s Exp $
#

DISTNAME=	c2hs-0.14.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cse.unsw.edu.au/~chak/haskell/c2hs/

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://www.cse.unsw.edu.au/~chak/haskell/c2hs/
COMMENT=	C->Haskell, an Interface Generator for Haskell


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
.include "../../mk/bsd.pkg.mk"
