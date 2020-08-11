# $NetBSD$

PKGNAME=	unit-php${PHP_VERSION:R:S|.||g}-1.18.0
DISTNAME=	unit-1.18.0
COMMENT=	PHP module for NGINX Unit

MAINTAINER=	osa@FreeBSD.org

DISTINFO_FILE=	../../www/unit/distinfo
PATCHDIR=	../../www/unit/patches

PHP_VERSIONS_ACCEPTED?=	56 72 73 74

MAKE_ENV+=	WITHOUT_RPATH_FIX=1

USE_LANGUAGES+=	c

.include "../../lang/php/phpversion.mk"

# FIX ME
#.if empty(PKG_BUILD_OPTIONS.${PHP_PKG_PREFIX}:Mphp-embed)
#BROKEN=		"Requires the php-embed option enabled in PHP."
#.endif

post-configure:
	cd ${WRKSRC} && \
	./configure php --lib-path=${PREFIX}/lib
		--module=php${PHP_VERSION}

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/libexec/unit/modules/
	${INSTALL_LIB} ${WRKSRC}/build/php${PHP_VERSION}.unit.so \
		${DESTDIR}${PREFIX}/libexec/unit/modules/

.include "${PHPPKGSRCDIR}/buildlink3.mk"
#.include "../../lang/php/ext.mk"
.include "../../www/unit/Makefile.common"
