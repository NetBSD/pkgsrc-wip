# $NetBSD: Makefile,v 1.7 2012/10/07 16:23:18 asau Exp $
#

DISTNAME=	SugarCE-${VERSION}
PKGNAME=	sugarCRM-${VERSION}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sugarcrm/}
EXTRACT_SUFX=	.zip

MAINTAINER=	derv0@nubisci.net
HOMEPAGE=	http://www.sugarcrm.com/
COMMENT=	SugarCRM is a php based CRM system
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.3.3:../../databases/php-mysql

VERSION=	5.2.0l

USE_LANGUAGES=	# empty
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S|CE|CE-Full|}
AUTO_MKDIRS=	yes

APACHE_USER?=	www
APACHE_GROUP?=	www
BUILD_DEFS+=	APACHE_USER APACHE_GROUP

do-install:
	${CP} -R ${WRKSRC}/* ${DESTDIR}${PREFIX}/share/sugarCRM
	${CHOWN} -R ${APACHE_USER}:${APACHE_GROUP} ${DESTDIR}${PREFIX}/share/sugarCRM

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
