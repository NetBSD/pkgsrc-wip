# $NetBSD$

DISTNAME=	tde2e-1.8.51
CATEGORIES=	chat security
MASTER_SITES=	${MASTER_SITE_GITHUB:=tdlib/}
GITHUB_PROJECT=	td
GITHUB_TAG=	bb474a201baa798784d696d2d9d762a9d2807f96
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tdlib/td
COMMENT=	Telegram End-to-End encryption library (tdlib E2E mode)
LICENSE=	boost-license

USE_LANGUAGES=	c c++
TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF
CMAKE_CONFIGURE_ARGS+=	-DTD_ENABLE_JNI=OFF
CMAKE_CONFIGURE_ARGS+=	-DTD_ENABLE_DOTNET=OFF
CMAKE_CONFIGURE_ARGS+=	-DTD_E2E_ONLY=ON
CMAKE_CONFIGURE_ARGS+=	-DTDE2E_ENABLE_INSTALL=ON
CMAKE_CONFIGURE_ARGS+=	-DTDE2E_INSTALL_INCLUDES=ON

BUILDLINK_DEPMETHOD.abseil=	build
.include "../../devel/cmake/build.mk"
.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
