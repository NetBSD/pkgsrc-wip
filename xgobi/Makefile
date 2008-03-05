# $NetBSD: Makefile,v 1.8 2008/03/05 19:46:42 asau Exp $
#

DISTNAME=		xgobi
PKGNAME=		xgobi-20030626
CATEGORIES=		graphics
MASTER_SITES=		http://www.research.att.com/areas/stat/xgobi/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.research.att.com/areas/stat/xgobi/
COMMENT=		Data Visualization Systems for viewing high-dimensional data

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_IMAKE=		yes

do-configure:
	cd ${WRKSRC}/src; \
	${XMKMF}

do-build:
	cd ${WRKSRC}/src; \
	make

do-install:
.for PROGRAM in xgobi xgvis
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PROGRAM} ${DESTDIR}${PREFIX}/bin
.endfor
.for MAN in xgobi.1 xgvis.1
	${INSTALL_DATA} ${WRKSRC}/manpages/${MAN} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}
.for DOC in Changes Readme.install Readme.S Copyright
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/HELP
.for DOC in *
	${INSTALL_DATA} ${WRKSRC}/help/${DOC} ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/HELP
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/${PKGNAME}
	${INSTALL_DATA} ${WRKSRC}/XGobi.ex ${DESTDIR}${PREFIX}/share/examples/${PKGNAME}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/${PKGNAME}/data_xgobi
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/${PKGNAME}/data_xgvis
.for EXA in *
	${INSTALL_DATA} ${WRKSRC}/data_xgobi/${EXA} ${DESTDIR}${PREFIX}/share/examples/${PKGNAME}/data_xgobi
.endfor
.for EXA in *
	${INSTALL_DATA} ${WRKSRC}/data_xgvis/${EXA} ${DESTDIR}${PREFIX}/share/examples/${PKGNAME}/data_xgvis
.endfor

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
