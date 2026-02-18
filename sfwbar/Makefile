# $NetBSD$

DISTNAME=	sfwbar-1.0_beta16.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=LBCrion/}
GITHUB_TAG=	d30db7c77fde25093f55eae8203f5a4995768152

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/LBCrion/sfwbar/
COMMENT=	S* Floating Window Bar for wayland compositors
LICENSE=	gnu-gpl-v3

#USE_CXX_FEATURES+=	filesystem
USE_LANGUAGES=		c c++

USE_TOOLS+=	pkg-config
#TOOL_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

MESON_ARGS+=	-Dpulse=disabled
MESON_ARGS+=	-Dpipewire=disabled
MESON_ARGS+=	-Dalsa=disabled
MESON_ARGS+=	-Diwd=disabled
MESON_ARGS+=	-Dnm=disabled
MESON_ARGS+=	-Dxkb=enabled
MESON_ARGS+=	-Ddbus=enabled

#SUBST_CLASSES+=		nogit
#SUBST_STAGE.nogit=	pre-configure
#SUBST_MESSAGE.nogit=	Set version
#SUBST_FILES.nogit+=	meson.build
#SUBST_SED.nogit+=	-e 's/git =/\#git =/g'
#SUBST_SED.nogit+=	-e 's/git.found()/false/g'
#SUBST_SED.nogit+=	-e '/project_version/s/@0@/${PKGVERSION}/g'

#SUBST_CLASSES+=		conf
#SUBST_STAGE.conf=	pre-configure
#SUBST_MESSAGE.conf=	Set SYSCONFDIR
#SUBST_FILES.conf+=	src/config.cpp
#SUBST_SED.conf+=	-e 's|SYSCONFDIR "|"${PKG_SYSCONFBASE}|g'

#EGDIR=		${PREFIX}/share/examples/waybar
#CONF_FILES=	${EGDIR}/config.jsonc ${PKG_SYSCONFDIR}/config.jsonc
#CONF_FILES+=	${EGDIR}/style.css ${PKG_SYSCONFDIR}/style.css

.include "../../wip/gtk-layer-shell/buildlink3.mk"

.include "../../devel/meson/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
