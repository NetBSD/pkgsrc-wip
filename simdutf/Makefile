# $NetBSD$

DISTNAME=	simdutf-5.6.0
CATEGORIES=	converters textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=simdutf/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/simdutf/simdutf/
COMMENT=	Library for unicode validation, transcoding and processing
LICENSE=	apache-2.0 OR mit

USE_LANGUAGES=		c++
USE_CXX_FEATURES+=	c++11

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DSIMDUTF_BENCHMARKS=OFF
CMAKE_CONFIGURE_ARGS+=	-DSIMDUTF_TOOLS=OFF
CMAKE_CONFIGURE_ARGS+=	-DSIMDUTF_TESTS=OFF

PKGCONFIG_OVERRIDE+=	simdutf.pc.in

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

# this needed in order to comply with
# the mit and apache licenses and redistribution
post-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE-MIT ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/LICENSE-APACHE ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
