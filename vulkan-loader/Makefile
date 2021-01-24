# $NetBSD$

GITHUB_PROJECT=	Vulkan-Loader
DISTNAME=	sdk-1.1.126.0
PKGNAME=	${GITHUB_PROJECT:tl}-${DISTNAME:S/sdk-//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=KhronosGroup/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	${DISTNAME}
EXTRACT_USING=	bsdtar

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/Vulkan-Loader/
COMMENT=	Loader for Vulkan Graphics API
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

# wayland support missing in pkgsrc
CMAKE_ARGS+=	-DBUILD_WSI_WAYLAND_SUPPORT=OFF
CMAKE_ARGS+=	-DBUILD_TESTS=ON

PKGCONFIG_OVERRIDE+=	loader/vulkan.pc.in

.include "../../devel/googletest/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../graphics/vulkan-headers/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
