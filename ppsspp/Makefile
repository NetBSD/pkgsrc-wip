# $NetBSD$

DISTNAME=	ppsspp-1.17.1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=hrydgard/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://www.ppsspp.org/
COMMENT=	PSP emulator
LICENSE=	gnu-gpl-v2

# There's a crash that consistently happens whenever PPSSPPSDL exits, but
# only when built with GCC. Works fine with Clang, though.
BUILD_DEPENDS+=	clang-[0-9]*:../../lang/clang

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17
USE_TOOLS+=		pkg-config

CFLAGS+=		-fPIE

ONLY_FOR_PLATFORM=	*-*-*arm* *-*-x86_64 *-*-i386

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_C_COMPILER=${CLANGBASE:Q}/bin/clang
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_COMPILER=${CLANGBASE:Q}/bin/clang++
CMAKE_CONFIGURE_ARGS+=	-DUSE_DISCORD=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_FFMPEG=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_LIBPNG=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_LIBSDL2=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_LIBZIP=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_MINIUPNPC=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_SNAPPY=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_ZSTD=ON

NOT_PAX_ASLR_SAFE+=	bin/PPSSPPSDL
NOT_PAX_MPROTECT_SAFE+=	bin/PPSSPPSDL

# wiz 20240314:
# the ninja generator has problems in some environments:
# ninja: error: manifest 'build.ninja' still dirty after 100 tries, perhaps system time is not set
CMAKE_GENERATORS_INCOMPATIBLE=	ninja

.include "../../mk/compiler/clang.mk"
.include "../../devel/cmake/build.mk"
.include "../../lang/python/tool.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../net/miniupnpc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
