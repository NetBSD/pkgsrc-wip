# $NetBSD: Makefile,v 1.1.1.1 2008/08/26 05:56:07 phonohawk Exp $
#

DISTNAME=	mkcabal-0.4.1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=mkcabal/0.4.1.1/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://hackage.haskell.org/cgi-bin/hackage-scripts/package/mkcabal
COMMENT=	Generate cabal files for a Haskell project

do-configure:
	cd ${WRKSRC} && \
		runghc Setup.*hs configure --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && \
		runghc Setup.*hs build

do-install:
	cd ${WRKSRC} && \
		runghc Setup.*hs copy

.include "../../lang/ghc/buildlink3.mk"
.include "../../wip/hs-pcre-light/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
