# $NetBSD: Makefile,v 1.7 2008/05/23 10:32:36 tnn2 Exp $
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
	${INSTALL_DATA_DIR} ${PREFIX}/share/httpd/htdocs/uebimiau
	${CP} -R ${WRKSRC}/* ${PREFIX}/share/httpd/htdocs/uebimiau

.include "../../mk/apachever.mk"
.include "../../lang/php/phpversion.mk"

.include "../../mk/bsd.pkg.mk"
