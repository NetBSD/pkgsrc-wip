# $NetBSD$

DISTNAME=	realm-core-6.0.8
CATEGORIES=	database
MASTER_SITES=	${MASTER_SITE_GITHUB:=realm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://realm.io/
COMMENT=	Core database component for the Realm Mobile Database SDKs 
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARGS+=	-DPEGTL_SYSTEM=1
CMAKE_ARGS+=	-DSSL_SYSTEM=1

CONFIGURE_DIRS=	${WRKDIR}/build                                                                
CMAKE_ARG_PATH=	${WRKSRC}

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../security/openssl/buildlink3.mk"
.include "../../wip/pegtl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
