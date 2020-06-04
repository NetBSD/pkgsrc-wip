# $NetBSD$

GITHUB_PROJECT=	sway
GITHUB_TAG=	1.4
DISTNAME=	1.4
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=swaywm/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://github.com/swaywm/sway/
COMMENT=	Sway is an i3-compatible Wayland compositor
LICENSE=	mit

WRKSRC=	${WRKDIR}/sway-1.4

.include "../../wip/wlroots/buildlink3.mk"
.include "../../wip/libinput/buildlink3.mk"
.include "../../wip/libevdev/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
