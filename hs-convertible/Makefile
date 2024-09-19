# $NetBSD: Makefile,v 1.9 2014/05/18 21:33:26 szptvlfn Exp $
#

DISTNAME=	convertible-1.0.11.0
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Typeclasses and instances for converting between types
LICENSE=	modified-bsd

CONFIGURE_ARGS+=	-fsplitBase -ftime_gte_113

.include "../../wip/mk/haskell.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
