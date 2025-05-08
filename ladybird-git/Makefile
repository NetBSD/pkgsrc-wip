# $NetBSD: Makefile,v 1.18 2015/09/13 07:33:05 thomasklausner Exp $

DISTNAME=	ladybird-0.0.0
CATEGORIES=	www
GIT_REPO=	https://github.com/LadybirdBrowser/ladybird.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ladybird.dev/
COMMENT=	Independent web browser from scratch from SerenityOS
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++20
GCC_REQD+=		13
USE_TOOLS+=		pkg-config

#CMAKE_CONFIGURE_ARGS+=		-S Ladybird
# build broken with make
CMAKE_GENERATORS_INCOMPATIBLE=	make
# TODO: this needs fixing
ALLOW_NETWORK_ACCESS=	1

# Ladybird dumps core with full RELRO
# http://gnats.netbsd.org/57792
# Note this PR is fixed in -current, should retest.
RELRO_SUPPORTED=	partial

# ld(1) goes crazy and eats 32GB of RAM
CMAKE_CONFIGURE_ARGS+=	-DENABLE_LTO_FOR_RELEASE=OFF

# .buildlink/include/openssl/tls1.h:295:17: error: cast from type 'const char*' to type 'void*' casts away qualifiers [-Werror=cast-qual]
# work/ladybird/Libraries/LibCrypto/OpenSSL.h:35:35: note: in definition of macro 'OPENSSL_TRY'
BUILDLINK_TRANSFORM+=	rm:-Werror

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/cmake-pkgsrc-build/lib

#StandardPaths::system_data_directories
SUBST_CLASSES+=		fontpath
SUBST_FILES.fontpath+=	Libraries/LibCore/StandardPaths.cpp
SUBST_SED.fontpath+=	-e "s,/usr/local/share:/usr/share,${PREFIX}/share,"
SUBST_MESSAGE.fontpath=	Fixing path to fonts.
SUBST_STAGE.fontpath=	pre-build

post-extract:
	${LN} -s ${FILESDIR}/FindWebP.cmake	\
	  ${WRKSRC}/Meta/CMake/FindWebP.cmake

.include "../../devel/cmake/build.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/woff2/buildlink3.mk"
.include "../../graphics/libavif/buildlink3.mk"
.include "../../graphics/libjxl/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../wip/simdutf/buildlink3.mk"
.include "../../wip/skia-git/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
