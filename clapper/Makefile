# $NetBSD$

DISTNAME=	clapper-0.10.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=Rafostar/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	gourd753+netbsd@xenos5.net
HOMEPAGE=	https://github.com/Rafostar/clapper/
COMMENT=	Modern media player
LICENSE=	gnu-lgpl-v3 AND gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config cmake
MESON_ARGS+=		-Denhancers-loader=disabled

.include "../../x11/gtk4/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../graphics/gst-plugins1-gl/buildlink3.mk"
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../devel/appstream/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
