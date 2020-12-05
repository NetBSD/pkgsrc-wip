# $NetBSD$
#

MODNAME=		msgpack
PECL_VERSION=		2.1.2
CATEGORIES+=		devel

MAINTAINER=		pkgsrc-users@pkgsrc.org
HOMEPAGE=		https://pecl.php.net/package/msgpack
COMMENT=		PHP extension for interfacing with MessagePack
LICENSE=		modified-bsd

PHP_VERSIONS_INCOMPATIBLE=	56

TEST_TARGET=		test
TEST_ENV=		NO_INTERACTION=set

.include "../../devel/msgpack/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
