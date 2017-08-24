# $NetBSD$

DISTNAME=	arangodb-3.2.2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=arangodb/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/arangodb/arangodb/
COMMENT=	Native multi-model database with flexible data models
LICENSE=	apache-2.0

USE_CMAKE=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	3rdParty/V8/v5.7.0.0/third_party/icu/source/config/icu.pc.in
PKGCONFIG_OVERRIDE+=	3rdParty/boost/1.62.0/libs/hana/cmake/hana.pc.in
PKGCONFIG_OVERRIDE+=	3rdParty/curl/curl-7.50.3/libcurl.pc.in
PKGCONFIG_OVERRIDE+=	3rdParty/jemalloc/v5.0.1/jemalloc.pc.in
PKGCONFIG_OVERRIDE+=	3rdParty/zlib/zlib-1.2.11/contrib/minizip/minizip.pc.in
PKGCONFIG_OVERRIDE+=	3rdParty/zlib/zlib-1.2.11/zlib.pc.in

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
