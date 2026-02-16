# $NetBSD$

DISTNAME=	gtk4-layer-shell-1.3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=wmww/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/wmww/gtk4-layer-shell/
COMMENT=	Library to create desktop components for Wayland
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
