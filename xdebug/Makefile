# $NetBSD: Makefile,v 1.3 2014/02/11 21:04:11 noud4 Exp $
#

DISTNAME=		xdebug-2.2.3
CATEGORIES=		devel
MASTER_SITES=		http://xdebug.org/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		noud4@users.sourceforge.net
HOMEPAGE=		https://xdebug.org/
COMMENT=		PHP extension for debugging
LICENSE=		php	# XXX based on php

DIST_SUBDIR=		PHP

MODNAME=		xdebug
USE_TOOLS+=		automake autoconf
HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-xdebug
PHPIZE?=		${BUILDLINK_PREFIX.php}/bin/phpize
PLIST_SRC+=		${.CURDIR}/../../lang/php/PLIST.module
PLIST_SUBST+=		MODNAME=${MODNAME}
MESSAGE_SUBST+=		PHP_EXTENSION_DIR=${PHP_EXTENSION_DIR}
INSTALLATION_DIRS+=	${PHP_EXTENSION_DIR}

pre-configure:
	cd ${WRKSRC} && ${PHPIZE}

pre-install:
	${INSTALL_LIB} ${WRKSRC}/modules/xdebug.so ${DESTDIR}${PREFIX}/${PHP_EXTENSION_DIR}

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/Makefile.common"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
