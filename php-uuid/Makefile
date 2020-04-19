# $NetBSD$

MODNAME=		uuid
PECL_VERSION=		1.1.0
CATEGORIES=		devel

MAINTAINER=		tpaul@NetBSD.org
HOMEPAGE=		https://pecl.php.net/package/uuid
LICENSE=		gnu-lgpl-v2.1
COMMENT=		Wrapper around libuuid from the ext2utils project

CONFIGURE_ARGS+=	--with-uuid=${PREFIX}

PHP_VERSIONS_INCOMPATIBLE=	56

TEST_TARGET=		test
TEST_ENV=		NO_INTERACTION=set

.include "../../devel/libuuid/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
