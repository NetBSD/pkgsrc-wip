# $NetBSD: Makefile,v 1.6 2006/10/29 08:32:57 shattered Exp $
#

DISTNAME=		uebimiau-2.7.2
CATEGORIES=		www mail
MASTER_SITES=		http://www.contenidosonline.com.ar/pkgsrc/

MAINTAINER=		rpereyra@users.sourceforge.net
HOMEPAGE=		http://www.uebimiau.org/
COMMENT=		Web based email client

DEPENDS+=	ap{,2}-php>=4.3.0:../../www/ap-php

NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/httpd/htdocs/uebimiau
	${CP} -R ${WRKSRC}/* ${PREFIX}/share/httpd/htdocs/uebimiau

.include "../../mk/bsd.pkg.mk"
