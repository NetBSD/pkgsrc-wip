# $NetBSD: Makefile,v 1.2 2004/02/12 22:22:53 xtraeme Exp $
#

PKGNAME=		ap-php-${PHP5_VERSION}
PKGREVISION=		# empty
COMMENT=		Apache (${PKG_APACHE}) module for PHP5

DEPENDS+=		php>=${PHP5_VERSION}:../../www/php5

USE_BUILDLINK2=		YES
APACHE_MODULE=		YES
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../wip/php5/Makefile.common"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

do-install:
	if [ -f ${WRKSRC}/libs/libphp5.so ]; then		\
		${INSTALL_DATA} ${WRKSRC}/libs/libphp5.so	\
			${PREFIX}/lib/httpd/mod_php5.so;	\
	elif [ -f ${WRKSRC}/libs/libphp5.so ]; then		\
		${INSTALL_DATA} ${WRKSRC}/libs/libphp5.so	\
			${PREFIX}/lib/httpd/mod_php5.so;	\
	fi


.include "../../mk/apache.mk"
