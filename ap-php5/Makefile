# $NetBSD: Makefile,v 1.9 2004/07/16 14:49:04 ppostma Exp $
#

PKGNAME=		ap-php-${PHP5_VERSION}
PKGREVISION=		# empty
COMMENT=		Apache (${PKG_APACHE}) module for PHP5

USE_BUILDLINK3=		YES
APACHE_MODULE=		YES
SHLIBTOOL_OVERRIDE=	libtool

.include "../../wip/php5/Makefile.common"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

do-install:
	if [ -f ${WRKSRC}/libs/libphp5.so ]; then		\
		${INSTALL_DATA} ${WRKSRC}/libs/libphp5.so	\
			${PREFIX}/lib/httpd/mod_php5.so;        \
	fi

.include "../../wip/php5/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
