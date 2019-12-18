# $NetBSD$

DISTNAME=	sagittarius-0.9.6
CATEGORIES=	lang
MASTER_SITES=	https://bitbucket.org/ktakashi/sagittarius-scheme/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/ktakashi/sagittarius-scheme/wiki/Home
COMMENT=	R6RS/R7RS Scheme system
LICENSE=	2-clause-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/build

PKGCONFIG_OVERRIDE+=	cmake/sagittarius.pc.in

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
