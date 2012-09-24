# $NetBSD: Makefile,v 1.4 2012/09/24 16:56:32 asau Exp $
#

DISTNAME=	aida-3.2.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.slac.stanford.edu/software/freehep/AIDA/v3.2.1/

MAINTAINER=	hugor@users.sourceforge.net
HOMEPAGE=	http://aida.freehep.org/index.thtml
COMMENT=	Abstract interfaces for data analysis
LICENSE=	gnu-lgpl-v3

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS+=	include/AIDA share/doc/${PKGBASE}/api/hep/aida
INSTALLATION_DIRS+=	share/doc/${PKGBASE}/UsersGuide

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/cpp/AIDA/* ${DESTDIR}${PREFIX}/include/AIDA
	${INSTALL_DATA} ${WRKSRC}/doc/api/*.html ${WRKSRC}/doc/api/package-list \
		${WRKSRC}/doc/api/status.* ${WRKSRC}/doc/api/stylesheet.css \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/api
	${INSTALL_DATA} ${WRKSRC}/doc/api/hep/aida/* \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/api/hep/aida
	${INSTALL_DATA} ${WRKSRC}/doc/UsersGuide/*.shtml \
		${WRKSRC}/doc/UsersGuide/aida.css \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/UsersGuide

.include "../../mk/bsd.pkg.mk"
