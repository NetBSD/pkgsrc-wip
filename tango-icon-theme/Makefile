# $NetBSD: Makefile,v 1.1.1.1 2009/03/16 18:25:03 roelants Exp $

DISTNAME=	tango-icon-theme-0.8.90
CATEGORIES=	graphics
MASTER_SITES=	http://tango.freedesktop.org/releases/

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	http://tango.freedesktop.org/Tango_Desktop_Project
COMMENT=	Tango desktop project icon theme

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool pkg-config

BUILDLINK_DEPMETHOD.ImageMagick=	build
BUILDLINK_API_DEPENDS.icon-naming-utils+=	icon-naming-utils>=0.8.90

USE_DIRS+=	xdg-1.4

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
