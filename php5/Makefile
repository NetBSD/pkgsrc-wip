# $NetBSD: Makefile,v 1.12 2004/05/10 22:47:00 poppnk Exp $
#

PKGNAME=	php-${PHP5_VERSION}
CATEGORIES=	www

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.php.net/
COMMENT=	PHP Hypertext Preprocessor version 5

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

CONF_FILES=	${PREFIX}/etc/php.ini

BUILD_DEFS=	USE_INET6 PHP5_WITHOUT_NETWORK

post-install:
	${INSTALL_DATA} ${WRKSRC}/php.ini-recommended \
		${PREFIX}/etc/php.ini

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
