# $NetBSD: Makefile,v 1.11 2008/03/05 20:18:08 asau Exp $
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
CONFIGURE_DIRS=		src
USE_IMAKE=		yes

INSTALLATION_DIRS=	${PKGMANDIR} ${PKGMANDIR}/man1 bin

do-install:
.for program in xgobi xgvis
	${INSTALL_PROGRAM} ${WRKSRC}/src/${program} ${DESTDIR}${PREFIX}/bin
.endfor
.for man in xgobi.1 xgvis.1
	${INSTALL_DATA} ${WRKSRC}/manpages/${man} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}
.for doc in Changes Readme.install Readme.S Copyright
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/HELP
.for doc in *
	${INSTALL_DATA} ${WRKSRC}/help/${doc} ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/HELP
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/${PKGNAME}
	${INSTALL_DATA} ${WRKSRC}/XGobi.ex ${DESTDIR}${PREFIX}/share/examples/${PKGNAME}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/${PKGNAME}/data_xgobi
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/${PKGNAME}/data_xgvis
.for exa in *
	${INSTALL_DATA} ${WRKSRC}/data_xgobi/${exa} ${DESTDIR}${PREFIX}/share/examples/${PKGNAME}/data_xgobi
.endfor
.for exa in *
	${INSTALL_DATA} ${WRKSRC}/data_xgvis/${exa} ${DESTDIR}${PREFIX}/share/examples/${PKGNAME}/data_xgvis
.endfor

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
