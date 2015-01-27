# $NetBSD: Makefile,v 1.14 2015/01/27 14:13:32 szptvlfn Exp $

DISTNAME=	haskell-src-exts-1.16.0.1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Manipulating Haskell source
LICENSE=	modified-bsd

BUILD_DEPENDS+=	happy>=1.17:../../devel/happy

.include "../../mk/haskell.mk"
.include "../../devel/hs-cpphs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
