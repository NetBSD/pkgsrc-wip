# $NetBSD: Makefile,v 1.15 2004/07/16 16:03:57 ppostma Exp $
#

PKGNAME=		php-${PHP5_VERSION}
CATEGORIES=		lang

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.php.net/
COMMENT=		PHP Hypertext Preprocessor version 5

USE_PKGINSTALL=		YES
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
LIBTOOL_OVERRIDE=	# empty

.include "Makefile.common"

EGDIR=			${PREFIX}/
CONF_FILES=		${EGDIR}/php.ini-recommended ${PKG_SYSCONFDIR}/php.ini

OWN_DIRS=		${PREFIX}/${PHP_EXTENSION_DIR}

.include "../../mk/bsd.pkg.mk"
