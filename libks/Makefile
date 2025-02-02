# $NetBSD$

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	libks-2.0.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=signalwire/}

MAINTAINER=	rob@buglawton.com
HOMEPAGE=	https://github.com/signalwire/libks/
COMMENT=	Foundational support for signalwire C products
LICENSE=	mit AND public-domain AND modified-bsd

USE_TOOLS+=	cmake pkg-config
USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/${DISTNAME}
PKGCONFIG_OVERRIDE+=	libks.pc.in
MAKE_ENV+=	GCC=yes

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX:PATH=/usr/pkg


.include "../../devel/libuuid/buildlink3.mk"
.include "../../misc/rhash/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/pthread.builtin.mk"
.include "../../mk/bsd.pkg.mk"
