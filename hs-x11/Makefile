# $NetBSD: Makefile,v 1.13 2014/05/20 21:23:20 szptvlfn Exp $
DISTNAME=	X11-${VERSION}
PKGNAME=	hs-x11-${VERSION}
VERSION=	1.6.1.2
CATEGORIES=	x11 graphics

MAINTAINER=	esg@sdf.lonestar.org
COMMENT=	Haskell binding to the X11 graphics library
LICENSE=	modified-bsd

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
