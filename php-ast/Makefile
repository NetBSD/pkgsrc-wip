# $NetBSD$

MODNAME=		ast
PECL_VERSION=		1.0.6
CATEGORIES=		devel

MAINTAINER=		tpaul@NetBSD.org
HOMEPAGE=		https://pecl.php.net/package/ast
LICENSE=		modified-bsd
COMMENT=		Extension exposing PHP 7 abstract syntax tree

CONFIGURE_ARGS+=	--with-ast=${PREFIX}

PHP_VERSIONS_INCOMPATIBLE=	56

TEST_TARGET=		test
TEST_ENV=		NO_INTERACTION=set

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
