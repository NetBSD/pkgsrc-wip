# $NetBSD: Makefile,v 1.20 2007/01/23 08:24:17 bsadewitz Exp $
#

DISTNAME=	libXfont-1.2.7
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/lib/
COMMENT=	LibXfont from modular X.org project--current version

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews


PKGCONFIG_OVERRIDE+=	xfont.pc.in

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CPPFLAGS+=	-D_NETBSD_SOURCE

PKGCONFIG_OVERRIDE+=	xfont.pc.in

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/fontcacheproto/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
