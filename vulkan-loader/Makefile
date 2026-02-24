# $NetBSD$

DISTNAME=	vulkan-loader-1.4.335.0 # matches vulkan-headers
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

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DFALLBACK_CONFIG_DIRS="${PKG_SYSCONFDIR}/xdg"
CMAKE_CONFIGURE_ARGS+=	-DFALLBACK_DATA_DIRS="${X11BASE}/share:${PREFIX}/share:/usr/share"

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

PKGCONFIG_OVERRIDE+=	loader/vulkan.pc.in

.include "../../devel/cmake/build.mk"
.include "../../lang/python/tool.mk"
.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../graphics/vulkan-headers/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
