# $NetBSD$

DISTNAME=		LIEF-0.14.1
PKGNAME=		${DISTNAME:tl}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=lief-project/}
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://lief-project.github.io/
COMMENT=		Library to Instrument Executable Formats
LICENSE=		apache-2.0

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17
FORCE_CXX_STD=		c++17

CMAKE_CONFIGURE_ARGS+=	-DLIEF_OPT_MBEDTLS_EXTERNAL=1
CMAKE_CONFIGURE_ARGS+=	-DLIEF_ENABLE_JSON=1 \
			-DLIEF_OPT_NLOHMANN_JSON_EXTERNAL=1
CMAKE_CONFIGURE_ARGS+=	-DLIEF_FROZEN_ENABLED=1 \
			-DLIEF_OPT_FROZEN_EXTERNAL=1
CMAKE_CONFIGURE_ARGS+=	-DLIEF_EXTERNAL_EXPECTED=1
CMAKE_CONFIGURE_ARGS+=	-DLIEF_OPT_UTFCPP_EXTERNAL=1

PKGCONFIG_OVERRIDE+=	cmake/LIEF.pc.in

# make sure the vendored versions don't get found
post-extract:
	rm ${WRKSRC}/third-party/mbedtls*.zip
	rm ${WRKSRC}/third-party/json*.zip
	rm ${WRKSRC}/third-party/expected*.zip
	rm ${WRKSRC}/third-party/frozen*.zip
	rm ${WRKSRC}/third-party/utfcpp*.zip
	rm ${WRKSRC}/third-party/spdlog*.zip

# needs Git at build time???
# "tcb-span"? LIEF_EXTERNAL_SPAN, LIEF_EXTERNAL_SPAN_DIR
# py-sqlelf will want the python bindings installed (BUILD_DIRS+=api/python)

.include "../../devel/cmake/build.mk"
.include "../../devel/frozen/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../devel/tl-expected/buildlink3.mk"
.include "../../security/mbedtls3/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../textproc/utf8-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
