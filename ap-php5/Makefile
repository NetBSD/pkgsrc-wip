# $NetBSD: Makefile,v 1.6 2004/05/11 14:43:18 poppnk Exp $
#

PKGNAME=		ap-php-${PHP5_VERSION}
CATEGORIES=		www
PKGREVISION=		# empty
COMMENT=		Apache (${PKG_APACHE}) module for PHP5

DEPENDS+=		php>=${PHP5_VERSION}:../../wip/php5
DEPENDS+=		apache>=1.3.9:../../www/apache

USE_BUILDLINK3=		YES
APACHE_MODULE=		YES
SHLIBTOOL_OVERRIDE=	libtool

.include "../../wip/php5/Makefile.module"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

pre-install:
	if [ -f ${WRKSRC}/libs/libphp5.so ]; then		\
		${INSTALL_DATA} ${WRKSRC}/libs/libphp5.so	\
			${PREFIX}/lib/httpd/mod_php5.so;        \
	fi

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
