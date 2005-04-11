# $NetBSD: Makefile,v 1.2 2005/04/11 21:16:17 tvierling Exp $
#

DISTNAME=		xgobi
PKGNAME=		xgobi-20030626
WRKSRC=			${WRKDIR}/${DISTNAME}
CATEGORIES=		graphics
MASTER_SITES=		http://www.research.att.com/areas/stat/xgobi/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.research.att.com/areas/stat/xgobi/
COMMENT=		Data Visualization Systems for viewing high-dimensional data

USE_X11=                yes

do-configure:
	cd ${WRKSRC}/src; \
	${XMKMF}

do-build:
	cd ${WRKSRC}/src; \
	make

do-install:
.for PROGRAM in xgobi xgvis
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PROGRAM} ${PREFIX}/bin
.endfor
.for MAN in xgobi.1 xgvis.1
	${INSTALL_DATA} ${WRKSRC}/manpages/${MAN} ${PREFIX}/man/man1
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGNAME}
.for DOC in Changes Readme.install Readme.S Copyright
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${PREFIX}/share/doc/${PKGNAME}
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGNAME}/HELP
.for DOC in *
	${INSTALL_DATA} ${WRKSRC}/help/${DOC} ${PREFIX}/share/doc/${PKGNAME}/HELP
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGNAME}
	${INSTALL_DATA} ${WRKSRC}/XGobi.ex ${PREFIX}/share/examples/${PKGNAME}
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGNAME}/data_xgobi
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGNAME}/data_xgvis
.for EXA in *
	${INSTALL_DATA} ${WRKSRC}/data_xgobi/${EXA} ${PREFIX}/share/examples/${PKGNAME}/data_xgobi
.endfor
.for EXA in *
	${INSTALL_DATA} ${WRKSRC}/data_xgvis/${EXA} ${PREFIX}/share/examples/${PKGNAME}/data_xgvis
.endfor

.include "../../mk/bsd.pkg.mk"

