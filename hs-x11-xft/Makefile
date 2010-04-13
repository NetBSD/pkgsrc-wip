# $NetBSD: Makefile,v 1.1.1.1 2010/04/13 18:35:27 emil_s Exp $
DISTNAME=	X11-xft-${VERSION}
PKGNAME=	hs-x11-xft-${VERSION}
VERSION=	0.3
CATEGORIES=	devel

MAINTAINER=	esg@sdf.org
HOMEPAGE=	http://hackage.haskell.org/cgi-bin/hackage-scripts/package/X11-xft
COMMENT=	Bindings to the Xft library, and some Xrender parts

LICENSE=	gnu-gpl-v2

.include "../../x11/libXft/buildlink3.mk"
BUILDLINK_API_DEPENDS.hs-x11+=	hs-x11>=1.2.1
.include "../../wip/hs-x11/buildlink3.mk"
BUILDLINK_API_DEPENDS.hs-utf8-string+=	hs-utf8-string>=0.1
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../wip/mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
