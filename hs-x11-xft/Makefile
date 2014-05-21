# $NetBSD: Makefile,v 1.6 2014/05/21 21:04:46 szptvlfn Exp $
DISTNAME=	X11-xft-${VERSION}
PKGNAME=	hs-x11-xft-${VERSION}
VERSION=	0.3.1
CATEGORIES=	devel

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://hackage.haskell.org/cgi-bin/hackage-scripts/package/X11-xft
COMMENT=	Bindings to the Xft library, and some Xrender parts
LICENSE=	gnu-gpl-v2

.include "../../x11/libXft/buildlink3.mk"
.include "../../wip/mk/haskell.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../x11/hs-X11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
