# $NetBSD$
#

MODNAME=		xdiff
PECL_VERSION=		2.0.1
CATEGORIES+=		misc

MAINTAINER=		pkgsrc-users@pkgsrc.org
HOMEPAGE=		http://php.net/xdiff
COMMENT=		PHP bindings to the functions of LibXDiff
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	70 71

TEST_TARGET=		test
TEST_ENV=		NO_INTERACTION=set

pre-configure:
	${MV} ${WRKSRC}/configure ${WRKSRC}/configure.orig
	${SED} -e "s|SEARCH_PATH=\"/usr/local /usr\"|SEARCH_PATH=\"${BUILDLINK_PREFIX.libxdiff}\"|" \
		${WRKSRC}/configure.orig > ${WRKSRC}/configure

#.include "../../devel/libxdiff/buildlink3.mk"
.include "../../wip/libxdiff/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
