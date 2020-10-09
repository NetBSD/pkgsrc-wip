# $NetBSD$

MODNAME=	psr
PECL_VERSION=	1.0.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/psr
COMMENT=	This extension provides the accepted PSR interfaces, so they can be used in an extension
LICENSE=	2-clause-bsd

PHP_VERSIONS_ACCEPTED=	72 73 74

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

INSTALLATION_DIRS+=	include/php/ext/psr
PLIST_SRC+=		PLIST

post-install:
	${INSTALL_DATA} ${WRKSRC}/php_psr.h \
		${DESTDIR}${PREFIX}/include/php/ext/psr

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
