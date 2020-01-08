# $NetBSD$

GITHUB_PROJECT=	aseprite
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
DISTNAME=	Aseprite-v1.2.16.2-Source
PKGNAME=	${DISTNAME:S,-v,-,:S,-Source,,}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=aseprite/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aseprite/aseprite/
COMMENT=	Animated sprite editor & pixel art tool
#LICENSE=	Aseprite-license

WRKSRC=		${WRKDIR}
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARGS+=	..

pre-configure:
	${MKDIR} ${WRKSRC}/build

PKGCONFIG_OVERRIDE+=	laf/third_party/googletest/googlemock/cmake/gmock.pc.in
PKGCONFIG_OVERRIDE+=	laf/third_party/googletest/googlemock/cmake/gmock_main.pc.in
PKGCONFIG_OVERRIDE+=	laf/third_party/googletest/googletest/cmake/gtest.pc.in
PKGCONFIG_OVERRIDE+=	laf/third_party/googletest/googletest/cmake/gtest_main.pc.in
PKGCONFIG_OVERRIDE+=	laf/third_party/stringencoders/src/stringencoders.pc.in
PKGCONFIG_OVERRIDE+=	third_party/benchmark/cmake/benchmark.pc.in
PKGCONFIG_OVERRIDE+=	third_party/cmark/src/libcmark.pc.in
PKGCONFIG_OVERRIDE+=	third_party/harfbuzz/src/harfbuzz-gobject.pc.in
PKGCONFIG_OVERRIDE+=	third_party/harfbuzz/src/harfbuzz-icu.pc.in
PKGCONFIG_OVERRIDE+=	third_party/harfbuzz/src/harfbuzz-subset.pc.in
PKGCONFIG_OVERRIDE+=	third_party/harfbuzz/src/harfbuzz.pc.in
PKGCONFIG_OVERRIDE+=	third_party/json11/json11.pc.in
PKGCONFIG_OVERRIDE+=	third_party/libarchive/build/pkgconfig/libarchive.pc.in
PKGCONFIG_OVERRIDE+=	third_party/libpng/libpng.pc.in
PKGCONFIG_OVERRIDE+=	third_party/libpng/scripts/libpng.pc.in
PKGCONFIG_OVERRIDE+=	third_party/libwebp/src/demux/libwebpdemux.pc.in
PKGCONFIG_OVERRIDE+=	third_party/libwebp/src/libwebp.pc.in
PKGCONFIG_OVERRIDE+=	third_party/libwebp/src/libwebpdecoder.pc.in
PKGCONFIG_OVERRIDE+=	third_party/libwebp/src/mux/libwebpmux.pc.in
PKGCONFIG_OVERRIDE+=	third_party/pixman/pixman-1.pc.in
PKGCONFIG_OVERRIDE+=	third_party/zlib/contrib/minizip/minizip.pc.in
PKGCONFIG_OVERRIDE+=	third_party/zlib/zlib.pc.in

CMAKE_ARGS+=	-DUSE_SHARED_CMARK=ON
CMAKE_ARGS+=	-DUSE_SHARED_CURL=ON
CMAKE_ARGS+=	-DUSE_SHARED_GIFLIB=ON
CMAKE_ARGS+=	-DUSE_SHARED_JPEGLIB=ON
CMAKE_ARGS+=	-DUSE_SHARED_ZLIB=ON
CMAKE_ARGS+=	-DUSE_SHARED_LIBPNG=ON
CMAKE_ARGS+=	-DUSE_SHARED_TINYXML=ON
CMAKE_ARGS+=	-DUSE_SHARED_PIXMAN=ON
CMAKE_ARGS+=	-DUSE_SHARED_FREETYPE=ON
CMAKE_ARGS+=	-DUSE_SHARED_HARFBUZZ=ON

post-install:
.for i in bin/bsd* include lib share/man
	${RM} -rf ${DESTDIR}${PREFIX}/${i}
.endfor

.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../textproc/cmark/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
