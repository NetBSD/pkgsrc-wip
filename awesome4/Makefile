# $NetBSD: Makefile,v 1.57 2016/08/27 08:04:42 maya Exp $
#

DISTNAME=	awesome-4.1
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=awesomeWM/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	https://awesomewm.org/
COMMENT=	Tiling window manager based on dwm
LICENSE=	gnu-gpl-v2

CONFLICTS+=	awesome<3.0

USE_TOOLS+=	bash gmake pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PKG_SYSCONFSUBDIR=	xdg/awesome

CMAKE_ARGS+=	-DWITH_DBUS=OFF
CMAKE_ARGS+=	-DSYSCONFDIR=${PKG_SYSCONFDIR:C/\/xdg\/awesome//}
CMAKE_ARGS+=	-DCOMPRESS_MANPAGES=${MANZ:Q}
CMAKE_ARGS+=	-DAWESOME_MAN_PATH=${PREFIX}/${PKGMANDIR}
CMAKE_ARGS+=	-DLUA_EXECUTABLE=${LUA_INTERPRETER}

EGDIR=		${PREFIX}/share/examples/awesome
CONF_FILES=	${EGDIR}/rc.lua ${PKG_SYSCONFDIR}/rc.lua

SUBST_CLASSES+=		eg
SUBST_MESSAGE.eg=	Fixing pathnames
SUBST_STAGE.eg=		pre-configure
SUBST_FILES.eg=		CMakeLists.txt
SUBST_SED.eg=		-e "s,\$${AWESOME_SYSCONFDIR},${EGDIR},"

SUBST_CLASSES+=		lua
SUBST_MESSAGE.lua=	Fixing lua prefix
SUBST_STAGE.lua=	pre-configure
SUBST_FILES.lua=	build-utils/lgi-check.sh
SUBST_SED.lua=		-e "s,lua -e,${LUA_INTERPRETER} -e,"

LDFLAGS.Darwin+=	-liconv
LDFLAGS.SunOS+=		-liconv

BUILD_DEPENDS+=		ImageMagick-[0-9]*:../../graphics/ImageMagick
BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto
BUILD_DEPENDS+=		${LUA_PKGPREFIX}-ldoc-[0-9]*:../../wip/lua-ldoc
DEPENDS+=		${LUA_PKGPREFIX}-gi>=0.7.0:../../wip/lua-gi

pre-configure:
	# XXX pkgsrc does not enable out-of-source cmake build
	${MV} ${WRKSRC}/awesomerc.lua ${WRKSRC}/awesomerc.lua.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxdg-basedir/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-xrm/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"

.include "../../lang/lua/luaversion.mk"

.include "../../mk/bsd.pkg.mk"
