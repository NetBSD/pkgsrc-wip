# $NetBSD: Makefile,v 1.9 2004/05/10 16:59:33 poppnk Exp $
#

PKGNAME=	php-${PHP5_VERSION}
CATEGORIES+=	lang

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.php.net/
COMMENT=	PHP Hypertext Preprocessor version 5

CONFLICTS+=	php-[34]*
USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

CONF_FILES=	${PREFIX}/etc/php.ini

BUILD_DEFS=	USE_INET6

post-install:
	${INSTALL_DATA} ${WRKSRC}/php.ini-recommended \
		${PREFIX}/etc/php.ini

.include "Makefile.common"
