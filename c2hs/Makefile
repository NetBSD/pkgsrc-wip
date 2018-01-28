# $NetBSD: Makefile,v 1.8 2012/09/24 18:26:51 asau Exp $
#

DISTNAME=	c2hs-0.14.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cse.unsw.edu.au/~chak/haskell/c2hs/

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://www.cse.unsw.edu.au/~chak/haskell/c2hs/
COMMENT=	C->Haskell, an Interface Generator for Haskell
LICENSE=	gnu-gpl-v2

EGDIR=		${PREFIX}/share/examples/${PKGBASE}

do-configure:
	cd ${WRKSRC} &&						\
	runhaskell Setup.hs configure					\
	  --ghc								\
	  --prefix=${PREFIX}						\
	  --with-compiler=${PREFIX}/bin/ghc				\
	  --with-hc-pkg=${PREFIX}/bin/ghc-pkg

do-build:
	cd ${WRKSRC} && runhaskell Setup.hs build

do-install:
	cd ${WRKSRC} && runhaskell Setup.hs install

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/c2hs/tests && ${INSTALL_DATA} * ${EGDIR}

.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
