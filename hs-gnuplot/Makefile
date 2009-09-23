# $NetBSD: Makefile,v 1.1.1.1 2009/09/23 13:00:58 phonohawk Exp $
#

DISTNAME=	gnuplot-0.3.3
CATEGORIES=	graphics

MAINTAINER=	pho@cielonegro.org
COMMENT=	2D and 3D plots using gnuplot
LICENSE=	modified-bsd

DEPENDS+=	gnuplot-[0-9]*:../../graphics/gnuplot
.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-monoid-transformer/buildlink3.mk"
.include "../../wip/hs-time/buildlink3.mk"
.include "../../wip/hs-utility-ht/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
