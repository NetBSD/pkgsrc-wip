# $NetBSD: Makefile,v 1.1.1.1 2003/04/14 09:41:49 jmmv Exp $
#

DISTNAME=	adodb243
PKGNAME=	adodb-2.43
WRKSRC=		${WRKDIR}/adodb
CATEGORIES=	databases www
MASTER_SITES=	http://phplens.com/lens/dl/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE= 	http://php.weblogs.com/ADODB	
COMMENT=	Database class library for PHP4

DEPENDS+=       php>=4.0.1pl2:../../www/php4

NO_BUILD=	YES

DOC_FILES=	license.txt readme.htm readme.txt tips_portable_sql.htm \
		tute.htm

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb/drivers
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb/tests
	${INSTALL_DATA_DIR} ${PREFIX}/share/adodb/cute_icons_for_site
	${INSTALL_SCRIPT} ${WRKSRC}/*.php ${PREFIX}/share/adodb
	${INSTALL_SCRIPT} ${WRKSRC}/drivers/*.php ${PREFIX}/share/adodb/drivers
	${INSTALL_SCRIPT} ${WRKSRC}/tests/*.php ${PREFIX}/share/adodb/tests
	${INSTALL_DATA} ${WRKSRC}/cute_icons_for_site/*.png ${PREFIX}/share/adodb/cute_icons_for_site
	${INSTALL_DATA} ${WRKSRC}/cute_icons_for_site/*.gif ${PREFIX}/share/adodb/cute_icons_for_site
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/adodb
	for FILE in ${DOC_FILES}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$FILE ${PREFIX}/share/doc/adodb; \
	done

.include "../../mk/bsd.pkg.mk"
