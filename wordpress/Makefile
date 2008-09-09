# $NetBSD: Makefile,v 1.1.1.1 2008/09/09 20:04:03 shindenmorr Exp $

DISTNAME=	latest
PKGNAME=	wordpress-${VERSION}
VERSION=	2.6.2
CATEGORIES=	www
MASTER_SITES=	http://wordpress.org/
EXTRACT_SUFX=	.zip

MAINTAINER=	shinden@linux.pl
HOMEPAGE=	http://wordpress.org/
COMMENT=	Blogging tool written in php

PKG_DESTDIR_SUPPORT=    user-destdir

WRKSRC=		${WRKDIR}/wordpress
INSTALLATION_DIRS=	${PREFIX}/share/wordpress/ ${PREFIX}/share/doc/wordpress/ ${PREFIX}/share/examples/wordpress/
NO_BUILD=       yes

WORDPRESS_DIR=	share/wordpress/

do-install:
	${CP} -R ${WRKSRC}/* ${DESTDIR}${PREFIX}/${WORDPRESS_DIR}
	${FIND} ${DESTDIR}${PREFIX}/${WORDPRESS_DIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${PREFIX}/${WORDPRESS_DIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	${INSTALL_DATA} ${WRKSRC}/readme.html ${DESTDIR}${PREFIX}/share/doc/wordpress/
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DESTDIR}${PREFIX}/share/doc/wordpress/
	${INSTALL_DATA} ${WRKSRC}/wp-config-sample.php ${DESTDIR}${PREFIX}/share/examples/wordpress/

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
