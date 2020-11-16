# $NetBSD$

PKGNAME=	unit-php${PHP_VERSION:R:S|.||g}-1.20.0
DISTNAME=	unit-1.20.0
COMMENT=	PHP module for NGINX Unit

MODNAME=	php${PHP_VERSION}

MAINTAINER=	osa@FreeBSD.org

PHP_VERSIONS_ACCEPTED?=	56 72 73 74

USE_LANGUAGES+=	c

.include "../../lang/php/phpversion.mk"

#.if empty(PKG_BUILD_OPTIONS.${PHP_PKG_PREFIX}:Mphp-embed)
#BROKEN=		"Requires the php-embed option enabled in PHP."
#.endif

post-configure:
	cd ${WRKSRC} && \
	./configure php --lib-path=${PREFIX}/lib \
		--module=${MODNAME}

.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../www/unit/ext.mk"
.include "../../www/unit/Makefile.common"
