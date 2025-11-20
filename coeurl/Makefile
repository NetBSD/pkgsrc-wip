# $NetBSD$

DISTNAME=	coeurl-v0.3.1
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	www
MASTER_SITES=	https://nheko.im/nheko-reborn/coeurl/-/archive/v0.3.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nheko.im/nheko-reborn/coeurl/
COMMENT=	Simple library to do http requests asynchronously via CURL in C++
LICENSE=	mit

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config cmake

USE_BUILTIN.libevent=	no
.include "../../devel/libevent/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
