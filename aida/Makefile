# $NetBSD: Makefile,v 1.1.1.1 2006/09/19 03:20:57 hugor Exp $
#

DISTNAME=	aida-3.2.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.slac.stanford.edu/software/freehep/AIDA/v3.2.1/

MAINTAINER=	hugor@users.sourceforge.net
HOMEPAGE=	http://aida.freehep.org/index.thtml
COMMENT=	Abstract interfaces for data analysis

WRKSRC=		${WRKDIR}


do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/AIDA
	${INSTALL_DATA} ${WRKSRC}/src/cpp/AIDA/* ${PREFIX}/include/AIDA
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}/api
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}/api/hep
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}/api/hep/aida
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}/UsersGuide
	${INSTALL_DATA} ${WRKSRC}/doc/api/*.html ${WRKSRC}/doc/api/package-list \
		${WRKSRC}/doc/api/status.* ${WRKSRC}/doc/api/stylesheet.css \
		${PREFIX}/share/doc/${PKGBASE}/api
	${INSTALL_DATA} ${WRKSRC}/doc/api/hep/aida/* \
		${PREFIX}/share/doc/${PKGBASE}/api/hep/aida
	${INSTALL_DATA} ${WRKSRC}/doc/UsersGuide/*.shtml \
		${WRKSRC}/doc/UsersGuide/aida.css \
		${PREFIX}/share/doc/${PKGBASE}/UsersGuide

.include "../../mk/bsd.pkg.mk"
