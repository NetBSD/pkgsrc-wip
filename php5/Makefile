# $NetBSD: Makefile,v 1.5 2004/01/14 20:40:32 poppnk Exp $
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
USE_GMAKE=	YES

post-install:
	${INSTALL_DATA} ${WRKSRC}/php.ini-recommended \
		${PREFIX}/lib/php.ini

.include "Makefile.common"
