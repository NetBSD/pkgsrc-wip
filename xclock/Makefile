# $NetBSD: Makefile,v 1.1 2007/01/29 07:02:54 bsadewitz Exp $
#

DISTNAME=	xclock-1.0.2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/app/
COMMENT=	Classic X11 clock application from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

PKG_OPTIONS_VAR= PKG_OPTIONS.xclock
PKG_SUPPORTED_OPTIONS= xrender
PKG_SUGGESTED_OPTIONS= xrender
.include "../../mk/bsd.options.mk"
# url2pkg-marker (please do not remove this line.)

.if !empty(${PKG_OPTIONS.xclock:Mxrender})
.include "../../x11/libXrender/buildlink3.mk"
.endif

.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
