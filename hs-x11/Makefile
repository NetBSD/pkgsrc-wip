# $NetBSD: Makefile,v 1.11 2013/07/22 19:50:08 zul_ Exp $
DISTNAME=	X11-${VERSION}
PKGNAME=	hs-x11-${VERSION}
VERSION=	1.6.1.1
CATEGORIES=	devel

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://code.haskell.org/X11
COMMENT=	Haskell binding to the X11 graphics library

LICENSE=	modified-bsd

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-data-default/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
