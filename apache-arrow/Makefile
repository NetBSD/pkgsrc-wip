# $NetBSD$

DISTNAME=	apache-arrow-${APACHE_ARROW_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE:=arrow/arrow-${APACHE_ARROW_VERSION}/}/


MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://arrow.apache.org/
COMMENT=	Cross-language development platform for in-memory analytics
LICENSE=	apache-2.0

# These packages are built within arrow, and it
# looks difficult to decouple them
# They come from ./cpp/thirdparty/versions.txt
XSIMD=		9.0.1.tar.gz
JEMALLOC=	jemalloc-5.3.0.tar.bz2
DISTFILES+=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		${XSIMD}
DISTFILES+=		${JEMALLOC}

SITES.${XSIMD}=		https://github.com/xtensor-stack/xsimd/archive/
SITES.${JEMALLOC}=	${MASTER_SITE_GITHUB:=jemalloc/jemalloc/releases/download/5.3.0/}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

CONFIGURE_DIR=	cpp

USE_LANGUAGES=	c c++
USE_TOOLS=	gmake install
# Needs gnu install for -v option
TOOLS_PLATFORM.install=

CMAKE_ARGS+=	-DCMAKE_INSTALL_LIBDIR=lib
CMAKE_ARGS+=	-DARROW_DEPENDENCY_SOURCE=SYSTEM
# Not yet for Gandiva
CMAKE_ARGS+=	-DARROW_GANDIVA=OFF
CMAKE_ARGS+=	-DARROW_CUDA=OFF
# These seem OK
CMAKE_ARGS+=	-DARROW_FILESYSTEM=ON
CMAKE_ARGS+=	-DARROW_BUILD_UTILITIES=ON
CMAKE_ARGS+=	-DARROW_CSV=ON
CMAKE_ARGS+=	-DARROW_ACERO=ON
CMAKE_ARGS+=	-DARROW_DATASET=ON
CMAKE_ARGS+=	-DPARQUET_BUILD_EXECUTABLES=ON

# For finding deps
CMAKE_ARGS+=	-Dxsimd_SOURCE=BUNDLED

# Set environment variable to find the extra source packages
CONFIGURE_ENV+=	ARROW_JEMALLOC_URL=/${DISTDIR}/${JEMALLOC}
CONFIGURE_ENV+=	ARROW_XSIMD_URL=/${DISTDIR}/${XSIMD}

# To enable tests, devel/googletest needs -fPIE removed
CMAKE_ARGS+=	-DARROW_BUILD_TESTS=OFF

# Fix this version expansion as we have to
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/gdb/auto-load/${LOCALBASE}/lib/libarrow.so.${APACHE_ARROW_VERSION:C/\./0/1}.0-gdb.py ${DESTDIR}${PREFIX}/share/arrow/gdb/


.include "../../wip/apache-arrow/version.mk"
.include "../../converters/utf8proc/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/gflags/buildlink3.mk"
# .include "../../devel/googletest/buildlink3.mk"
.include "../../devel/flatbuffers/buildlink3.mk"
.include "../../devel/libthrift/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../net/grpc/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
