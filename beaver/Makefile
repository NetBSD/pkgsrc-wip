# $NetBSD: Makefile,v 1.1.1.1 2003/04/15 22:17:39 bmeurer Exp $

DISTNAME=	beaver-0.2.6
CATEGORIES=	editors
MASTER_SITES=	http://savannah.nongnu.org/download/beaver/

MAINTAINER=	vincent.derrien@ahoup.net
HOMEPAGE=	http://www.beaver-project.org/
COMMENT=	Lightweight Gtk text editor with syntax highlighting

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_X11=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/beaver \
		${PREFIX}/bin/beaver
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/beaver.1x \
		${PREFIX}/man/man1/beaver.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/beaver
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/pixmaps/beaver.png \
		${PREFIX}/share/beaver/beaver.png
	${INSTALL_DATA_DIR} ${PREFIX}/share/beaver/bl
	cd ${WRKDIR}/${DISTNAME} && \
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/bl/* \
		${PREFIX}/share/beaver/bl

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
