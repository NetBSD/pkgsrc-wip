# $NetBSD: Makefile,v 1.14 2011/10/26 15:16:44 noud4 Exp $
#

DISTNAME=		xgobi
PKGNAME=		xgobi-20030626
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		http://www.research.att.com/areas/stat/xgobi/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.research.att.com/areas/stat/xgobi/
COMMENT=		Data Visualization Systems for viewing high-dimensional data

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}
CONFIGURE_DIRS=		src
USE_IMAKE=		yes

INSTALLATION_DIRS=	${PKGMANDIR}/man1 bin
INSTALLATION_DIRS+=	share/doc/${PKGNAME_NOREV}/HELP
INSTALLATION_DIRS+=	share/examples/${PKGNAME_NOREV}/data_xgobi
INSTALLATION_DIRS+=	share/examples/${PKGNAME_NOREV}/data_xgvis

do-install:
.for program in xgobi xgvis
	${INSTALL_PROGRAM} ${WRKSRC}/src/${program} ${DESTDIR}${PREFIX}/bin
.endfor
.for man in xgobi.1 xgvis.1
	${INSTALL_DATA} ${WRKSRC}/manpages/${man} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor
.for doc in Changes Readme.install Readme.S Copyright
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}
.endfor
	${INSTALL_DATA} ${WRKSRC}/help/* ${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}/HELP
	${INSTALL_DATA} ${WRKSRC}/XGobi.ex ${DESTDIR}${PREFIX}/share/examples/${PKGNAME_NOREV}
	${INSTALL_DATA} ${WRKSRC}/data_xgobi/* ${DESTDIR}${PREFIX}/share/examples/${PKGNAME_NOREV}/data_xgobi
	${INSTALL_DATA} ${WRKSRC}/data_xgvis/* ${DESTDIR}${PREFIX}/share/examples/${PKGNAME_NOREV}/data_xgvis

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
