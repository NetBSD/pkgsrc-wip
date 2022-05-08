# $NetBSD$

DISTNAME=	apache-arrow-7.0.0
CATEGORIES=	devel
MASTER_SITES=	https://dlcdn.apache.org/arrow/arrow-7.0.0/


MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://arrow.apache.org/
COMMENT=	Cross-language development platform for in-memory analytics
LICENSE=	apache-2.0

# These packages are built within arrow, and it
# looks difficult to decouple them
XSIMD=		aeec9c872c8b475dedd7781336710f2dd2666cb2.tar.gz
JEMALLOC=	jemalloc-5.2.1.tar.bz2

DISTFILES+=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		${XSIMD}
DISTFILES+=		${JEMALLOC}
SITES.${XSIMD}=		https://github.com/xtensor-stack/xsimd/archive/
SITES.${JEMALLOC}=	${MASTER_SITE_GITHUB:=jemalloc/}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

CONFIGURE_DIRS=	cpp
BUILD_DIRS=	cpp

USE_LANGUAGES=	c c++
USE_TOOLS=	cmake gmake
USE_CMAKE=	yes
CMAKE_ARGS+=	-DCMAKE_INSTALL_LIBDIR=lib
CMAKE_ARGS+=	-DARROW_DEPENDENCY_SOURCE=SYSTEM
# Not yet for Gandiva
CMAKE_ARGS+=	-DARROW_GANDIVA=OFF
# These seem OK
CMAKE_ARGS+=	-DARROW_FILESYSTEM=ON
CMAKE_ARGS+=	-DARROW_BUILD_UTILITIES=ON
CMAKE_ARGS+=	-DARROW_CSV=ON
CMAKE_ARGS+=	-DARROW_DATASET=ON

# Set environment variable to find the extra source packages
CONFIGURE_ENV+=	ARROW_JEMALLOC_URL=/${DISTDIR}/${JEMALLOC}
CONFIGURE_ENV+=	ARROW_XSIMD_URL=/${DISTDIR}/${XSIMD}

# To enable tests, devel/googletest needs -fPIE removed
CMAKE_ARGS+=	-DARROW_BUILD_TESTS=OFF

BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "../../converters/utf8proc/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../devel/libthrift/buildlink3.mk"
.include "../../devel/flatbuffers/buildlink3.mk"

# .include "../../devel/googletest/buildlink3.mk"

.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../net/grpc/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
