# $NetBSD: Makefile,v 1.5 2004/07/25 16:22:59 marc Exp $
#

DISTNAME=	tutos-php-1.1.20030404
WRKSRC=		${WRKDIR}/tutos
CATEGORIES=	devel
MASTER_SITES=	http://www.tutos.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.tutos.org/homepage/about.html
COMMENT=	Time and team management software

USE_BUILDLINK3=	yes
USE_PKGINSTALL=	yes

TUTOS_USER?=	tutos
TUTOS_GROUP?=	${TUTOS_USER}

PKG_GROUPS+=	${TUTOS_GROUP}
PKG_USERS+=     ${TUTOS_USER}:${TUTOS_GROUP}::Tutos\\ Runtime\\ User

NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' -e 's|@X11BASE@|${X11BASE}|g' \
		${FILESDIR}/config.pinc > ${WRKSRC}/config.pinc
	${INSTALL_DATA_DIR} ${PREFIX}/share/httpd/htdocs/tutos
	cd ${WRKSRC}; ${PAX} -rwpe . ${PREFIX}/share/httpd/htdocs/tutos

.include "../../www/php4/buildlink3.mk"
.include "../../www/apache2/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
