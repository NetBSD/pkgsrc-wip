# $NetBSD: Makefile,v 1.9 2012/10/07 17:21:20 asau Exp $
#

DISTNAME=		uebimiau-2.7.2
CATEGORIES=		www mail
MASTER_SITES=		http://www.contenidosonline.com.ar/pkgsrc/

MAINTAINER=		rpereyra@users.sourceforge.net
HOMEPAGE=		http://www.uebimiau.org/
COMMENT=		Web based email client

DEPENDS+=		${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.3.0:../../www/ap-php

NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/httpd/htdocs/uebimiau
	${CP} -R ${WRKSRC}/* ${DESTDIR}${PREFIX}/share/httpd/htdocs/uebimiau

.include "../../mk/apache.mk"
.include "../../lang/php/phpversion.mk"

.include "../../mk/bsd.pkg.mk"
