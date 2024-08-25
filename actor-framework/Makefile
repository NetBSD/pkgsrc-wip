# $NetBSD$

DISTNAME=	actor-framework-0.18.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=actor-framework/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.actor-framework.org/
COMMENT=	Open Source Implementation of the Actor Model in C++
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

#CMAKE_CONFIGURE_ARGS+=	-DCAF_ENABLE_TESTING:BOOL=OFF

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
