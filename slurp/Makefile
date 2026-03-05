# $NetBSD$

DISTNAME=	slurp-1.5.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=emersion/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/emersion/slurp/
COMMENT=	Tool to select a region in a Wayland compositor
LICENSE=	mit

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../wip/input-headers/buildlink3.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../mk/bsd.pkg.mk"
