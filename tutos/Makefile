# $NetBSD: Makefile,v 1.16 2012/10/07 17:13:28 asau Exp $
#

DISTNAME=	TUTOS-php-1.2.20040906
PKGNAME=	${DISTNAME:S/TUTOS/tutos/}
WRKSRC=		${WRKDIR}/tutos
CATEGORIES=	devel
MASTER_SITES=	http://www.tutos.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tutos.org/homepage/about.html
COMMENT=	Time and team management software

TUTOS_USER?=	tutos
TUTOS_GROUP?=	${TUTOS_USER}

PKG_GROUPS+=	${TUTOS_GROUP}
PKG_USERS+=	${TUTOS_USER}:${TUTOS_GROUP}::Tutos\ Runtime\ User

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	pax

do-install:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' -e 's|@X11BASE@|${X11BASE}|g' \
		${FILESDIR}/config.pinc > ${WRKSRC}/config.pinc
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/httpd/htdocs/tutos
	cd ${WRKSRC}; pax -rwpe . ${DESTDIR}${PREFIX}/share/httpd/htdocs/tutos

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
