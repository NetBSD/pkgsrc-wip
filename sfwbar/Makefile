# $NetBSD$

DISTNAME=	sfwbar-1.0_beta16.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=LBCrion/}
GITHUB_TAG=	d30db7c77fde25093f55eae8203f5a4995768152

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/LBCrion/sfwbar/
COMMENT=	S* Floating Window Bar for wayland compositors
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/sfwbar

MESON_ARGS+=	-Dpulse=disabled
MESON_ARGS+=	-Dpipewire=disabled
MESON_ARGS+=	-Dalsa=disabled
MESON_ARGS+=	-Diwd=disabled
MESON_ARGS+=	-Dnm=disabled
MESON_ARGS+=	-Dxkb=enabled
MESON_ARGS+=	-Ddbus=enabled

.include "../../wip/gtk-layer-shell/buildlink3.mk"

.include "../../devel/meson/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
