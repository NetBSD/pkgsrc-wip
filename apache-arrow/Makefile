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
XSIMD=		14.0.0.tar.gz
JEMALLOC=	jemalloc-5.3.0.tar.bz2
MIMALLOC=	v3.1.5.tar.gz
SUBSTRAIT=	v0.44.0.tar.gz

DISTFILES+=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		${XSIMD}
DISTFILES+=		${JEMALLOC}
DISTFILES+=		${MIMALLOC}
DISTFILES+=		${SUBSTRAIT}

SITES.${XSIMD}=		https://github.com/xtensor-stack/xsimd/archive/
SITES.${SUBSTRAIT}=		https://github.com/substrait-io/substrait/archive/
SITES.${JEMALLOC}=	${MASTER_SITE_GITHUB:=jemalloc/jemalloc/releases/download/5.3.0/}
SITES.${MIMALLOC}=	${MASTER_SITE_GITHUB:=microsoft/mimalloc/archive/}

.include "../../mk/bsd.prefs.mk"

CONFIGURE_DIR=	cpp

USE_LANGUAGES=	c c++
USE_TOOLS=	gmake install
# Needs gnu install for -v option
TOOLS_PLATFORM.install=

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_LIBDIR=lib
CMAKE_CONFIGURE_ARGS+=	-DARROW_DEPENDENCY_SOURCE=SYSTEM
# Not yet for Gandiva
CMAKE_CONFIGURE_ARGS+=	-DARROW_GANDIVA=OFF
CMAKE_CONFIGURE_ARGS+=	-DARROW_CUDA=OFF
# These seem OK
CMAKE_CONFIGURE_ARGS+=	-DARROW_FILESYSTEM=ON
CMAKE_CONFIGURE_ARGS+=	-DARROW_BUILD_UTILITIES=ON
CMAKE_CONFIGURE_ARGS+=	-DARROW_CSV=ON
CMAKE_CONFIGURE_ARGS+=	-DARROW_ACERO=ON
CMAKE_CONFIGURE_ARGS+=	-DARROW_DATASET=ON
CMAKE_CONFIGURE_ARGS+=	-DARROW_WITH_BROTLI=ON
CMAKE_CONFIGURE_ARGS+=	-DARROW_WITH_BZ2=ON
CMAKE_CONFIGURE_ARGS+=	-DARROW_USE_GLOG=OFF=ON
CMAKE_CONFIGURE_ARGS+=	-DARROW_JSON=ON
CMAKE_CONFIGURE_ARGS+=	-DARROW_WITH_LZ4=ON
CMAKE_CONFIGURE_ARGS+=	-DARROW_PARQUET=ON
CMAKE_CONFIGURE_ARGS+=	-DPARQUET_BUILD_EXECUTABLES=ON
CMAKE_CONFIGURE_ARGS+=	-DPARQUET_REQUIRE_ENCRYPTION=ON
CMAKE_CONFIGURE_ARGS+=	-DARROW_SUBSTRAIT=OFF
CMAKE_CONFIGURE_ARGS+=	-DARROW_FLIGHT=OFF
CMAKE_CONFIGURE_ARGS+=	-DARROW_WITH_SNAPPY=ON
CMAKE_CONFIGURE_ARGS+=	-DARROW_WITH_ZLIB=ON
CMAKE_CONFIGURE_ARGS+=	-DARROW_WITH_ZSTD=ON

# For finding deps
CMAKE_CONFIGURE_ARGS+=	-Dxsimd_SOURCE=BUNDLED

# Set environment variable to find the extra source packages
CONFIGURE_ENV+=	ARROW_JEMALLOC_URL=/${DISTDIR}/${JEMALLOC}
CONFIGURE_ENV+=	ARROW_XSIMD_URL=/${DISTDIR}/${XSIMD}
CONFIGURE_ENV+=	ARROW_SUBSTRAIT_URL=/${DISTDIR}/${SUBSTRAIT}
CONFIGURE_ENV+=	ARROW_MIMALLOC_URL=/${DISTDIR}/${MIMALLOC}

# To enable tests, devel/googletest needs -fPIE removed
CMAKE_CONFIGURE_ARGS+=	-DARROW_BUILD_TESTS=OFF

# Fix this version expansion as we have to
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/gdb/auto-load/${LOCALBASE}/lib/libarrow.so.${APACHE_ARROW_VERSION:C/\./0/1}.0-gdb.py ${DESTDIR}${PREFIX}/share/arrow/gdb/


.include "../../wip/apache-arrow/version.mk"
.include "../../archivers/brotli/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../converters/utf8proc/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/gflags/buildlink3.mk"
.include "../../devel/google-glog/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
#.include "../../devel/googletest/buildlink3.mk"
# as of v21.0.0 they use an internal version of flatbuffers
#.include "../../devel/flatbuffers/buildlink3.mk"
.include "../../devel/libthrift/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../net/grpc/buildlink3.mk"
.include "../../textproc/rapidjson/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
