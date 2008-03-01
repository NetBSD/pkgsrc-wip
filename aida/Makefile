# $NetBSD: Makefile,v 1.2 2008/03/01 12:07:06 asau Exp $
#

DISTNAME=	aida-3.2.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.slac.stanford.edu/software/freehep/AIDA/v3.2.1/

MAINTAINER=	hugor@users.sourceforge.net
HOMEPAGE=	http://aida.freehep.org/index.thtml
COMMENT=	Abstract interfaces for data analysis

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

do-build:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/AIDA
	${INSTALL_DATA} ${WRKSRC}/src/cpp/AIDA/* ${DESTDIR}${PREFIX}/include/AIDA
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/api
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/api/hep
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/api/hep/aida
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/UsersGuide
	${INSTALL_DATA} ${WRKSRC}/doc/api/*.html ${WRKSRC}/doc/api/package-list \
		${WRKSRC}/doc/api/status.* ${WRKSRC}/doc/api/stylesheet.css \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/api
	${INSTALL_DATA} ${WRKSRC}/doc/api/hep/aida/* \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/api/hep/aida
	${INSTALL_DATA} ${WRKSRC}/doc/UsersGuide/*.shtml \
		${WRKSRC}/doc/UsersGuide/aida.css \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/UsersGuide

.include "../../mk/bsd.pkg.mk"
