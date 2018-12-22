# $NetBSD$

DISTNAME=	neko-2.2.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=HaxeFoundation/}
GITHUB_TAG=	v${PKGVERSION_NOREV:S/./-/g}

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	The Neko virtual machine
LICENSE=	mit

EXTRACT_USING=	gtar
USE_LANGUAGES=	c
USE_CMAKE=	yes

# XXX Minimal configuration for now. Should use options.mk instead.
CMAKE_ARGS+=	-DWITH_REGEXP:BOOL=OFF
CMAKE_ARGS+=	-DWITH_UI:BOOL=OFF
CMAKE_ARGS+=	-DWITH_SSL:BOOL=OFF
CMAKE_ARGS+=	-DWITH_MYSQL:BOOL=OFF
CMAKE_ARGS+=	-DWITH_SQLITE:BOOL=OFF
CMAKE_ARGS+=	-DWITH_APACHE:BOOL=OFF
CMAKE_ARGS+=	-DWITH_NEKOML:BOOL=OFF

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
