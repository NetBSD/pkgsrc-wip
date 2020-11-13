# $NetBSD$

PKGNAME=	unit-php${PHP_VERSION:R:S|.||g}-1.20.0
DISTNAME=	unit-1.20.0
COMMENT=	PHP module for NGINX Unit

UNIT_MODNAME=	php${PHP_VERSION}

MAINTAINER=	osa@FreeBSD.org

PHP_VERSIONS_ACCEPTED?=	56 72 73 74

USE_LANGUAGES+=	c

PLIST_SUBST+=	UNIT_MODNAME=${UNIT_MODNAME}

.include "../../lang/php/phpversion.mk"

#.if empty(PKG_BUILD_OPTIONS.${PHP_PKG_PREFIX}:Mphp-embed)
#BROKEN=		"Requires the php-embed option enabled in PHP."
#.endif

post-configure:
	cd ${WRKSRC} && \
	./configure php --lib-path=${PREFIX}/lib \
		--module=${UNIT_MODNAME}

do-build:
	cd ${WRKSRC} && ${MAKE} ${UNIT_MODNAME}

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/libexec/unit/modules/
	${INSTALL_LIB} ${WRKSRC}/build/${UNIT_MODNAME}.unit.so \
		${DESTDIR}${PREFIX}/libexec/unit/modules/

.include "${PHPPKGSRCDIR}/buildlink3.mk"
#.include "../../lang/php/ext.mk"
.include "../../www/unit/Makefile.common"
