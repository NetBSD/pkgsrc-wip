# $NetBSD$

GITHUB_TAG=	v3.0.0
DISTNAME=	nuspell-3.0.0
CATEGORIES=	textproc wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=nuspell/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://nuspell.github.io/
COMMENT=	Free and Open Source C++ spell checking library
LICENSE=	gnu-lgpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++17

PKGCONFIG_OVERRIDE+=	nuspell.pc.in

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
