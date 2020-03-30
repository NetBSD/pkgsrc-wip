# $NetBSD: Makefile,v 1.325 2020/03/10 22:08:49 wiz Exp $

DISTNAME=	glimpse-0.1.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=glimpse-editor/}
GITHUB_PROJECT=	Glimpse
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://glimpse-editor.org/
COMMENT=	Fork of the GNU Image Manipulation Program
LICENSE=	gnu-lgpl-v3 AND gnu-gpl-v3

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
TOOL_DEPENDS+=	gettext-tools>=0.19:../../devel/gettext-tools
DEPENDS+=	glib-networking>=2.36.2:../../net/glib-networking

USE_LANGUAGES+=		c c++14
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

USE_TOOLS+=		gmake pkg-config perl
USE_TOOLS+=		intltool msgfmt msgmerge xgettext

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-alsatest
CONFIGURE_ARGS+=	--disable-glibtest
CONFIGURE_ARGS+=	--disable-gtktest
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-aa
CONFIGURE_ARGS+=	--without-alsa
CONFIGURE_ARGS+=	--without-gs
CONFIGURE_ARGS+=	--without-linux-input
CONFIGURE_ARGS+=	--without-libheif
CONFIGURE_ARGS+=	--without-libmng
CONFIGURE_ARGS+=	--without-webkit

# ??? needed with builtin netbsd xz
CONFIGURE_ENV+=		LZMA_LIBS=-llzma
CONFIGURE_ENV+=		LZMA_CFLAGS=-I${BUILDLINK_PREFIX.xz}/include

PKG_SYSCONFSUBDIR=	glimpse/2.0
PKGCONFIG_OVERRIDE=	gimp.pc.in
UNLIMIT_RESOURCES+=	datasize

# GCC 4.x C++14 support is not new enough.
GCC_REQD+=	5

.include "../../mk/bsd.prefs.mk"

EGDIR=			${PREFIX}/share/examples/glimpse-2.0
.for f in controllerrc gimprc gtkrc menurc sessionrc templaterc unitrc
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

# checking for xgettext version (>= 0.19)... no
_TOOLS_USE_PKGSRC.xgettext=	yes

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

pre-configure:
	ln -s mypaint-brushes-2.0.pc	\
	  ${BUILDLINK_DIR}/share/pkgconfig/mypaint-brushes-1.0.pc

.include "../../archivers/xz/buildlink3.mk"
BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.8.1
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.12.4
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.babl+=		babl>=0.1.72
.include "../../graphics/babl/buildlink3.mk"
BUILDLINK_API_DEPENDS.gegl+=		gegl>=0.4.18
.include "../../graphics/gegl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/gexiv2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libmypaint/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/mypaint-brushes/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../print/poppler-data/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.gtk2:Mx11)
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-xmc
CONFIGURE_ARGS+=	--without-libxpm
.endif
.if !empty(PKG_BUILD_OPTIONS.gtk2:Mquartz)
.include "../../x11/gtk-mac-integration/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
