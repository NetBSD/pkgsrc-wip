# $NetBSD: Makefile,v 0.3 2018/09/07 20:03:10 andyb Exp $

DISTNAME=	efl-1.21.0
CATEGORIES=	x11
MASTER_SITES=	https://download.enlightenment.org/rel/libs/efl/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	andyb@m42.one
HOMEPAGE=	https://download.enlightenment.org/rel/libs/efl/
COMMENT=	Enlightenment foundation libraries
LICENSE=	2-clause-bsd

DEPENDS+= 		xz-[0-9]*:../../archivers/xz
DEPENDS+=		glib2-[0-9]*:../../devel/glib2
DEPENDS+=		gstreamer1-[0-9]*:../../multimedia/gstreamer1
DEPENDS+=		LuaJIT2-[0-9]*:../../lang/LuaJIT2
DEPENDS+=		freetype2-[0-9]*:../../graphics/freetype2
DEPENDS+=		fontconfig-[0-9]*:../../fonts/fontconfig
DEPENDS+=		fribidi-[0-9]*:../../converters/fribidi
DEPENDS+=		png-[0-9]*:../../graphics/png
DEPENDS+=		poppler-cpp-[0-9]*:../../print/poppler-cpp
DEPENDS+=		libspectre-[0-9]*:../../print/libspectre
DEPENDS+= 		MesaLib-[0-9]*:../../graphics/MesaLib
DEPENDS+=		giflib-[0-9]*:../../graphics/giflib
DEPENDS+=		tiff-[0-9]*:../../graphics/tiff
DEPENDS+=		libraw-[0-9]*:../../graphics/libraw
DEPENDS+=		librsvg-[0-9]*:../../graphics/librsvg
DEPENDS+=		cairo-[0-9]*:../../graphics/cairo
DEPENDS+=		dbus-[0-9]*:../../sysutils/dbus
DEPENDS+=		pulseaudio-[0-9]*:../../audio/pulseaudio
DEPENDS+=		bullet-[0-9]*:../../devel/bullet
DEPENDS+=		gst-plugins1-base-[0-9]*:../../multimedia/gst-plugins1-base
DEPENDS+=		libuuid-[0-9]*:../../devel/libuuid
#DEPENDS+=		linux-utils-[0-9]*:../util-linux

#PKG_OPTIONS.efl-1.21.0=	systemd

CONFIGURE_ARGS+=	--disable-systemd

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS=		gmake pkg-config automake autoconf
ICON_THEMES=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/bullet/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
#.include "../util-linux/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
