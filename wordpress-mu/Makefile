# $NetBSD: Makefile,v 1.8 2010/04/26 11:37:36 shindenmorr Exp $
#

DISTNAME=		wordpress-mu-${VERSION}
VERSION=		2.9.2
CATEGORIES=		www
MASTER_SITES=		http://mu.wordpress.org/

MAINTAINER=		morr@NetBSD.org
HOMEPAGE=		http://mu.wordpress.org/
COMMENT=		Multi User version of blogging tool

USE_TOOLS+=		pax

NO_BUILD=		yes
DIST_SUBDIR=		wordpress-mu-${VERSION}
PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/wordpress-mu

INSTALLATION_DIRS=	share/wordpress-mu
INSTALLATION_DIRS+=	share/doc/wordpress-mu
INSTALLATION_DIRS+=	share/examples/wordpress-mu

DEPENDS+=		${PHP_PKG_PREFIX}-mysql>=4.3.3:../../databases/php-mysql

#SVN_REPOSITORIES=	wordpress-mu
#SVN_ROOT.wordpress-mu=	http://svn.automattic.com/wordpress-mu/tags/2.7
#SVN_TAG=		1696

#NO_CHECKSUM=    yes

do-install:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r
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
	rm ${DESTDIR}${PREFIX}/share/wordpress-mu/README.txt

.include "options.mk"
#.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
