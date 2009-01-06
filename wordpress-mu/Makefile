# $NetBSD: Makefile,v 1.1.1.1 2009/01/06 21:36:14 shindenmorr Exp $
#

DISTNAME=		latest
PKGNAME=		wordpress-mu-${VERSION}
VERSION=		2.6.5
CATEGORIES=		www
MASTER_SITES=		http://mu.wordpress.org/

MAINTAINER=		shinden@linux.pl
HOMEPAGE=		http://mu.wordpress.org/
COMMENT=		Multi User version of blogging tool

USE_TOOLS+=		pax

NO_BUILD=		yes
DIST_SUBDIR=		wordpress-mu-${VERSION}
PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/wordpress-mu-${VERSION}

INSTALLATION_DIRS=	${PREFIX}/share/wordpress-mu
INSTALLATION_DIRS+=	${PREFIX}/share/doc/wordpress-mu
INSTALLATION_DIRS+=	${PREFIX}/share/examples/wordpress-mu

DEPENDS+=		${PHP_PKG_PREFIX}-mysql>=4.3.3:../../databases/php-mysql

do-install:
	cd ${WRKSRC} && pax -rw -pmp * ${DESTDIR}${PREFIX}/share/wordpress-mu
	${FIND} ${DESTDIR}${PREFIX}/share/wordpress-mu -type d \
		-exec ${CHMOD} ${PKGDIRMODE} "{}" \;
	${FIND} ${DESTDIR}${PREFIX}/share/wordpress-mu -type f \
		-exec ${CHMOD} ${SHAREMODE} "{}" \;
	${INSTALL_DATA} ${WRKSRC}/README.txt \
		${DESTDIR}${PREFIX}/share/doc/wordpress-mu
	${INSTALL_DATA} ${WRKSRC}/license.txt \
		${DESTDIR}${PREFIX}/share/doc/wordpress-mu
	${INSTALL_DATA} ${WRKSRC}/wp-config-sample.php \
		${DESTDIR}${PREFIX}/share/examples/wordpress-mu

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
