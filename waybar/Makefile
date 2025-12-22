# $NetBSD$

DISTNAME=	waybar-0.14.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=Alexays/}
GITHUB_PROJECT=	Waybar
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/Alexays/Waybar/
COMMENT=	Wayland bar for Wlroots based compositors
LICENSE=	mit

USE_CXX_FEATURES+=	filesystem
USE_LANGUAGES=		c c++

USE_TOOLS+=	pkg-config gdbus-codegen

SUBST_CLASSES+=		nogit
SUBST_STAGE.nogit=	pre-configure
SUBST_MESSAGE.nogit=	Set version
SUBST_FILES.nogit+=	meson.build
SUBST_SED.nogit+=	-e 's/git =/\#git =/g'
SUBST_SED.nogit+=	-e 's/git.found()/false/g'
SUBST_SED.nogit+=	-e '/project_version/s/@0@/${PKGVERSION}/g'

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_MESSAGE.conf=	Set SYSCONFDIR
SUBST_FILES.conf+=	src/config.cpp
SUBST_SED.conf+=	-e 's|SYSCONFDIR "|"${PKG_SYSCONFBASE}|g'

EGDIR=		${PREFIX}/share/examples/waybar
CONF_FILES=	${EGDIR}/config.jsonc ${PKG_SYSCONFDIR}/config.jsonc
CONF_FILES+=	${EGDIR}/style.css ${PKG_SYSCONFDIR}/style.css

PKG_SYSCONFSUBDIR=	xdg/waybar
BUILD_DEFS+=		PKG_SYSCONFBASE

.include "../../wip/gtk-layer-shell/buildlink3.mk"

.include "../../devel/meson/build.mk"
#.include "../../textproc/scdoc/tool.mk"
.include "../../wip/scdoc/tool.mk"
.include "../../devel/libdbusmenu-gtk3/buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../geography/gpsd/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/gtkmm3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
