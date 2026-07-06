# $NetBSD$

DISTNAME=	wayvnc-0.10.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=any1/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/any1/wayvnc/
COMMENT=	VNC server for wlroots based Wayland compositors
LICENSE=	isc

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../devel/aml/buildlink3.mk"
.include "../../devel/input-headers/buildlink3.mk"
.include "../../wip/neatvnc/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
