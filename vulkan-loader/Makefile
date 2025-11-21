# $NetBSD$

DISTNAME=	vulkan-loader-1.4.321.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=KhronosGroup/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_PROJECT=	Vulkan-Loader
GITHUB_TAG=	vulkan-sdk-${PKGVERSION_NOREV}
EXTRACT_USING=	bsdtar

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/Vulkan-Loader/
COMMENT=	Loader for Vulkan Graphics API
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

LIBVERSION=	${PKGVERSION_NOREV:R}
PLIST_SUBST+=	LIBVERSION=${LIBVERSION}

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fix fallback pathes
SUBST_FILES.path=	CMakeLists.txt
SUBST_VARS.path=	PREFIX PKG_SYSCONFBASE

# wayland support missing in pkgsrc
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WSI_WAYLAND_SUPPORT=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTS=OFF

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

PKGCONFIG_OVERRIDE+=	loader/vulkan.pc.in

.include "../../devel/cmake/build.mk"

#.include "../../devel/googletest/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../graphics/vulkan-headers/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
