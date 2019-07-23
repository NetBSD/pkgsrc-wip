# $NetBSD$

GITHUB_PROJECT=	unittest-cpp
VERS=		2.0.0
DISTNAME=	v${VERS}
PKGNAME=	${GITHUB_PROJECT}-${VERS}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=unittest-cpp/}
DIST_SUBDIR=	${GITHUB_PROJECT}

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
