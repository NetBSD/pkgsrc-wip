# $NetBSD: Makefile,v 1.2 2012/10/05 08:46:09 asau Exp $
#

DISTNAME=	pdftk-2.02-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	print
MASTER_SITES=	https://www.pdflabs.com/tools/pdftk-the-pdf-toolkit/
EXTRACT_SUFX=	.zip

MAINTAINER=	mwicks@kettering.edu
HOMEPAGE=	https://www.pdflabs.com/tools/pdftk-server/
COMMENT=	Swiss army knife for PDF files
LICENSE=	gnu-gpl-v2

BUILD_DIRS=		pdftk
MAKE_FILE=		Makefile.FreeBSD
WRKSRC=			${WRKDIR}/${DISTNAME:S/-src/-dist/}

USE_TOOLS+=		gmake
USE_LANGUAGES+=		c++

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-patch
SUBST_MESSAGE.fix-paths=	Fixing absolute paths in make file
SUBST_FILES.fix-paths=		pdftk/Makefile.Base
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/pdftk

post-install:
	${INSTALL_MAN}  ${WRKSRC}/debian/pdftk.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA}  ${WRKSRC}/pdftk.1.html ${DESTDIR}${PREFIX}/share/doc/html/pdftk/pdftk.html
	${INSTALL_DATA} ${WRKSRC}/java_libs/com/lowagie/text/pdf/fonts/License-Adobe.txt ${DESTDIR}${PREFIX}/share/doc/pdftk

# XXX figure out why this is needed (something about gcc34)
# (maybe try to use gcc5 instead?)
.include "../../mk/bsd.prefs.mk"

pre-configure:
.include "../../lang/gcc34/preconfigure.mk"

.include "../../lang/gcc34/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
