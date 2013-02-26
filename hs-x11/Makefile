# $NetBSD: Makefile,v 1.10 2013/02/26 12:51:12 szptvlfn Exp $
DISTNAME=	X11-${VERSION}
PKGNAME=	hs-x11-${VERSION}
VERSION=	1.6.1.1
CATEGORIES=	devel

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://code.haskell.org/X11
COMMENT=	Haskell binding to the X11 graphics library

LICENSE=	modified-bsd

.include "../../x11/libX11/buildlink3.mk"
.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-data-default/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
