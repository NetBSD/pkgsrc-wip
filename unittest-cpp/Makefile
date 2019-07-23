# $NetBSD$

DISTNAME=       unittest-cpp-2.0.0
CATEGORIES=     devel
MASTER_SITES=   ${MASTER_SITE_GITHUB:=unittest-cpp/}
GITHUB_TAG=     v${PKGVERSION_NOREV}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/unittest-cpp/unittest-cpp/
COMMENT=	Lightweight unit testing framework for C++
LICENSE=	mit

WRKSRC=		${WRKDIR}/unittest-cpp-2.0.0
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	UnitTest++.pc.in

.include "../../mk/bsd.pkg.mk"
