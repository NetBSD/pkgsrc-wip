# $NetBSD$

DISTNAME=	ppsspp-1.16.6
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=hrydgard/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://www.ppsspp.org/
COMMENT=	PSP emulator
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++17
USE_TOOLS+=	pkg-config
.include "../../lang/python/tool.mk"

# There's a crash that consistently happens whenever PPSSPPSDL exits, but
# only when built with GCC. Works fine with Clang, though.
BUILD_DEPENDS+=	clang-[0-9]*:../../lang/clang

ONLY_FOR_PLATFORM=	*-*-*arm* *-*-x86_64 *-*-i386

CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CLANGBASE:Q}/bin/clang
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CLANGBASE:Q}/bin/clang++
CMAKE_ARGS+=	-DUSE_DISCORD=OFF
CMAKE_ARGS+=	-DUSE_SYSTEM_FFMPEG=ON
CMAKE_ARGS+=	-DUSE_SYSTEM_LIBPNG=ON
CMAKE_ARGS+=	-DUSE_SYSTEM_LIBSDL2=ON
CMAKE_ARGS+=	-DUSE_SYSTEM_LIBZIP=ON
CMAKE_ARGS+=	-DUSE_SYSTEM_MINIUPNPC=ON
CMAKE_ARGS+=	-DUSE_SYSTEM_SNAPPY=ON
CMAKE_ARGS+=	-DUSE_SYSTEM_ZSTD=ON

NOT_PAX_ASLR_SAFE+=	bin/PPSSPPSDL
NOT_PAX_MPROTECT_SAFE+=	bin/PPSSPPSDL

.include "../../mk/compiler/clang.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../net/miniupnpc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
