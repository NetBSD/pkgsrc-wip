# $NetBSD: Makefile,v 1.1.1.1 2004/12/23 00:03:24 rpereyra Exp $
#

DISTNAME=		uebimiau-2.7.2
CATEGORIES=		wip
MASTER_SITES=		http://www.contenidosonline.com.ar/pkgsrc/

MAINTAINER=		rpereyra@users.sourceforge.net
HOMEPAGE=		www.uebimiau.org
COMMENT=		Email client

DEPENDS+=      		ap{,2}-php>=4.3.0:../../www/ap-php4
WRKSRC=			${WRKDIR}/uebimiau-2.7.2
USE_BUILDLINK3=		no
NO_BUILD=		yes

do-install:
			${MKDIR} ${PREFIX}/share/httpd/htdocs/uebimiau \
			&& ${CP} -R ${WRKSRC}/* ${PREFIX}/share/httpd/htdocs/uebimiau

.include "../../mk/bsd.pkg.mk"
