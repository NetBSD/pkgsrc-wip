# $NetBSD: Makefile,v 1.8 2004/01/25 02:33:12 grantbeattie Exp $
#

PKGNAME=	php-${PHP5_VERSION}
CATEGORIES+=	lang

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.php.net/
COMMENT=	PHP Hypertext Preprocessor version 5

CONFLICTS+=	php-[34]*
USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

CONF_FILES=	${PREFIX}/lib/php.ini

BUILD_DEFS=	USE_INET6 PHP5_WITH_FTP

post-install:
	${INSTALL_DATA} ${WRKSRC}/php.ini-recommended \
		${PREFIX}/lib/php.ini

.include "Makefile.common"
