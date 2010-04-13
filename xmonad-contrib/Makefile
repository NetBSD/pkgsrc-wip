# $NetBSD: Makefile,v 1.4 2010/04/13 19:03:11 emil_s Exp $
DISTNAME=	xmonad-contrib-${VERSION}
PKGNAME=	xmonad-contrib-${VERSION}
VERSION=	0.9.1
CATEGORIES=	wm

MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	http://xmonad.org/
COMMENT=	Third party extensions for xmonad

LICENSE=	modified-bsd

.include "../../x11/libXft/buildlink3.mk"
BUILDLINK_API_DEPENDS.hs-x11+=	hs-x11>=1.5.0.0
BUILDLINK_API_DEPENDS.hs-x11+=	hs-x11<1.6
.include "../../wip/hs-x11/buildlink3.mk"
BUILDLINK_API_DEPENDS.hs-x11-xft+=	hs-x11-xft>=0.2
.include "../../wip/hs-x11-xft/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
BUILDLINK_API_DEPENDS.xmonad+=	xmonad>=0.9.1
BUILDLINK_API_DEPENDS.xmonad+=	xmonad<0.10
.include "../../wip/xmonad/buildlink3.mk"
.include "../../wip/mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
