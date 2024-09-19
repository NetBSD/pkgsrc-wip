# $NetBSD$
#

MODNAME=		zmq
# all versions 1.0.7 to 1.1.3 are listed as "beta" state
PECL_VERSION=		1.1.3
CATEGORIES+=		net

MAINTAINER=		pkgsrc-users@pkgsrc.org
HOMEPAGE=		http://php.net/manual/en/intro.zmq.php
COMMENT=		PHP bindings to the functions of ZeroMQ
LICENSE=		modified-bsd

PHP_VERSIONS_ACCEPTED=	56 70 71 72

TEST_TARGET=		test
TEST_ENV=		NO_INTERACTION=set

.include "../../net/zeromq/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
