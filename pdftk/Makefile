# $NetBSD: Makefile,v 1.2 2012/10/05 08:46:09 asau Exp $
#

DISTNAME=		pdftk-1.41
CATEGORIES=		print
MASTER_SITES=		http://www.pdfhacks.com/pdftk/

MAINTAINER=		mwicks@kettering.edu
HOMEPAGE=		http://www.pdfhacks.com/pdftk/
COMMENT=		Swiss army knife for PDF files

PKG_DESTDIR_SUPPORT=	none

BUILD_DIRS=		pdftk
MAKE_FILE=		Makefile.Generic

USE_TOOLS+=		gmake
USE_LANGUAGES+=		c++

SUBST_CLASSES+=		   fix-paths
SUBST_STAGE.fix-paths=	   post-patch
SUBST_MESSAGE.fix-paths=   Fixing absolute paths in make file
SUBST_FILES.fix-paths=	   pdftk/Makefile.Base
SUBST_SED.fix-paths=	   -e 's,/usr/local,${LOCALBASE},g'

post-install:
	${INSTALL_MAN}  ${WRKSRC}/debian/pdftk.1 ${LOCALBASE}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/doc/html/pdftk
	${INSTALL_DATA}  ${WRKSRC}/pdftk.1.html ${LOCALBASE}/share/doc/html/pdftk/pdftk.html
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/doc/pdftk
	${INSTALL_DATA} ${WRKSRC}/java_libs/com/lowagie/text/pdf/fonts/License-Adobe.txt ${LOCALBASE}/share/doc/pdftk
	${INSTALL_DATA} files/COPYING ${LOCALBASE}/share/doc/pdftk

pre-configure:
.include "../../lang/gcc34/preconfigure.mk"

.include "../../lang/gcc34/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
