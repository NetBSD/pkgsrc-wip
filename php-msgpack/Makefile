# $NetBSD$
#

MODNAME=		msgpack
PECL_VERSION=		2.1.0
CATEGORIES+=		devel

MAINTAINER=		pkgsrc-users@pkgsrc.org
HOMEPAGE=		https://pecl.php.net/package/msgpack
COMMENT=		PHP extension for interfacing with MessagePack
LICENSE=		modified-bsd

PHP_VERSIONS_ACCEPTED=	70 71
# 5.x versions use 0.5.7 version of the php msgpack

TEST_TARGET=		test
TEST_ENV=		NO_INTERACTION=set

.include "../../devel/msgpack/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
