# $NetBSD$

DISTNAME=	simde-0.7.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=simd-everywhere/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_SUBMODULES=	nemequ munit da8f73412998e4f1adf1100dc187533a51af77fd test/munit

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/simd-everywhere/simde
COMMENT=	Header-only library for SIMD intrinsics
LICENSE=	mit

USE_LANGUAGES=	c c++
NO_BUILD=	yes
MESON_ARGS+=	-Dtests=false
BUILD_WRKSRC=	${WRKSRC}/output

# Passes on Darwin, Linux (Alma8)
# Fails on NetBSD 9
do-test:
	@${RM} -r ${BUILD_WRKSRC}/*
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} meson -Dtests=true output
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ninja -v test

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
