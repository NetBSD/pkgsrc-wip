# $NetBSD$
#
MODNAME=		snuffleupagus
PECL_VERSION=		0.7.0
CATEGORIES+=		security

# See TODO
MASTER_SITES=		https://travispaul.me/distfiles/

MAINTAINER=		tpaul@NetBSD.org
HOMEPAGE=		https://snuffleupagus.readthedocs.io/
COMMENT=		Security module for PHP7
LICENSE=		gnu-lgpl-v3

WRKSRC=			${WRKDIR}/${MODNAME}-${PECL_VERSION}
MODULESDIR=		${WRKSRC}/src/modules
PHPSETUPSUBDIR=		src
CONFIGURE_DIRS=		src
CONFIGURE_ARGS+=	--with-snuffleupagus=${PREFIX}

PHP_VERSIONS_INCOMPATIBLE=	56
PLIST_SRC+=			${.CURDIR}/PLIST.extras

TEST_TARGET=		test
TEST_ENV=		NO_INTERACTION=set

.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
