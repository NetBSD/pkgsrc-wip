# $NetBSD: Makefile,v 1.7 2011/12/01 02:33:53 phonohawk Exp $
#

DISTNAME=	convertible-1.0.11.0
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Typeclasses and instances for converting between types
LICENSE=	modified-bsd

CONFIGURE_ARGS+=	-fsplitBase -ftime_gte_113

.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
