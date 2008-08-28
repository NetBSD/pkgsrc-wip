# $NetBSD: Makefile,v 1.1.1.1 2008/08/28 02:59:06 phonohawk Exp $
#

DISTNAME=	pointfree-1.0.1
CATEGORIES=	devel
MASTER_SITES=	http://hackage.haskell.org/packages/archive/pointfree/1.0.1/

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://haskell.org/haskellwiki/Pointfree
COMMENT=	Convert Haskell expressions to pointfree form

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
.include "../../mk/bsd.pkg.mk"
