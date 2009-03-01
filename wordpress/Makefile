# $NetBSD: Makefile,v 1.6 2009/03/01 13:05:00 shindenmorr Exp $

DISTNAME=		wordpress-${VERSION}
VERSION=		2.7.1
CATEGORIES=		www
MASTER_SITES=		http://wordpress.org/
EXTRACT_SUFX=		.zip

MAINTAINER=		shinden@linux.pl
HOMEPAGE=		http://wordpress.org/
COMMENT=		Blogging tool written in php

USE_TOOLS+=		pax

NO_BUILD=		yes
DIST_SUBDIR=		wordpress-${VERSION}
PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/wordpress

INSTALLATION_DIRS=	${PREFIX}/share/wordpress
INSTALLATION_DIRS+=	${PREFIX}/share/doc/wordpress
INSTALLATION_DIRS+=	${PREFIX}/share/examples/wordpress

DEPENDS+=		${PHP_PKG_PREFIX}-mysql>=4.3.3:../../databases/php-mysql

do-install:
	cd ${WRKSRC} && pax -rw -pmp * ${DESTDIR}${PREFIX}/share/wordpress
	${FIND} ${DESTDIR}${PREFIX}/share/wordpress -type d \
		-exec ${CHMOD} ${PKGDIRMODE} "{}" \;
	${FIND} ${DESTDIR}${PREFIX}/share/wordpress -type f \
		-exec ${CHMOD} ${SHAREMODE} "{}" \;
	${INSTALL_DATA} ${WRKSRC}/readme.html \
		${DESTDIR}${PREFIX}/share/doc/wordpress
	${INSTALL_DATA} ${WRKSRC}/license.txt \
		${DESTDIR}${PREFIX}/share/doc/wordpress
	${INSTALL_DATA} ${WRKSRC}/wp-config-sample.php \
		${DESTDIR}${PREFIX}/share/examples/wordpress

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
