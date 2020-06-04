# $NetBSD$

DISTNAME=	sway-1.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=swaywm/}

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://github.com/swaywm/sway/
COMMENT=	Sway is an i3-compatible Wayland compositor
LICENSE=	mit

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
