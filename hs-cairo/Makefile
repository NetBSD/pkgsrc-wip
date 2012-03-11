# $NetBSD: Makefile,v 1.2 2012/03/11 07:35:05 phonohawk Exp $
#

DISTNAME=	cairo-0.12.3
CATEGORIES=	graphics

MAINTAINER=	pho@cielonegro.org
COMMENT=	Binding to the Cairo library
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
.include "options.mk"

.include "../../wip/mk/haskell.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../wip/gtk2hs-buildtools/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
